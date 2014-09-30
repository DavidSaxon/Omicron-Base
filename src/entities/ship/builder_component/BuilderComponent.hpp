#ifndef VOIDWALKER_SHIP_BUILDERCOMPONENT_HPP_
#   define VOIDWALKER_SHIP_BUILDERCOMPONENT_HPP_

#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/utilities/TransformUtil.hpp"

class BuilderComponent {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new builder component
    @param renderables a list of the renderable components of the block */
    BuilderComponent(
                  omi::Transform*                transform,
            const std::vector<omi::Renderable*>& renderables );

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~BuilderComponent();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Updates the builder component */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the transform of the block
    omi::Transform* m_transform;
    // the list of renderables used by the block
    std::vector<omi::Renderable*> m_renerables;

    // is true while the left mouse button is down
    bool m_mouseDown;
    // is true if the block is selected
    bool m_selected;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Decides whether the block is selected or not */
    void selection();

    /** Moves the block when it's selected */
    void move();
};

#endif
