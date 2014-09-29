#include "RenderLists.hpp"

namespace omi {

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
    for ( t_RenderableMap::iterator it = m_renderables.begin();
          it != m_renderables.end(); ++it )
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

    // apply the camera
    if ( camera != NULL )
    {
        camera->apply();
    }

    // iterate over the layers
    for ( t_RenderableMap::iterator it = m_renderables.begin();
          it != m_renderables.end(); ++it )
    {
        //sort the list of renderables based on their distance from the camera
        depthSorter.camera = camera;
        // TODO: sorting should only happen on transparent/requested renderables
        // std::sort( it->second.begin(), it->second.end(), depthSorter );

        // iterate over the renderables in this layer and render them
        for ( std::vector<Renderable*>::iterator itr = it->second.begin();
              itr != it->second.end(); ++itr)
        {
            ( *itr )->render( camera );
        }
    }
}

void RenderLists::clear()
{
    m_renderables.clear();
}

void RenderLists::addRenderable( Renderable* renderable )
{
    // get the layer from the component
    int layer = renderable->getLayer();

    // check if a list exists for the given layer
    if ( m_renderables.find( layer ) == m_renderables.end() )
    {
        // create a list for this layer
        m_renderables.insert(
            std::make_pair( layer, std::vector<Renderable*>() ) );
    }

    // add the renderable to the layer
    m_renderables[layer].push_back( renderable );
}

void RenderLists::removeRenderable( Renderable* renderable )
{
    // get the layer from the component
    int layer = renderable->getLayer();

    // check that the layer exists
    if ( m_renderables.find( layer ) == m_renderables.end() )
    {
        // TODO: throw an exception
        std::cout << "remove renderable from non-existent layer" << std::endl;
    }

    // search the layer for the renderable
    for ( std::vector<Renderable*>::iterator it = m_renderables[layer].begin();
          it != m_renderables[layer].end(); )
    {
        if ( *it == renderable )
        {
            it = m_renderables[layer].erase( it );
        }
        else
        {
            ++it;
        }
    }
}

} // namespace omi
