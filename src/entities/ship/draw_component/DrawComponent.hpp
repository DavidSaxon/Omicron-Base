#ifndef VOIDWALKER_SHIP_DRAWCOMPONENT_HPP_
#   define VOIDWALKER_SHIP_DRAWCOMPONENT_HPP_

#include "src/omicron/entity/Entity.hpp"

/**********************************************************************\
| Abstract base class that defines how a block is drawn by providing a |
| renderable.                                                          |
\**********************************************************************/
class DrawComponent {
public:

    /** @return the renderable component to use for the block
    @param transform the transform to use for the renderable */
    virtual omi::Component* getComponent( omi::Transform* transform ) = 0;
};

#endif
