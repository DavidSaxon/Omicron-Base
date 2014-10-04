#ifndef VOIDWALKER_SHIP_DRAWCOMPONENT_HPP_
#   define VOIDWALKER_SHIP_DRAWCOMPONENT_HPP_

#include <vector>

#include "src/omicron/entity/Entity.hpp"

/**********************************************************************\
| Abstract base class that defines how a block is drawn by providing a |
| renderable.                                                          |
\**********************************************************************/
class DrawComponent {
public:

    /** Initialises the component
    @param transform the transform to use for the renderables */
    virtual void init( omi::Transform* transform ) = 0;

    /** updates the draw component */
    virtual void update()
    {
        // do nothing
    }

    /** @return the list of renderable components to use for the block */
    const std::vector<omi::Renderable*>& getRenderables()
    {
        return m_renderables;
    }

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the list of renderables in this draw component
    std::vector<omi::Renderable*> m_renderables;
};

#endif
