#include "StartUp.hpp"

// TODO: include settings
#include <iostream>

namespace start_up {

omi::Scene* init() {

    // display settings
    // omi::displaySettings.setSize(util::vec::Vector2(960, 540));
    // omi::displaySettings.setPos(util::vec::Vector2(860, 440));
    omi::displaySettings.setSize(util::vec::Vector2(1920, 1080));
    omi::displaySettings.setPos(util::vec::Vector2(0, 0));
    omi::displaySettings.setTitle("Omicron Test");

    // render settings
    omi::renderSettings.setDepthTest(true);
    omi::renderSettings.setBackFaceCulling(true);
    omi::renderSettings.setClearColour(
        util::vec::Vector4(0.0f, 0.0f, 0.0f, 1.0f));

    //audio settings
    omi::audioSettings.setSoundDisabled(true);
    omi::audioSettings.setMusicDisabled(false);
    omi::audioSettings.setSoundVolume(1.0f);
    omi::audioSettings.setMusicVolume(1.0f);

    return new StartUpScene();
}

} // namespace start_up
