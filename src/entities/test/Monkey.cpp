#include "Monkey.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Monkey::init()
{
    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( 4.0f, 0.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
        );
    m_components.add(
            omi::ResourceManager::getMesh( "test_monkey", "", t ) );
}

void Monkey::update()
{
}

