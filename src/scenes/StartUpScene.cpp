#include "StartUpScene.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StartUpScene::init() {

    // turn off depth testing
    omi::renderSettings.setDepthTest(false);

    // load the start up resources resource group
    omi::ResourceManager::load(resource_group::START_UP);

    // add entities
    addEntity(new StartUpCamera());
    addEntity(new OmicronLogo());
}

bool StartUpScene::update() {

    return false;
}

omi::Scene* StartUpScene::nextScene() const {

    // turn depth testing back on
    omi::renderSettings.setDepthTest(true);

    return new TestScene();
}
