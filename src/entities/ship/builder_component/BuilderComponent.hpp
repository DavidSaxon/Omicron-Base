#ifndef VOIDWALKER_SHIP_BUILDERCOMPONENT_HPP_
#   define VOIDWALKER_SHIP_BUILDERCOMPONENT_HPP_

#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/utilities/TransformUtil.hpp"
#include "src/omicron/utilities/VectorUtil.hpp"
#include "src/override/Values.hpp"

class BuilderGrid;
#include "src/scenes/builder/grid/BuilderGrid.hpp"

#include "src/entities/builder/gui/BlockSelect.hpp"
#include "src/entities/ship/connection_component/ConnectionComponent.hpp"

class BuilderComponent {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new builder component
    @param grid the builder grid to build on */
    BuilderComponent( BuilderGrid* grid );

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~BuilderComponent();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Initialises the builder component
    @param owner the owner of this component */
    void init(
              omi::Entity*                   owner,
              omi::Transform*                transform,
              ConnectionComponent*           connection,
        const std::vector<omi::Renderable*>& renderables );

    /** Updates the builder component */
    void update();

    /** @return the collision detector of this component */
    omi::CollisionDetector* getCollisionDetector();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the block that this component is part of
    Block* m_owner;
    // the grid to build on
    BuilderGrid* m_grid;

    // the transform of the block
    omi::Transform* m_transform;
    // the connection component of the block
    ConnectionComponent* m_connection;
    // the list of renderables used by the block
    std::vector<omi::Renderable*> m_renderables;
    // the original layers of the renderables
    std::vector<int> m_layers;

    // the collision detector of this block
    omi::CollisionDetector* m_detector;

    //--------------------------------SELECTION---------------------------------
    // is true while the left mouse button is down
    bool m_mouseDown;
    // is true if the block is selected
    bool m_selected;
    // the offset of the selection
    glm::vec3 m_selectOffset;
    // the position which the block was grabbed at
    glm::vec3 m_preSelectPos;
    // is true if block was just released
    bool m_released;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Decides whether the block is selected or not */
    void selection();

    /** Moves the block when it's selected */
    void move();

    /** Release the block and places it back on the grid */
    void release();

    /** Set the renderables to use the given transform */
    void setRenderableTransform( omi::Transform* transform );
};

#endif
