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

    buildShip();
    initComponents();
}

void PlayerShip::update() {

    // process collisions
    

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

    // pass the position to the hub
    for(std::vector<Block*>::iterator it = m_blocks.begin();
        it != m_blocks.end(); ++it) {
        (*it)->traversed = false;
    }
    m_hub->setPosition(m_shipT->translation);
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
}

void PlayerShip::buildShip() {

    // create the hub
    m_hub = new PlayerHub(util::vec::Vector3());
    m_blocks.push_back(m_hub);
    addEntity(m_hub);

    //------------------------------INITIAL BLOCKS------------------------------

    Block* block1 = new SteelBlock(
        util::vec::Vector3(-1.0f, 0.0f, 0.0f), block::PLAYER);
    m_hub->left = block1;
    block1->right = m_hub;
    m_blocks.push_back(block1);
    addEntity(block1);

    Block* block2 = new SteelBlock(
        util::vec::Vector3(1.0f, 0.0f, 0.0f), block::PLAYER);
    m_hub->right = block2;
    block2->left = m_hub;
    m_blocks.push_back(block2);
    addEntity(block2);

    // Block* block3 = new SteelBlock(
    //     util::vec::Vector3(0.0f, 1.0f, 0.0f), block::PLAYER);
    // m_hub->top = block3;
    // block3->bottom = m_hub;
    // m_blocks.push_back(block3);
    // addEntity(block3);

    Block* block4 = new SteelBlock(
        util::vec::Vector3(-2.0f, 0.0f, 0.0f), block::PLAYER);
    block1->left = block4;
    block4->right = block1;
    m_blocks.push_back(block4);
    addEntity(block4);

    Block* block5 = new SteelBlock(
        util::vec::Vector3(2.0f, 0.0f, 0.0f), block::PLAYER);
    block2->right = block5;
    block5->left = block2;
    m_blocks.push_back(block5);
    addEntity(block5);

    Block* block6 = new SteelBlock(
        util::vec::Vector3(-1.0f, -1.0f, 0.0f), block::PLAYER);
    block1->bottom = block6;
    block6->top = block1;
    m_blocks.push_back(block6);
    addEntity(block6);

    Block* block7 = new SteelBlock(
        util::vec::Vector3(1.0f, -1.0f, 0.0f), block::PLAYER);
    block2->bottom = block7;
    block7->top = block2;
    m_blocks.push_back(block7);
    addEntity(block7);

    Block* block8 = new SteelBlock(
        util::vec::Vector3(0.0f, -1.0f, 0.0f), block::PLAYER);
    m_hub->bottom = block8;
    block8->top = m_hub;
    m_blocks.push_back(block8);
    addEntity(block8);

    Block* block9 = new SteelBlock(
        util::vec::Vector3(0.0f, -2.0f, 0.0f), block::PLAYER);
    block8->bottom = block9;
    block9->top = block8;
    m_blocks.push_back(block9);
    addEntity(block9);

    Block* block10 = new SteelBlock(
        util::vec::Vector3(-2.0f, 1.0f, 0.0f), block::PLAYER);
    block4->top = block10;
    block10->bottom = block4;
    m_blocks.push_back(block10);
    addEntity(block10);

    Block* block11 = new SteelBlock(
        util::vec::Vector3(2.0f, 1.0f, 0.0f), block::PLAYER);
    block5->top = block11;
    block11->bottom = block5;
    m_blocks.push_back(block11);
    addEntity(block11);
}