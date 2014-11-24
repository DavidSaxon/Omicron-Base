#include "RenderLists.hpp"

namespace omi {

namespace {

// the maximum number of point lights
static const unsigned MAX_LIGHTS = 8;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RenderLists::RenderLists()
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RenderLists::render( Camera* camera )
{
    //------------------------------LAYER SORTING-------------------------------

    // iterate over all renderables and group them into a map by layer
    t_RenderableMap renderLayers;
    for ( std::vector<Renderable*>::iterator renderable = m_renderables.begin();
          renderable != m_renderables.end(); ++ renderable )
    {
        // get the layer
        int layer = ( *renderable )->getLayer();
        //check if a list exists for this layer
        if ( renderLayers.find( layer ) == renderLayers.end() )
        {
            // create a list for this layer
            renderLayers.insert(
                std::make_pair( layer, std::vector<Renderable*>() ) );
        }
        // add the renderable to the layer
        renderLayers[layer].push_back( *renderable );
    }

    //------------------------------SELECTION PASS------------------------------

    // apply the camera
    if ( camera != NULL )
    {
        camera->apply();
    }
    // the colour values to render with
    unsigned char red   = 0;
    unsigned char green = 0;
    unsigned char blue  = 0;
    // a mapping from colour to renderables
    std::map<std::string, Renderable*> colourMap;
    // render selectable renderables
    for ( t_RenderableMap::iterator it = renderLayers.begin();
          it != renderLayers.end(); ++it )
    {
        // iterate over the renderables in this layer and render them
        for ( std::vector<Renderable*>::iterator itr = it->second.begin();
              itr != it->second.end(); ++itr)
        {
            if ( (* itr )->selectable )
            {
                // increment selection colour
                ++red;
                if ( red == 255 )
                {
                    red = 0;
                    ++green;
                    if ( green == 255 )
                    {
                        green = 0;
                        ++blue;
                        // TODO: if blue is 255 flip shit
                    }
                }

                // assign to map and render
                std::stringstream ss;
                ss << static_cast<unsigned>( red )   << ":";
                ss << static_cast<unsigned>( green ) << ":";
                ss << static_cast<unsigned>( blue );
                colourMap.insert( std::make_pair( ss.str(), *itr ) );
                ( *itr )->renderSelectable(
                    camera, red, green, blue );
            }
        }
    }

    // get colour of the pixel the mouse is at
    GLint viewport[4];
    GLubyte pixel[3];
    glGetIntegerv( GL_VIEWPORT, viewport );
    glm::vec2 mousePos = input::getMousePos() - displaySettings.getPos();
    if ( !displaySettings.getFullscreen() )
    {
        mousePos.y += 30;
    }
    glReadPixels( static_cast<GLint>( mousePos.x ),
                  viewport[3] - static_cast<GLint>( mousePos.y ),
                  1, 1, GL_RGB, GL_UNSIGNED_BYTE, ( void* ) pixel);

    // clear the select state of the renderables
    for ( std::map<std::string, Renderable*>::iterator it = colourMap.begin();
          it != colourMap.end(); ++it )
    {
        it->second->selected = false;
    }
    // if a renderable has been selected set it's state
    std::stringstream ss;
    ss << static_cast<unsigned>( pixel[0] )   << ":";
    ss << static_cast<unsigned>( pixel[1] )   << ":";
    ss << static_cast<unsigned>( pixel[2] );
    if ( colourMap.find( ss.str() ) != colourMap.end() )
    {
        colourMap[ss.str()]->selected = true;
    }

    // clear for normal rendering
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //------------------------------VISIBLE PASSES------------------------------

    // calculate light data
    LightData lightData;
    // apply the camera
    if ( camera != NULL )
    {
        camera->apply();
        // build lighting data
        buildLightData( camera, lightData );
    }

    //--------------------------------GLOW PASS---------------------------------

    // // bind the first pass glow render texture
    m_glowFirstPassRenTex.bind();

    // iterate over the layers
    for ( t_RenderableMap::iterator it = renderLayers.begin();
          it != renderLayers.end(); ++it )
    {
        // iterate over the renderables in this layer and render them or glow
        for ( std::vector<Renderable*>::iterator itr = it->second.begin();
              itr != it->second.end(); ++itr)
        {
            ( *itr )->renderGlow( camera );
        }
    }

    // unbind the first pass glow render texture
    m_glowFirstPassRenTex.unbind();

    // blur the glow render onto the collate texture
    m_glowBlurHorRenTex.bind();
    m_glowFirstPassRenTex.render();
    m_glowBlurHorRenTex.unbind();

    m_glowBlurVertRenTex.bind();
    m_glowBlurHorRenTex.render();
    m_glowBlurVertRenTex.unbind();

    m_glowCollateRenTex.bind();
    m_glowBlurVertRenTex.render();
    m_glowCollateRenTex.unbind();

    //-----------------------------MAIN RENDER PASS-----------------------------

    // bind final pass render texture
    m_finalRenTex.bind();

    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // iterate over the layers
    for ( t_RenderableMap::iterator it = renderLayers.begin();
          it != renderLayers.end(); ++it )
    {
        // iterate over the renderables in this layer and render them
        for ( std::vector<Renderable*>::iterator itr = it->second.begin();
              itr != it->second.end(); ++itr)
        {
            ( *itr )->render( camera, lightData );
        }
    }

    // used additive blending for glow
    glBlendFunc( GL_ONE, GL_ONE );
    // render glow
    m_glowCollateRenTex.render();
    // revert normal blending mode
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // unbind final pass
    m_finalRenTex.unbind();
    // render the results of the render texture
    m_finalRenTex.render();

    //-----------------------------------GUI------------------------------------

    // TODO:
}

void RenderLists::clear()
{
    m_renderables.clear();
}

void RenderLists::addRenderable( Renderable* renderable )
{
    m_renderables.push_back( renderable );
}

void RenderLists::removeRenderable( Renderable* renderable )
{
    for ( std::vector<Renderable*>::iterator it = m_renderables.begin();
          it != m_renderables.end(); )
    {
        if ( *it == renderable )
        {
            it = m_renderables.erase( it );
            return;
        }
        ++it;
    }
}

void RenderLists::addLight( Light* light )
{
    // don't add the light if over the max light limit
    if ( m_lights.size() >= MAX_LIGHTS )
    {
        // TODO: some sort of warning if in designer mode
        // don't add the light
        return;
    }

    // add to the list of lights
    m_lights.push_back( light );
}

void RenderLists::removeLight( Light* light )
{
    for ( std::vector<Light*>::iterator it = m_lights.begin();
          it != m_lights.end(); )
    {
        if ( *it == light )
        {
            it = m_lights.erase( it );
            return;
        }
        ++it;
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RenderLists::buildLightData( Camera* camera, LightData& lightData )
{
    for ( std::vector<Light*>::iterator it = m_lights.begin();
          it != m_lights.end(); ++it )
    {
        Light* light = *it;
        glm::vec3 pos( light->getTransform()->translation );
        // calculate rotation
        glm::mat4 rotMat = glm::mat4( 1.0f );
        rotMat *= glm::rotate(
            light->getTransform()->rotation.z * util::math::DEGREES_TO_RADIANS,
            glm::vec3( 0.0f, 0.0f, 1.0f )
        );
        rotMat *= glm::rotate(
            light->getTransform()->rotation.y * util::math::DEGREES_TO_RADIANS,
            glm::vec3( 0.0f, 1.0f, 0.0f )
        );
        rotMat *= glm::rotate(
            light->getTransform()->rotation.x * util::math::DEGREES_TO_RADIANS,
            glm::vec3( 1.0f, 0.0f, 0.0f )
        );
        glm::vec3 rot( 0.0f, 0.0f, -1.0f );
        rot = glm::vec3( rotMat * glm::vec4( rot, 0.0f ) );
        // add generic data
        lightData.types.push_back(
            static_cast<int>( light->getLightType() ) );
        lightData.colours.push_back( light->getValue().r );
        lightData.colours.push_back( light->getValue().g );
        lightData.colours.push_back( light->getValue().b );

        // light type specific data
        switch ( light->getLightType() )
        {
            case light::DIRECTIONAL:
            {
                pos = glm::vec3(
                        camera->getViewMatrix() * glm::vec4( pos, 0.0f ) );
                rot = glm::vec3(
                        camera->getViewMatrix()* glm::vec4( rot, 0.0f ) );
                lightData.attenuations.push_back( 1.0f );
                lightData.attenuations.push_back( 0.0f );
                lightData.attenuations.push_back( 0.0f );
                lightData.arcs.push_back( 0.0f );
                lightData.arcs.push_back( 0.0f );
                break;
            }
            case light::POINT:
            {
                PointLight* point = dynamic_cast<PointLight*>( light );
                pos = glm::vec3(
                        camera->getViewMatrix() * glm::vec4( pos, 1.0f ) );
                rot = glm::vec3(
                        camera->getViewMatrix() * glm::vec4( rot, 1.0f ) );
                lightData.attenuations.push_back( point->getConstantAtt() );
                lightData.attenuations.push_back( point->getLinearAtt() );
                lightData.attenuations.push_back( point->getQuadraticAtt() );
                lightData.arcs.push_back( 0.0f );
                lightData.arcs.push_back( 0.0f );
                break;
            }
            case light::SPOT:
            {
                SpotLight* spot = dynamic_cast<SpotLight*>( light );
                pos = glm::vec3(
                        camera->getViewMatrix() * glm::vec4( pos, 1.0f ) );
                rot = glm::vec3(
                        camera->getViewMatrix() * glm::vec4( rot, 0.0f ) );
                lightData.attenuations.push_back( spot->getConstantAtt() );
                lightData.attenuations.push_back( spot->getLinearAtt() );
                lightData.attenuations.push_back( spot->getQuadraticAtt() );
                lightData.arcs.push_back(
                        util::math::cosd( spot->getOuterArc() ) );
                lightData.arcs.push_back(
                        util::math::cosd( spot->getInnerArc() ) );
                break;
            }
        }

        // positions
        lightData.positions.push_back( pos.x );
        lightData.positions.push_back( pos.y );
        lightData.positions.push_back( pos.z );
        // rotations
        lightData.rotations.push_back( rot.x );
        lightData.rotations.push_back( rot.y );
        lightData.rotations.push_back( rot.z );
    }
}

} // namespace omi
