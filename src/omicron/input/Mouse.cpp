#include "Input.hpp"

namespace omi {
    
namespace input {

// mouse button types
enum ButtonType {

    LEFT,
    MIDDLE,
    RIGHT
};

namespace {

    // the current buffer
    bool currentBuffer = 0;
    // the mouse move buffer
    util::vec::Vector2 mousePos[2];

    //the button states
    bool buttonStates[3];

} // namespace anonymous

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void mouseMove(int x, int y) {

    mousePos[currentBuffer].x = x;
    mousePos[currentBuffer].y = y;
}

void mouseButton(int button, int state, int x, int y) {

    buttonStates[button] = !state;
}

void switchMouseBuffers() {

    currentBuffer = !currentBuffer;
}

const util::vec::Vector2& getMousePos() {

    return mousePos[!currentBuffer];
}

bool mousePressed(ButtonType button) {

    return buttonStates[button];
}

} // namespace input

} // namespace omi