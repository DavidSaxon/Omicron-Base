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
    m_owner(owner) {

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
}

void Block::setPosition(const util::vec::Vector3& pos) {

    m_transform->translation = pos;
}

void Block::renew() {

    traversed = true;
}

//-----------------------------------GETTERS------------------------------------

block::Owner Block::getOwner() const {

    return m_owner;
}