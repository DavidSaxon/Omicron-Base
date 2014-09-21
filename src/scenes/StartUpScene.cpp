#include "StartUpScene.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StartUpScene::init() {

    // apply settings
    omi::systemSettings.setCursorHidden(true);
    omi::renderSettings.setDepthTest(false);

    // load the need resources
    omi::ResourceManager::load(resource_group::ALL);
    omi::ResourceManager::load(resource_group::START_UP);

    // add entities
    m_omicronLogo = new OmicronLogo();
    addEntity(m_omicronLogo);
}

bool StartUpScene::update() {

    if (m_omicronLogo->done()) {

        // load the first scene resources
        // TODO:
        // omi::ResourceManager::load(resource_group::TEST);
        // start up finished
        return true;
    }

    return false;
}

omi::Scene* StartUpScene::nextScene() const {

    // release resources
    omi::ResourceManager::release(resource_group::START_UP);

    return new LevelScene();
}
