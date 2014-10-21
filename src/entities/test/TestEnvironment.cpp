#include "TestEnvironment.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEnvironment::init()
{
    std::cout << "what the fuck?" << std::endl;
    m_components.add(
            omi::ResourceManager::getMesh( "test_skybox", "", NULL ) );
    // omi::ResourceManager::getMesh( "test_skybox", "", NULL );
}

void TestEnvironment::update()
{
}

