#include "Input.hpp"

namespace omi {

namespace input {

namespace {

// the map of keys currently down
bool keyState[256];
// the map of special keys currently down
bool specialState[246];

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

void specialPressed(int key, int x, int y) {

    std::cout << "SPECIAL" << std::endl;

    specialState[key] = true;
}

void specialReleased(int key, int x, int y) {

    specialState[key] = false;
}

bool isKeyPressed(unsigned char key) {

    return keyState[key] || keyState[toupper(key)];
}

bool isCharPressed(unsigned char key) {

    return keyState[key];
}

bool isSpecialPressed(int key) {

    return specialState[key];
}

} // namespace input

} // namespace omi
