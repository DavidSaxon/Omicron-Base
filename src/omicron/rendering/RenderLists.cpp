#include "RenderLists.hpp"

namespace omi {

namespace {

// the maximum number of point lights
static const unsigned MAX_LIGHTS = 8;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RenderLists::RenderLists() :
    m_visCheckThread( new boost::thread( vis_check::sortVisible ) )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RenderLists::render( Camera* camera )
{
    //----------------------------RENDERABLES UPDATE----------------------------

    // iterate over all renderables and update them
    for ( std::vector<Renderable*>::iterator renderable = m_renderables.begin();
          renderable != m_renderables.end(); ++ renderable )
    {
        ( *renderable )->update();
    }

    //------------------------------LAYER SORTING-------------------------------

    // iterate over all renderables and group them into a map by layer and
    // separate gui renderables
    t_RenderableMap renderLayers;
    t_RenderableMap guiLayers;
    for ( std::vector<Renderable*>::iterator renderable = m_renderables.begin();
          renderable != m_renderables.end(); ++ renderable )
    {
        // decide which list to add this to
        t_RenderableMap* currentList = &renderLayers;
        if ( ( *renderable )->gui )
        {
            currentList = &guiLayers;
        }

        // get the layer
        int layer = ( *renderable )->getLayer();
        //check if a list exists for this layer
        if ( currentList->find( layer ) == currentList->end() )
        {
            // create a list for this layer
            currentList->insert(
                std::make_pair( layer, std::vector<Renderable*>() ) );
        }
        // add the renderable to the layer
        ( *currentList )[layer].push_back( *renderable );
    }

    //------------------------------SELECTION PASS------------------------------

    // create a camera for rendering gui
    Camera guiCamera( "", omi::cam::ORTHOGRAPHIC, NULL );
    guiCamera.apply();

    // apply the camera
    if ( camera != NULL )
    {
        camera->apply();
    }

    if ( renderSettings.getColourPicking() )
    {
        // the colour values to render with
        unsigned char red   = 0;
        unsigned char green = 0;
        unsigned char blue  = 0;
        // a mapping from colour to renderables
        std::map<unsigned, Renderable*> colourMap;
        // render selectable renderables
        for ( t_RenderableMap::iterator it = renderLayers.begin();
              it != renderLayers.end(); ++it )
        {
            for ( std::vector<Renderable*>::iterator itr = it->second.begin();
                  itr != it->second.end(); ++itr)
            {
                renderSelectable( *itr, camera, colourMap, red, green, blue );
            }
        }
        for ( t_RenderableMap::iterator it = guiLayers.begin();
              it != guiLayers.end(); ++it )
        {
            for ( std::vector<Renderable*>::iterator itr = it->second.begin();
                  itr != it->second.end(); ++itr)
            {
                renderSelectable(
                        *itr,
                        &guiCamera,
                        colourMap,
                        red,
                        green,
                        blue
                );
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
        for ( std::map<unsigned, Renderable*>::iterator it = colourMap.begin();
              it != colourMap.end(); ++it )
        {
            it->second->selected = false;
        }

        // build the colour key
        unsigned colour = static_cast<unsigned>( pixel[ 0 ] );
        colour |= static_cast<unsigned>( pixel[ 1 ] ) << 8;
        colour |= static_cast<unsigned>( pixel[ 2 ] ) << 16;
        // if a renderable has been selected set it's state
        if ( colourMap.find( colour ) != colourMap.end() )
        {
            colourMap[ colour ]->selected = true;
        }

        // clear for normal rendering
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    //-------------------------CAMERA AND LIGHT SET UP--------------------------

    // find the first light that has shadow casting on (only have support for
    // one shadow light right now )
    bool shadowing = false;
    Light* shadowCaster = NULL;
    if ( renderSettings.getShadows() )
    {
        for ( std::vector<Light*>::iterator it = m_lights.begin();
              it != m_lights.end(); ++it )
        {
            if ( (*it)->getCastShadows() )
            {
                shadowing = true;
                shadowCaster = *it;
                break;
            }
        }
    }

    // calculate light data
    LightData lightData;
    // apply the camera
    if ( camera != NULL )
    {
        camera->apply();
        // build lighting data
        buildLightData( camera, shadowCaster, lightData );
    }

    //-----------------------------VISIBILITY PASS------------------------------

    if ( renderSettings.getVisibilityChecking() && vis_check::ready )
    {
        std::cout << "VIS CHECK" << std::endl;

        util::time::sleep( 500 );

        // bind the visibility check render texture
        m_visCheckRenTex.bind();

        // TODO: MOVE BACK TO ZEROS
        // the colour values to render with
        unsigned char red   = 125;
        unsigned char green = 125;
        unsigned char blue  = 125;
        // a mapping from colour to renderables
        m_visColourMap.clear();
        // render selectable renderables
        for ( t_RenderableMap::iterator it = renderLayers.begin();
              it != renderLayers.end(); ++it )
        {
            for ( std::vector<Renderable*>::iterator itr = it->second.begin();
                  itr != it->second.end(); ++itr)
            {
                renderVisibilty( *itr, camera, m_visColourMap, red, green, blue );
                // set the visibility to false
                ( *itr )->setVisCam( false );
            }
        }

        m_visCheckRenTex.unbind();

        // check the size of the buffer we're creating pixels in
        unsigned bufferSize = static_cast<unsigned>(
                3 *
                m_visCheckRenTex.getResolution().x *
                m_visCheckRenTex.getResolution().y
        );

        if ( m_visCheckBuffer.size() < bufferSize )
        {
            m_visCheckBuffer.resize( bufferSize );
        }

        // get the texture pixels
        glBindTexture( GL_TEXTURE_2D, m_visCheckRenTex.getTextureId() );
        glGetTexImage(
                GL_TEXTURE_2D,
                0,
                GL_RGB,
                GL_UNSIGNED_BYTE,
                ( GLvoid* ) &m_visCheckBuffer[ 0 ]
        );

        // check the pixel buffer off in another thread
        vis_check::buffer = &m_visCheckBuffer;
        vis_check::sort = true;

        // clear for normal rendering
        glBindTexture( GL_TEXTURE_2D, 0 );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    //-------------------------------SHADOW PASS--------------------------------

    Camera* shadowCamera = NULL;
    if ( shadowing && camera != NULL )
    {
        // create a camera to use for shadowing
        shadowCamera = new Camera(
            "",
            omi::cam::SHADOW,
            shadowCaster->getTransform()
        );
        Transform* offset = new Transform(
                "",
                glm::vec3( 30.0f, 3.0f, 3.0f ),
                glm::vec3( 0.0f, 0.0f, 0.0f ),
                glm::vec3( 1.0f, 1.0f, 1.0f )
        );
        shadowCamera->setShadowOffset( camera->getTransform() );
        shadowCamera->apply();

        // TODO: uncomment
        // render all faces
        glDisable( GL_CULL_FACE );

        // render
        m_shadowMap.bind();
        for ( t_RenderableMap::iterator it = renderLayers.begin();
              it != renderLayers.end(); ++it )
        {
            // iterate over the renderables in this layer and render them
            for ( std::vector<Renderable*>::iterator itr = it->second.begin();
                  itr != it->second.end(); ++itr)
            {
                ( *itr )->renderShadow( shadowCamera );
            }
        }
        m_shadowMap.unbind();

        // turn back on back-face culling
        if ( renderSettings.getBackFaceCulling() )
        {
            glEnable( GL_CULL_FACE );
        }

    }

    //------------------------------VISIBLE PASSES------------------------------

    //--------------------------------GLOW PASS---------------------------------

    // bind the first pass glow render texture
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
    // TODO: GUI glow?

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

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // iterate over the layers
    for ( t_RenderableMap::iterator it = renderLayers.begin();
          it != renderLayers.end(); ++it )
    {
        // iterate over the renderables in this layer and render them
        for ( std::vector<Renderable*>::iterator itr = it->second.begin();
              itr != it->second.end(); ++itr)
        {
            ( *itr )->render( camera, shadowCamera, lightData );
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

    // disable depth testing
    glDisable( GL_DEPTH_TEST );

    for ( t_RenderableMap::iterator it = guiLayers.begin();
          it != guiLayers.end(); ++it )
    {
        // iterate over the renderables in this layer and render them
        for ( std::vector<Renderable*>::iterator itr = it->second.begin();
              itr != it->second.end(); ++itr)
        {
            ( *itr )->render( &guiCamera, shadowCamera, lightData );
        }
    }

    // revert depth testing
    if ( renderSettings.getDepthTest() )
    {
        glEnable( GL_DEPTH_TEST );
    }

    //---------------------------VISIBLE THREAD JOIN----------------------------

    // check if the visibility thread is done
    if ( !renderSettings.getVisibilityChecking() || !vis_check::ready )
    {
        return;
    }

    std::cout << "JOIN" << std::endl;

    // go over each colour and tell the renderable that's visible
    for ( std::set<unsigned>::iterator it = vis_check::visibleSet.begin();
          it != vis_check::visibleSet.end(); ++it )
    {
        if ( m_visColourMap.find( *it ) != m_visColourMap.end() )
        {
            // tell the renderable that it is visible
            m_visColourMap[ *it ]->setVisCam( true );
        }
    }

    // vis_check::buffer = NULL;
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

void RenderLists::renderSelectable(
        Renderable* renderable,
        Camera* camera,
        std::map<unsigned, Renderable*>& colourMap,
        unsigned char& red,
        unsigned char& green,
        unsigned char& blue )
{
    // check if this is a selectable
    if ( renderable->selectable )
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

        // create the id for the colour
        unsigned colour = static_cast<unsigned>( red );
        colour         |= static_cast<unsigned>( green ) << 8;
        colour         |= static_cast<unsigned>( blue ) << 16;

        colourMap.insert( std::make_pair( colour, renderable ) );
        renderable->renderSelectable( camera, red, green, blue );
    }
}

void RenderLists::renderVisibilty(
        Renderable* renderable,
        Camera* camera,
        std::map<unsigned, Renderable*>& colourMap,
        unsigned char& red,
        unsigned char& green,
        unsigned char& blue )
{
    // increment visibility colour
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

    // create the id for the colour
    unsigned colour = static_cast<unsigned>( red );
    colour         |= static_cast<unsigned>( green ) << 8;
    colour         |= static_cast<unsigned>( blue ) << 16;

    colourMap.insert( std::make_pair( colour, renderable ) );
    renderable->renderVisCheck( camera, red, green, blue );
}

void RenderLists::buildLightData(
        Camera* camera,
        Light* shadowCaster,
        LightData& lightData )
{
    unsigned i = 0;
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
        lightData.names.push_back( light->getId() );
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

        // inverse
        lightData.inverses.push_back( light->isInversed() );

        // shadow map
        lightData.shadowMap = m_shadowMap.getTexture();
        // shadow caster
        if ( *it == shadowCaster )
        {
            lightData.shadowCaster = i;
        }

        ++i;
    }
}

} // namespace omi
