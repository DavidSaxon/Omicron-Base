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

    /** Sets the visibility of the top connection arrow */
    static void setTopVisibility( bool visible );

    /** Sets the visibility of the top connection arrow */
    static void setBottomVisibility( bool visible );

    /** Sets the visibility of the top connection arrow */
    static void setLeftVisibility( bool visible );

    /** Sets the visibility of the top connection arrow */
    static void setRightVisibility( bool visible );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the transform
    static omi::Transform* m_transform;
    // the sprite of the selector
    static omi::Sprite* m_selectSprite;
    // the sprites for the connection arrows
    static omi::Sprite* m_topConnectionArrow;
    static omi::Sprite* m_bottomConnectionArrow;
    static omi::Sprite* m_leftConnectionArrow;
    static omi::Sprite* m_rightConnectionArrow;
};

#endif
