#include "RenderLists.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RenderLists::RenderLists() {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

RenderLists::~RenderLists() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RenderLists::render(Camera* camera) {

    // apply the camera
    if (camera != NULL) {

        camera->apply();
    }

    // iterate over the layers
    for (t_RenderableMap::iterator it = m_renderables.begin();
        it != m_renderables.end(); ++it) {

        // iterate over the renderables in this layer and render them
        for (std::set<Renderable*>::iterator itr = it->second.begin();
            itr != it->second.end(); ++itr) {

            (*itr)->render();
        }
    }
}

void RenderLists::clear() {

    m_renderables.clear();
}

void RenderLists::addRenderable(Renderable* renderable) {

    // get the layer from the component
    int layer = renderable->getLayer();

    // check if a set exists for the given layer
    if (m_renderables.find(layer) == m_renderables.end()) {

        // create a set for this layer
        m_renderables.insert(std::make_pair(layer, std::set<Renderable*>()));
    }

    // add the renderable to the layer
    m_renderables[layer].insert(renderable);
}

void RenderLists::removeRenderable(Renderable* renderable) {

    // get the layer from the component
    int layer = renderable->getLayer();

    // check that the layer exists
    if (m_renderables.find(layer) == m_renderables.end()) {

        // TODO: throw an exception
        std::cout << "remove renderable from non-existent layer" << std::endl;
    }

    // search the layer for the renderable
    for (std::set<Renderable*>::iterator it = m_renderables[layer].begin();
         it != m_renderables[layer].end();) {

        if (*it == renderable) {

            it = m_renderables[layer].erase(it);
        }
        else {

            ++it;
        }
    }
}

} // namespace omi