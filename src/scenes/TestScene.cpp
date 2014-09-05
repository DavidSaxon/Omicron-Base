#include "TestScene.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestScene::TestScene() {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TestScene::~TestScene() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestScene::init() {

    // apply settings
    omi::systemSettings.setCursorLocked(true);
    omi::systemSettings.setCursorLockPosition(omi::displaySettings.getCentre());

    omi::renderSettings.setAmbientStrength(0.3f);
    omi::renderSettings.setAmbientColour(util::vec::Vector3(0.3f, 0.3f, 1.0f));

    // create music
    m_musicStart = std::unique_ptr<omi::MusicPlayer>(
        new omi::MusicPlayer("res/sound/music/test/test_music_start.ogg", true));
    m_musicStart->setVolume(0.2f);
    m_musicMain = std::unique_ptr<omi::MusicPlayer>(
        new omi::MusicPlayer("res/sound/music/test/test_music_main.ogg", true));
    m_musicMain->setVolume(0.2f);
    m_musicMain->setLoop(true);

    // add entities
    addEntity(new Player());
    addEntity(new Skybox());
    addEntity(new Human());

    // start playing the music
    m_musicStart->play();
}

bool TestScene::update() {

    // exit if the escape key has been pressed
    if (omi::input::isKeyPressed(27)) {

        return true;
    }

    // transition music
    if (m_musicMain->isStopped() && m_musicStart->isStopped()) {

        m_musicMain->play();
    }

    return false;
}

omi::Scene* TestScene::nextScene() const {

    // revert settings
    omi::systemSettings.setCursorLocked(false);

    return 0;
}
