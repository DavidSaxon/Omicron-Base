#include "Human.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Human::init()
{
    m_transform = new omi::Transform(
            "",
            glm::vec3( -4.0f, 0.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
        );
    m_components.add(
            omi::ResourceManager::getMesh( "test_human", "", m_transform ) );
}

void Human::update()
{
    m_transform->rotation.y += 0.5f * omi::fpsManager.getTimeScale();
}

