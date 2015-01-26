#include "TestEvil.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEvil::init()
{
    m_transform = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.0f, -15.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_transform );

    omi::KeyFrameMesh* mesh = omi::ResourceManager::getKeyFrameMesh(
                                            "test_evil_key", "", m_transform );
    m_components.add( mesh );
}

void TestEvil::update()
{
    // move
    m_transform->translation.z += 0.0225f * omi::fpsManager.getTimeScale();
}
