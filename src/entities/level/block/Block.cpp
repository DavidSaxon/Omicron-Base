#include "Block.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Block::Block(
        const std::string& sprite,
        const util::vec::Vector3& pos,
              block::Owner         owner) :
    traversed(false),
    m_spriteName(sprite),
    m_owner(owner),
    top(NULL),
    bottom(NULL),
    left(NULL),
    right(NULL) {

    // create the transform
    m_transform = new omi::Transform(
        "", pos,
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Block::~Block() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Block::init() {

    // add components
    m_components.add(m_transform);
    m_components.add(omi::ResourceManager::getSprite(
        m_spriteName, "", m_transform));
    m_collisionDetect = new omi::CollisionDetector(
        "", "block", this);
    m_collisionDetect->addBounding(new omi::BoundingCircle(0.5f, m_transform));
    m_components.add(m_collisionDetect);
}

void Block::update() {

    // update based on owner
    switch (m_owner) {

        case block::NONE: {

            noOwnerUpdate();
            break;
        }
        case block::PLAYER: {

            break;
        }
        case block::ENEMY: {

            break;
        }
    }
}

void Block::setPosition(const util::vec::Vector3& pos) {

    traversed = true;
    m_transform->translation = pos;

    // set the position of neighbors
    if (top != NULL && !top->traversed) {

        top->setPosition(pos + util::vec::Vector3(0.0f, 1.0f, 0.0f));
    }
    if (bottom != NULL && !bottom->traversed) {

        bottom->setPosition(pos + util::vec::Vector3(0.0f, -1.0f, 0.0f));
    }
    if (left != NULL && !left->traversed) {

        left->setPosition(pos + util::vec::Vector3(-1.0f, 0.0f, 0.0f));
    }
    if (right != NULL && !right->traversed) {

        right->setPosition(pos + util::vec::Vector3(1.0f, 0.0f, 0.0f));
    }
}

void Block::renew() {

    traversed = true;
}

//-----------------------------------GETTERS------------------------------------

block::Owner Block::getOwner() const {

    return m_owner;
}

//------------------------------------STTERS------------------------------------

void Block::setOwner(block::Owner owner) {

    m_owner = owner;
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Block::noOwnerUpdate() {

    // move the block down
    m_transform->translation.y -=
        value::DOWN_SPEED * omi::fpsManager.getTimeScale();
}