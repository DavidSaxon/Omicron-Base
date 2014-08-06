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

void RenderLists::addRenderable(Renderable* renderable, int layer) {

    // check if a set exists for the given layer
    if (m_renderables.find(layer) == m_renderables.end()) {

        // create a set for this layer
        m_renderables.insert(std::make_pair(layer, std::set<Renderable*>()));
    }

    // add the renderable to the layer
    m_renderables[layer].insert(renderable);
}

void RenderLists::removeRenderable(Renderable* renderable) {
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RenderLists::render() {
}


} // namespace omi