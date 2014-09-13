#include "Block.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Block::init() {

    // transform
    m_transform = new omi::Transform("",
        util::vec::Vector3(0.0f, 10.0f, 0.0f),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_transform);
    // sprite
    m_components.add(omi::ResourceManager::getSprite(
        "block_steel", "", m_transform));
    // collision detector
    m_collisionDetect = new omi::CollisionDetector(
        "", "block", this);
    m_collisionDetect->addBounding(new omi::BoundingCircle(0.5f, m_transform));
    m_components.add(m_collisionDetect);
}

void Block::update() {
}

