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

    // set up collision groups
    omi::CollisionDetect::checkGroup("block", "block");

    // add entities
    addEntity(new Terrain());
    addEntity(new PlayerShip());
    addEntity(
        new SteelBlock(util::vec::Vector3(0.0f, 25.0f, 0.0f), block::NONE));
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