#include "TestScene.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestScene::init()
{
    addEntity( new TestEnvironment() );
    addEntity( new TestPlayer() );
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
    return NULL;
}
