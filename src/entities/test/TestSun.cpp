#include "TestSun.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestSun::TestSun() :
    Entity(),
    m_move( 1.0f )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestSun::init()
{
    // transform
    m_transform = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.5f, 0.0f ),
            glm::vec3(),
            glm::vec3( 0.15f, 0.15f, 0.15f )
    );
    m_components.add( m_transform );

    // add light
    omi::DirectionalLight* light =
    light =  new omi::DirectionalLight(
        "", m_transform, 0.8f, glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    light->setCastShadow( true );
    m_components.add( light );

    // add the geo
    m_components.add(
            omi::ResourceManager::getMesh( "test_sun_geo", "", m_transform ) );
}

void TestSun::update()
{
    // move the light
    // m_move += 0.015f * omi::fpsManager.getTimeScale();

    m_transform->translation.x = sin( m_move );
    m_transform->translation.y = cos( m_move );
}
