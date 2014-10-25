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

    //---------------------------SELECTABLE ELEMENTS----------------------------

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

    //-----------------------------VISIBLE ELEMENTS-----------------------------


    LightData lightData;

    // apply the camera
    if ( camera != NULL )
    {
        camera->apply();
        // build lighting data
        buildLightData( camera, lightData );
    }

    // iterate over the layers
    for ( t_RenderableMap::iterator it = renderLayers.begin();
          it != renderLayers.end(); ++it )
    {
        //sort the list of renderables based on their distance from the camera
        depthSorter.camera = camera;
        // TODO: sorting should only happen on transparent/requested renderables
        // std::sort( it->second.begin(), it->second.end(), depthSorter );

        // iterate over the renderables in this layer and render them
        for ( std::vector<Renderable*>::iterator itr = it->second.begin();
              itr != it->second.end(); ++itr)
        {
            ( *itr )->render( camera, lightData );
        }
    }
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
                lightData.attenuations.push_back( 0.0f );
                lightData.attenuations.push_back( 0.0f );
                lightData.attenuations.push_back( 0.0f );
                break;
            }
            case light::POINT:
            {
                PointLight* point = dynamic_cast<PointLight*>( light );
                pos = glm::vec3(
                        camera->getViewMatrix() * glm::vec4( pos, 1.0f ) );
                lightData.attenuations.push_back( point->getConstantAtt() );
                lightData.attenuations.push_back( point->getLinearAtt() );
                lightData.attenuations.push_back( point->getQuadraticAtt() );
                break;
            }
            case light::SPOT:
            {
                // TODO:
                break;
            }
        }

        // positions
        lightData.positions.push_back( pos.x );
        lightData.positions.push_back( pos.y );
        lightData.positions.push_back( pos.z );
    }
}

} // namespace omi
