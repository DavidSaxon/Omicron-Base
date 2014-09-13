#include "StartUp.hpp"

// TODO: include settings
#include <iostream>

namespace start_up {

omi::Scene* init() {

    // display settings
    omi::displaySettings.setSize(util::vec::Vector2(960, 540));
    omi::displaySettings.setPos(util::vec::Vector2(800, 400));
    omi::displaySettings.setTitle("Blocks of Fury ");
    // omi::displaySettings.setFullscreen(true);
    omi::displaySettings.setVsync(true);

    // render settings
    omi::renderSettings.setDepthTest(true);
    omi::renderSettings.setBackFaceCulling(true);
    omi::renderSettings.setClearColour(
        util::vec::Vector4(0.0f, 0.0f, 0.0f, 1.0f));

    //audio settings
    omi::audioSettings.setSoundDisabled(true);
    omi::audioSettings.setMusicDisabled(true);
    omi::audioSettings.setSoundVolume(1.0f);
    omi::audioSettings.setMusicVolume(1.0f);

    return new StartUpScene();
}

} // namespace start_up
