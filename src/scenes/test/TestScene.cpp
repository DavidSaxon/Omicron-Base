#include "TestScene.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestScene::init()
{
    // apply settings
    omi::systemSettings.setCursorLocked( true );
    omi::systemSettings.setCursorLockPosition(
        omi::displaySettings.getCentre() );

    // ambient lighting
    omi::renderSettings.setAmbientStrength( 0.3f );
    omi::renderSettings.setAmbientColour( glm::vec3( 0.3f, 0.3f, 1.0f ) );

    // add entities
    addEntity( new TestPlayer() );
    addEntity( new TestEnvironment() );
    addEntity( new Human() );
    addEntity( new Monkey() );
}

bool TestScene::update()
{
    // exit if the escape key has been pressed
    if ( omi::input::isKeyPressed( omi::input::key::ESCAPE ) )
    {
        return true;
    }

    return false;
}

omi::Scene* TestScene::nextScene()
{
    // revert settings
    omi::systemSettings.setCursorLocked( false );

    return NULL;
}
