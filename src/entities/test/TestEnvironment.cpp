#include "TestEnvironment.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEnvironment::init()
{
    // lights
    omi::Transform* t_0 = new omi::Transform(
            "",
            glm::vec3( 1.0f, 0.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
        );
    m_components.add( t_0 );
    m_components.add( new omi::DirectionalLight(
        "", t_0, 1.0f, glm::vec3( 1.0f, 0.0f, 1.0f )
    ) );

    omi::Transform* t_1 = new omi::Transform(
            "",
            glm::vec3( -4.0f, 0.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
        );
    m_components.add( new omi::PointLight(
        "", t_1, 1.0f, 3.0f, glm::vec3( 1.0f, 1.0f, 1.0f )
    ) );
    m_components.add( t_1 );
    omi::Transform* t_2 = new omi::Transform(
            "",
            glm::vec3( 4.0f, 0.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
        );
    m_components.add( t_2 );
    m_components.add( new omi::PointLight(
        "", t_2, 1.0f, 3.0f, glm::vec3( 1.0f, 0.0f, 1.0f )
    ) );

    // meshes
    m_components.add(
            omi::ResourceManager::getMesh( "test_tunnel_1", "", NULL ) );
    m_components.add(
            omi::ResourceManager::getMesh( "test_tunnel_pipe_1", "", NULL ) );
    m_components.add(
            omi::ResourceManager::getMesh(
            "test_tunnel_pipe_holder_1", "", NULL ) );
    m_components.add(
            omi::ResourceManager::getMesh( "test_floor_1", "", NULL ) );
}

void TestEnvironment::update()
{
}

