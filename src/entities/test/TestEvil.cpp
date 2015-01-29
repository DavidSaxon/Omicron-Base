#include "TestEvil.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEvil::init()
{
    m_transTimer = 0.0f;
    m_walk = false;

    m_transform = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.0f, -10.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_transform );

    m_mesh = omi::ResourceManager::getKeyFrameMesh(
            "test_evil_key", "", m_transform );
    m_components.add( m_mesh );
}

void TestEvil::update()
{
    if ( !m_walk )
    {
        m_transTimer += 0.0025f * omi::fpsManager.getTimeScale();
        if ( m_transTimer > 1.0f )
        {
            m_walk = true;
            m_mesh->transition( "walk", 42 );
        }
    }
    else
    {
        // move
        m_transform->translation.z += 0.022f * omi::fpsManager.getTimeScale();
    }
}
