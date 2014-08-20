#include "Player.hpp"

namespace {

static const float MOVE_SPEED = 0.2f;

} // namespace anonymouse

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Player::Player() {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Player::~Player() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Player::init() {

    // create a camera
    m_camT = new omi::Transform(
        "camera_t",
        util::vec::Vector3(),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_camT->translation.z = -15.0f;
    m_components.add(m_camT);
    m_components.add(
        new omi::Camera("camera", omi::cam::PERSPECTIVE, m_camT));
}

void Player::update() {

    // move the player
    if (omi::input::isKeyPressed('w')) {

        m_camT->translation.z += MOVE_SPEED * omi::fpsManager.getTimeScale();
    }
    if (omi::input::isKeyPressed('s')) {

        m_camT->translation.z -= MOVE_SPEED * omi::fpsManager.getTimeScale();
    }
    if (omi::input::isKeyPressed('a')) {

        m_camT->translation.x += MOVE_SPEED * omi::fpsManager.getTimeScale();
    }
    if (omi::input::isKeyPressed('d')) {

        m_camT->translation.x -= MOVE_SPEED * omi::fpsManager.getTimeScale();
    }
}

