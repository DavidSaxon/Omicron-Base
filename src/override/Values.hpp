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
    BUILDER_SELECT,
    BUILDER_SELECT_OUTLINE,
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

#endif
