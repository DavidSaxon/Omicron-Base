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
    m_omicronLogo = new OmicronLogo();
    addEntity(m_omicronLogo);
}

bool StartUpScene::update() {

    if (m_omicronLogo->done()) {

        // load the first scene resources
        omi::ResourceManager::load(resource_group::TEST);
        // start up finished
        return true;
    }

    return false;
}

omi::Scene* StartUpScene::nextScene() const {

    // turn depth testing back on
    omi::renderSettings.setDepthTest(true);
    // release resources
    omi::ResourceManager::release(resource_group::START_UP);

    return new TestScene();
}
