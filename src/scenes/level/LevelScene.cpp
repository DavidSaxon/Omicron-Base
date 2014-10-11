#include "LevelScene.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LevelScene::LevelScene()
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void LevelScene::init()
{
    // TODO
}

bool LevelScene::update()
{
    // exit if the escape key has been pressed
    if ( omi::input::isKeyPressed( omi::input::key::ESCAPE ) )
    {

        return true;
    }

    return false;
}

omi::Scene* LevelScene::nextScene()
{
    // TODO
    return 0;
}
