#include "BuilderScene.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderScene::init()
{
    // set up collision groups
    omi::CollisionDetect::checkGroup( "builder_block", "builder_block" );

    // create the builder grid
    m_grid = new BuilderGrid();

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

omi::Scene* BuilderScene::nextScene()
{
    // clean up
    delete m_grid;
    m_grid = NULL;

    return new LevelScene();
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderScene::initEntities()
{
    addEntity( new Cursor() );
    addEntity( new BuilderControl() );
    addEntity( new BuilderEnvironment() );

    // TESTING TODO: REMOVE ME
    addEntity( block_factory::builderBlock(
        block_factory::hullSteel,
        glm::vec3(),
        m_grid
    ) );
    addEntity( block_factory::builderBlock(
        block_factory::hullSteel,
        glm::vec3( -2.0f,  0.0f, 0.0f ),
        m_grid
    ) );
    addEntity( block_factory::builderBlock(
        block_factory::hullSteel,
        glm::vec3( -2.0f,  2.0f, 0.0f ),
        m_grid
    ) );
    addEntity( block_factory::builderBlock(
        block_factory::hullSteel,
        glm::vec3(  2.0f,  0.0f, 0.0f ),
        m_grid
    ) );
    addEntity( block_factory::builderBlock(
        block_factory::weaponRocketLauncher,
        glm::vec3( -2.0f, -2.0f, 0.0f ),
        m_grid
    ) );
    addEntity( block_factory::builderBlock(
        block_factory::engineCoal,
        glm::vec3(  0.0f,  2.0f, 0.0f ),
        m_grid
    ) );

    addEntity( new BoundaryScaffold( m_grid ) );
    addEntity( new BlockSelect() );



}
