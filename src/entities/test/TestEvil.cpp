#include "TestEvil.hpp"

void TestEvil::init()
{
    omi::Transform* transform = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.0f, -5.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( transform );
    omi::Mesh* mesh =
        omi::ResourceManager::getMesh( "test_evil", "", transform );
    m_components.add( mesh );
}

void TestEvil::update()
{
}
