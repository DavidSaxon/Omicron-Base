#include "TestPlayer.hpp"

namespace {

static const float LOOK_SPEED = 0.15f;
static const float MOVE_SPEED = 0.15f;

} // namespace anonymous

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestPlayer::init()
{
    // create the camera
    m_camT = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.0f, -1.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
        );
    m_components.add( m_camT );
    m_components.add(
        new omi::Camera( "", omi::cam::PERSPECTIVE, m_camT ) );
}

void TestPlayer::update()
{
    // look
    m_camT->rotation.x -=
        ( omi::displaySettings.getCentre().y - omi::input::getMousePos().y ) *
        LOOK_SPEED * omi::fpsManager.getTimeScale();
    m_camT->rotation.y -=
        ( omi::displaySettings.getCentre().x - omi::input::getMousePos().x ) *
        LOOK_SPEED * omi::fpsManager.getTimeScale();

    // move
    float moveSpeed = MOVE_SPEED * omi::fpsManager.getTimeScale();
    if ( omi::input::isKeyPressed( omi::input::key::W ) )
    {
        m_camT->translation.z +=
            util::math::cosd( m_camT->rotation.y ) * moveSpeed;
        m_camT->translation.x -=
            util::math::sind( m_camT->rotation.y ) * moveSpeed;
    }
    if ( omi::input::isKeyPressed( omi::input::key::S ) )
    {
        m_camT->translation.z -=
            util::math::cosd( m_camT->rotation.y ) * moveSpeed;
        m_camT->translation.x +=
            util::math::sind( m_camT->rotation.y ) * moveSpeed;
    }
    if ( omi::input::isKeyPressed( omi::input::key::A ) )
    {
        m_camT->translation.z +=
            util::math::sind( m_camT->rotation.y ) * moveSpeed;
        m_camT->translation.x +=
            util::math::cosd( m_camT->rotation.y ) * moveSpeed;
    }
    if ( omi::input::isKeyPressed( omi::input::key::D ) )
    {
        m_camT->translation.z -=
            util::math::sind( m_camT->rotation.y ) * moveSpeed;
        m_camT->translation.x -=
            util::math::cosd( m_camT->rotation.y ) * moveSpeed;
    }
}
