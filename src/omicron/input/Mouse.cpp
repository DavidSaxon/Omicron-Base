#include "Input.hpp"

namespace omi {
    
namespace input {

namespace {

    // the current buffer
    bool currentBuffer = 0;
    // the mouse move buffer
    util::vec::Vector2 mousePos[2];

} // namespace anonymous

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void mouseMove(int x, int y) {

    mousePos[currentBuffer].x = x;
    mousePos[currentBuffer].y = y;
}

void mouseButton(int button, int state, int x, int y) {

    // TODO:
}

void switchMouseBuffers() {

    currentBuffer = !currentBuffer;
}

const util::vec::Vector2& getMousePos() {

    return mousePos[!currentBuffer];
}

} // namespace input

} // namespace omi