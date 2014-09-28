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
    addEntity( block_factory::hullSteel( glm::vec3() ) );
    addEntity( block_factory::hullSteel( glm::vec3(-2.0f, 0.0f, 0.0f) ) );
    addEntity( block_factory::hullSteel( glm::vec3(-2.0f, 2.0f, 0.0f) ) );
    addEntity( block_factory::hullSteel( glm::vec3( 2.0f, 0.0f, 0.0f) ) );
}
