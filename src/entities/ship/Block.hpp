#ifndef VOIDWALKER_SHIP_BLOCK_HPP_
#    define VOIDWALKER_SHIP_BLOCK_HPP_

#include "src/entities/ship/builder_component/BuilderComponent.hpp"
#include "src/entities/ship/draw_component/DrawComponent.hpp"

/***************************************************************************\
| A block represents any part that a ship can compromise of, be part of the |
| hull, an engine, or a utility.                                            |
\***************************************************************************/
class Block : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the component used for drawing the block
    DrawComponent* drawComponent;

    // the component used for controlling the block in builder mode
    BuilderComponent* builderComponent;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new block
    @param pos the initial position of the block */
    Block( const glm::vec3& pos );

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Block();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the transform of the block
    omi::Transform* m_transform;
};

#endif
