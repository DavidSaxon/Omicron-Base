#ifndef OMICRON_OVERRIDE_VALUES_HPP_
#   define OMICRON_OVERRIDE_VALUES_HPP_

namespace layer {

//------------------------------------------------------------------------------
//                                  ENUMERATORS
//------------------------------------------------------------------------------

enum Layer {
    BACKGROUND,
    SHIP_ENGINE,
    SHIP_WEAPON,
    SHIP_HULL,
    BOUNDARY,
    BUILDER_SELECT_OUTLINE,
    BUILDER_SELECT,
    BUILDER_CONNECTION_ARROW,
    GUI_CURSOR
};

} // namespace layer

namespace vdwk {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

// the size of a block
static const float BLOCK_SIZE = 1.0f;

} // namespace vdwk


// TODO: connection utils, should probably go in functions folder

namespace connection {

//------------------------------------------------------------------------------
//                                  ENUMERATORS
//------------------------------------------------------------------------------

enum Direction {
    TOP    = 1,
    BOTTOM = 2,
    LEFT   = 4,
    RIGHT  = 8,
    ABOVE  = 16,
    BELOW  = 32
};

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

static const glm::vec3 TOP_VECTOR   (  0.0,   1.0f, 0.0f );
static const glm::vec3 BOTTOM_VECTOR(  0.0f, -1.0f, 0.0f );
static const glm::vec3 LEFT_VECTOR  ( -1.0f,  0.0f, 0.0f );
static const glm::vec3 RIGHT_VECTOR (  1.0f,  0.0f, 0.0f );
static const glm::vec3 ABOVE_VECTOR (  0.0f,  0.0f, 0.0f );
static const glm::vec3 BELOW_VECTOR (  0.0f,  0.0f, 0.0f );

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/** Gets the vector relating to the given direction */
inline const glm::vec3& vecFromDir( Direction direction )
{
    switch ( direction )
    {
        case TOP:
        {
            return TOP_VECTOR;
        }
        case BOTTOM:
        {
            return BOTTOM_VECTOR;
        }
        case LEFT:
        {
            return LEFT_VECTOR;
        }
        case RIGHT:
        {
            return RIGHT_VECTOR;
        }
        case ABOVE:
        {
            return ABOVE_VECTOR;
        }
        case BELOW:
        {
            return BELOW_VECTOR;
        }
    }
    return TOP_VECTOR;
}


} // namespace connection

#endif
