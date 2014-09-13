#include "LevelScene.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LevelScene::LevelScene() {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

LevelScene::~LevelScene() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void LevelScene::init() {

    // apply settings
    omi::renderSettings.setAmbientStrength(1.0f);
    omi::renderSettings.setAmbientColour(util::vec::Vector3(1.0f, 1.0f, 1.0f));

    // add entities
    addEntity(new PlayerShip());
}

bool LevelScene::update() {

    // exit if the escape key has been pressed
    if (omi::input::isKeyPressed(sf::Keyboard::Escape)) {

        return true;
    }

    return false;
}

omi::Scene* LevelScene::nextScene() const {

    return 0;
}