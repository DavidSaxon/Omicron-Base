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
            glm::vec3( 0.0f, 0.0f, 10.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
        );
    m_components.add( m_camT );
    m_components.add(
        new omi::Camera( "", omi::cam::PERSPECTIVE, m_camT ) );

    // create collision detector
    m_collisionChecker = new omi::CollisionChecker( "" );
    m_collisionChecker->addBounding(
            new omi::BoundingCircle( 0.3f, m_camT ) );
    m_components.add( m_collisionChecker );

    // create spot light
    // m_components.add( new omi::SpotLight(
    //     "", m_camT, 1.0f, glm::vec3( 1.0f, 1.0f, 1.0f ),
    //     0.0f, 0.4f, 0.025f, 40.0f, 30.0f
    // ) );
}

void TestPlayer::update()
{
    // look
    m_camT->rotation.x +=
        ( omi::displaySettings.getCentre().y - omi::input::getMousePos().y ) *
        LOOK_SPEED * omi::fpsManager.getTimeScale();
    m_camT->rotation.y +=
        ( omi::displaySettings.getCentre().x - omi::input::getMousePos().x ) *
        LOOK_SPEED * omi::fpsManager.getTimeScale();

    // calculate the amount to move
    glm::vec3 move;
    float moveSpeed = MOVE_SPEED * omi::fpsManager.getTimeScale();
    if ( omi::input::isKeyPressed( omi::input::key::W ) )
    {
        move.z = -util::math::cosd( m_camT->rotation.y ) * moveSpeed;
        move.x = -util::math::sind( m_camT->rotation.y ) * moveSpeed;
    }
    if ( omi::input::isKeyPressed( omi::input::key::S ) )
    {
        move.z = util::math::cosd( m_camT->rotation.y ) * moveSpeed;
        move.x = util::math::sind( m_camT->rotation.y ) * moveSpeed;
    }
    if ( omi::input::isKeyPressed( omi::input::key::A ) )
    {
        move.z =  util::math::sind( m_camT->rotation.y ) * moveSpeed;
        move.x = -util::math::cosd( m_camT->rotation.y ) * moveSpeed;
    }
    if ( omi::input::isKeyPressed( omi::input::key::D ) )
    {
        move.z = -util::math::sind( m_camT->rotation.y ) * moveSpeed;
        move.x =  util::math::cosd( m_camT->rotation.y ) * moveSpeed;
    }

    // check for collisions
    if ( !m_collisionChecker->forwardCheck( move, "block" ) )
    {
        m_camT->translation += move;
    }
}
