#include "Input.hpp"

namespace omi {

namespace input {

namespace {

// the map of key's currently down
bool keyState[256];

} // namespace anonymous

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void keyPressed(unsigned char key, int x, int y) {

    keyState[key] = true;
}

void keyReleased(unsigned char key, int x, int y) {

    keyState[key] = false;
}   

bool isKeyPressed(unsigned char key) {

    return keyState[key] || keyState[toupper(key)];
}

bool isCharPressed(unsigned char key) {

    return keyState[key];
}

} // namespace input

} // namespace omi