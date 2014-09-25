#include "BuilderScene.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderScene::init()
{
    initEntities();
}

bool BuilderScene::update()
{
    // TODO:
    // exit if the escape key has been pressed
    if ( omi::input::isKeyPressed( omi::input::key::ESCAPE ) )
    {

        return true;
    }

    return false;
}

omi::Scene* BuilderScene::nextScene() const
{
    return new LevelScene();
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderScene::initEntities()
{
    addEntity( new BuilderControl() );
    addEntity( new BuilderEnvironment() );

    // TESTING TODO: REMOVE ME
    Block* block = new Block( util::vec::Vector3( ) );
    block->drawComponent = new RandomStillDrawComp( "ship_hull_steel" );
    addEntity( block );
}
