#include "EnemyShip.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

EnemyShip::EnemyShip(const util::vec::Vector3 pos) :
    m_health(5.0f) {

    m_shipT = new omi::Transform(
        "",
        pos,
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );

    m_right = bool(rand() % 2);
    m_sideSpeed = (rand() % 1000) / 5000.0f;

    if (!bool(rand() % 3)) {

        m_sideSpeed = 0.0f;
    }
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

EnemyShip::~EnemyShip() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void EnemyShip::init() {

    m_components.add(m_shipT);

    buildShip();
}

void EnemyShip::update() {

    movement();

    collisions();

    if (m_health <= 0.0f) {

        destroy();
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void EnemyShip::movement() {

    m_shipT->translation.y -=
        value::DOWN_SPEED * omi::fpsManager.getTimeScale();

    if (m_right) {

        m_shipT->translation.x +=
            m_sideSpeed * omi::fpsManager.getTimeScale();

        if (m_shipT->translation.x >= 31.0f) {

            m_right = false;
        }
    }
    else {

        m_shipT->translation.x -=
            m_sideSpeed * omi::fpsManager.getTimeScale();

        if (m_shipT->translation.x <= -31.0f) {

            m_right = true;
        }
    }

    // pass the position to the hub
    for(std::vector<Block*>::iterator it = m_blocks.begin();
        it != m_blocks.end(); ++it) {
        (*it)->traversed = false;
    }
    m_hub->setPosition(m_shipT->translation);
}

void EnemyShip::collisions() {

    // check over the collisions of the blocks contained withing this
    for (std::vector<Block*>::iterator it = m_blocks.begin();
         it != m_blocks.end(); ++it) {

        // get collision data from each block
        for (std::vector<omi::CollisionData>::iterator data =
            (*it)->m_collisionDetect->getCollisionData().begin();
            data != (*it)->m_collisionDetect->getCollisionData().end();
            ++data) {

            if (!data->group.compare("player_bullet")) {

                // cast the entity to a bullet
                Bullet* bullet = static_cast<Bullet*>(data->entity);
                bullet->destroy();
                m_health -= bullet->getDamage();
            }
        }
    }
}

void EnemyShip::destroy() {

    // disconnect all blocks
    for(std::vector<Block*>::iterator it = m_blocks.begin();
        it != m_blocks.end(); ++it) {

        (*it)->setOwner(block::NONE);
        (*it)->attach(false);
        (*it)->top = NULL;
        (*it)->bottom = NULL;
        (*it)->left = NULL;
        (*it)->right = NULL;

        (*it)->flyDir = util::vec::angleBetween(
            m_shipT->translation.xy(), (*it)->m_transform->translation.xy());
        (*it)->m_flySpeed = (rand() % 1000) / 10000.0f;
        (*it)->m_rotSpeed = ((rand() % 1000) / 150.0f) - 3.3333f;

        // randomly destroy half of the blocks
        if (rand() % 2) {

            (*it)->destroy();
        }
    }

    // destroy the hub
    m_hub->destroy();

    remove();
}

void EnemyShip::buildShip() {

    // create the hub
    m_hub = new EnemyHub(m_shipT->translation);
    m_hub->attach(true);
    m_blocks.push_back(m_hub);
    addEntity(m_hub);

    // randomly select a ship
    // TODO:

    buildShip1();
}

Block* EnemyShip::getBlock(const util::vec::Vector3& pos) {

    int rnd = rand() % 3;

    if (rnd == 0) {

        m_health += 0.5f;
        return new RustyBlock(pos, block::ENEMY);
    }
    else if (rnd == 1) {

        m_health += 1.0f;
        return new SteelBlock(pos, block::ENEMY);
    }
    else if (rnd == 2) {

        m_health += 1.5f;
        return new CopperBlock(pos, block::ENEMY);
    }
}

void EnemyShip::buildShip1() {

    Block* block1 = getBlock(util::vec::Vector3(-1.0f, 0.0f, 0.0f));
    m_hub->left = block1;
    block1->right = m_hub;
    block1->attach(true);
    m_blocks.push_back(block1);
    addEntity(block1);

    Block* block2 = getBlock(util::vec::Vector3(-2.0f, 0.0f, 0.0f));
    block1->left = block2;
    block2->right = block1;
    block2->attach(true);
    m_blocks.push_back(block2);
    addEntity(block2);

    Block* block3 = getBlock(util::vec::Vector3(-2.0f, -1.0f, 0.0f));
    block2->bottom = block3;
    block3->top = block2;
    block3->attach(true);
    m_blocks.push_back(block3);
    addEntity(block3);

    Block* block4 = getBlock(util::vec::Vector3(-2.0f, 1.0f, 0.0f));
    block2->top = block4;
    block4->bottom = block2;
    block4->attach(true);
    m_blocks.push_back(block4);
    addEntity(block4);

    Block* block5 = getBlock(util::vec::Vector3(1.0f, 0.0f, 0.0f));
    m_hub->right = block5;
    block5->left = m_hub;
    block5->attach(true);
    m_blocks.push_back(block5);
    addEntity(block5);

    Block* block6 = getBlock(util::vec::Vector3(2.0f, 0.0f, 0.0f));
    block5->right = block6;
    block6->left = block5;
    block6->attach(true);
    m_blocks.push_back(block6);
    addEntity(block6);

    Block* block7 = getBlock(util::vec::Vector3(2.0f, -1.0f, 0.0f));
    block6->bottom = block7;
    block7->top = block6;
    block7->attach(true);
    m_blocks.push_back(block7);
    addEntity(block7);

    Block* block8 = getBlock(util::vec::Vector3(2.0f, 1.0f, 0.0f));
    block6->top = block8;
    block8->bottom = block6;
    block8->attach(true);
    m_blocks.push_back(block8);
    addEntity(block8);
}