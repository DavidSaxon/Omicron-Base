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

    processBlockGrab();

    // process input
    processInput();
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PlayerShip::processBlockGrab() {

    std::vector<Block*> newBlocks;
    // check over the collisions of the blocks contained withing this
    for (std::vector<Block*>::iterator it = m_blocks.begin();
         it != m_blocks.end(); ++it) {

        // get collision data from each block
        for (std::vector<omi::CollisionData>::iterator data =
            (*it)->m_collisionDetect->getCollisionData().begin();
            data != (*it)->m_collisionDetect->getCollisionData().end();
            ++data) {

            if (data->group.compare("none_block")) {

                return;
            }

            // cast the entity to a block
            Block* block = static_cast<Block*>(data->entity);

            // add to the list of new blocks
            if (block->getOwner() == block::NONE &&
                find(newBlocks.begin(), newBlocks.end(), block) == 
                newBlocks.end()) {

                // add to the list of new entities;
                newBlocks.push_back(block);
            }
        }
    }

    // process the new blocks
    for (std::vector<Block*>::iterator it = newBlocks.begin();
         it != newBlocks.end(); ++it) {

        // find the closet block
        Block* closet = 0;
        float distance = 10000000.0f;
        for (std::vector<Block*>::iterator block = m_blocks.begin();
             block != m_blocks.end(); ++block) {

            if ((*block)->top != NULL && (*block)->bottom != NULL &&
                (*block)->left != NULL && (*block)->right != NULL) {

                continue;
            }

            if (util::vec::distance(
                (*it)->m_transform->translation,
                (*block)->m_transform->translation) <
                distance) {

                distance = util::vec::distance(
                    (*it)->m_transform->translation,
                    (*block)->m_transform->translation);
                closet = *block;
            }
        }
        // calculate the angle between the blocks
        float angle = util::vec::angleBetween(
            (*it)->m_transform->translation.xy(),
            closet->m_transform->translation.xy());
        if (angle < 0.0) {

            angle += 360.0f;
        }
        else if (angle >= 360.0f) {

            angle -= 360.0f;
        }
        // attach to the closet block
        if (angle > 45.0f &&  angle < 135.0f) {

            closet->bottom = *it;
            (*it)->top = closet;
        }
        else if (angle > 135.0f &&  angle < 225.0f) {

            closet->left = *it;
            (*it)->right = closet;
        }
        else if (angle > 225.0f &&  angle < 315.0f) {

            closet->top = *it;
            (*it)->bottom = closet;
        }
        else {

            closet->right = *it;
            (*it)->left = closet;
        }
    }
    for (std::vector<Block*>::iterator it = newBlocks.begin();
         it != newBlocks.end(); ++it) {

        (*it)->setOwner(block::PLAYER);
        (*it)->attach(true);
        m_blocks.push_back(*it);
    }
}

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
    block1->attach(true);
    m_blocks.push_back(block1);
    addEntity(block1);

    Block* block2 = new SteelBlock(
        util::vec::Vector3(1.0f, 0.0f, 0.0f), block::PLAYER);
    m_hub->right = block2;
    block2->left = m_hub;
    block2->attach(true);
    m_blocks.push_back(block2);
    addEntity(block2);

    Block* block3 = new SteelBlock(
        util::vec::Vector3(0.0f, 1.0f, 0.0f), block::PLAYER);
    m_hub->top = block3;
    block3->bottom = m_hub;
    block3->attach(true);
    m_blocks.push_back(block3);
    addEntity(block3);

    Block* block4 = new SteelBlock(
        util::vec::Vector3(-2.0f, 0.0f, 0.0f), block::PLAYER);
    block1->left = block4;
    block4->right = block1;
    block4->attach(true);
    m_blocks.push_back(block4);
    addEntity(block4);

    Block* block5 = new SteelBlock(
        util::vec::Vector3(2.0f, 0.0f, 0.0f), block::PLAYER);
    block2->right = block5;
    block5->left = block2;
    block5->attach(true);
    m_blocks.push_back(block5);
    addEntity(block5);

    Block* block6 = new SteelBlock(
        util::vec::Vector3(-1.0f, -1.0f, 0.0f), block::PLAYER);
    block1->bottom = block6;
    block6->top = block1;
    block6->attach(true);
    m_blocks.push_back(block6);
    addEntity(block6);

    Block* block7 = new SteelBlock(
        util::vec::Vector3(1.0f, -1.0f, 0.0f), block::PLAYER);
    block2->bottom = block7;
    block7->top = block2;
    block7->attach(true);
    m_blocks.push_back(block7);
    addEntity(block7);

    Block* block8 = new SteelBlock(
        util::vec::Vector3(0.0f, -1.0f, 0.0f), block::PLAYER);
    m_hub->bottom = block8;
    block8->top = m_hub;
    block8->attach(true);
    m_blocks.push_back(block8);
    addEntity(block8);

    Block* block9 = new SteelBlock(
        util::vec::Vector3(0.0f, -2.0f, 0.0f), block::PLAYER);
    block8->bottom = block9;
    block9->top = block8;
    block9->attach(true);
    m_blocks.push_back(block9);
    addEntity(block9);

    Block* block10 = new SteelBlock(
        util::vec::Vector3(-2.0f, 1.0f, 0.0f), block::PLAYER);
    block4->top = block10;
    block10->bottom = block4;
    block10->attach(true);
    m_blocks.push_back(block10);
    addEntity(block10);

    Block* block11 = new SteelBlock(
        util::vec::Vector3(2.0f, 1.0f, 0.0f), block::PLAYER);
    block5->top = block11;
    block11->bottom = block5;
    block11->attach(true);
    m_blocks.push_back(block11);
    addEntity(block11);
}