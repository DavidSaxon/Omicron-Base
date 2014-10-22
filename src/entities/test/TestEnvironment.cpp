#include "TestEnvironment.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEnvironment::init()
{
    // lights
    m_components.add(
        new omi::PointLight(
            "",
            glm::vec3( -4.0f, 1.0f, 1.0f ),
            1.0f,
            3.0f,
            glm::vec3( 1.0f, 0.5f, 0.5f )
        )
    );
    m_components.add(
        new omi::PointLight(
            "",
            glm::vec3( 4.0f, 1.0f, 1.0f ),
            1.0f,
            3.0f,
            glm::vec3( 1.0f, 0.0f, 1.0f )
        )
    );

    // meshes
    m_components.add(
            omi::ResourceManager::getMesh( "test_tunnel_1", "", NULL ) );
    m_components.add(
            omi::ResourceManager::getMesh( "test_floor_1", "", NULL ) );
}

void TestEnvironment::update()
{
}

