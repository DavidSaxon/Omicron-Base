#ifndef VOIDWALKER_SHIP_DRAW_COMPONENT_SPRITEDRAWCOMP_H_
#   define VOIDWALKER_SHIP_DRAW_COMPONENT_SPRITEDRAWCOMP_H_

#include "DrawComponent.hpp"

class SpriteDrawComp : public DrawComponent {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new sprite draw component
    @param renderableName the name of the renderable to use for the component */
    SpriteDrawComp( const std::string& renderableName );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init( omi::Transform* transform );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the name of the renderable to use
    std::string m_renderableName;
};

#endif
