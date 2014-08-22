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

    // load sound
    if (!m_music.openFromFile("res/sound/fx/start_up/omicron_intro.ogg")){

        std::cout << "fuck" << std::endl;
    }
    m_music.play();
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

    // release resources
    omi::ResourceManager::release(resource_group::START_UP);

    // revert settings
    omi::renderSettings.setDepthTest(true);

    // return new StartUpScene();
    return new TestScene();
}
