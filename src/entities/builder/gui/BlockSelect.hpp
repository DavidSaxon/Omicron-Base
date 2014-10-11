#ifndef VOIDWALKER_BUILDER_GUI_BLOCKSELECT_HPP_
#   define VOIDWALKER_BUILDER_GUI_BLOCKSELECT_HPP_

#include "src/omicron/entity/Entity.hpp"

class BlockSelect : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    /** Sets the visibility of the block select */
    static void setVisibility( bool visible );

    /** Sets the position of the block select */
    static void setPosition( const glm::vec3& pos );

    /** Sets the colour of the selector to be the valid colour */
    static void setValidColour();

    /** Sets the colour of the selector to be the invalid colour */
    static void setInvalidColour();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the transform
    static omi::Transform* m_transform;
    // the sprite
    static omi::Sprite* m_sprite;

};

#endif
