#include "TestEnvironment.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEnvironment::init()
{
    m_components.add(
            omi::ResourceManager::getMesh( "test_skybox", "", NULL ) );
    m_components.add(
            omi::ResourceManager::getMesh( "test_floor_1", "", NULL ) );
}

void TestEnvironment::update()
{
}

