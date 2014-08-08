#include "StartUp.hpp"

// TODO: include settings
#include <iostream>

namespace start_up {

omi::Scene* init() {

    // display settings
    omi::displaySettings.setSize(util::vec::Vector2(960, 540));
    omi::displaySettings.setPos(util::vec::Vector2(100, 100));
    omi::displaySettings.setTitle("Omicron Test");

    // render settings
    omi::renderSettings.setDepthTest(true);
    omi::renderSettings.setBackFaceCulling(false);
    omi::renderSettings.setClearColour(
        util::vec::Vector4(0.0f, 0.0f, 0.0f, 1.0f));

    return new TestScene();
}

} // namespace start_up
