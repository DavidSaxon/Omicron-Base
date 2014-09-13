#include "PlayerShip.hpp"

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

namespace {

static const float MOVE_SPEED = 0.15f;

}

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PlayerShip::PlayerShip() {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

PlayerShip::~PlayerShip() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PlayerShip::init() {

    initComponents();
}

void PlayerShip::update() {

    // process input
    processInput();
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PlayerShip::processInput() {

    movement();
}


void PlayerShip::movement() {

    // calculate movement speed
    float moveSpeed = MOVE_SPEED * omi::fpsManager.getTimeScale();
    if (omi::input::isKeyPressed(sf::Keyboard::Up)) {

        m_shipT->translation.y += moveSpeed;
    }
    if (omi::input::isKeyPressed(sf::Keyboard::Down)) {

        m_shipT->translation.y -= moveSpeed;
    }
    if (omi::input::isKeyPressed(sf::Keyboard::Left)) {

        m_shipT->translation.x -= moveSpeed;
    }
    if (omi::input::isKeyPressed(sf::Keyboard::Right)) {

        m_shipT->translation.x += moveSpeed;
    }
}

void PlayerShip::initComponents() {

    //----------------------------------CAMERA----------------------------------
    m_camT = new omi::Transform("",
        util::vec::Vector3(0.0f, 0.0f, -1.0f),
        util::vec::Vector3(),
        util::vec::Vector3(0.055f, 0.055f, 0.055f)
    );
    m_components.add(m_camT);
    m_components.add(
        new omi::Camera("", omi::cam::ORTHOGRAPHIC, m_camT));
    //------------------------------SHIP POSITION-------------------------------
    m_shipT = new omi::Transform(
        "",
        util::vec::Vector3(),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_shipT);
    m_components.add(omi::ResourceManager::getSprite(
        "block_steel", "", m_shipT));
}