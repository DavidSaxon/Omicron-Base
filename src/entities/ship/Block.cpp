#include "Block.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Block::Block( const util::vec::Vector3& pos )
{
    // set up the initial transform using the given position
    m_transform = new omi::Transform(
        "", pos,
        util::vec::Vector3(),
        util::vec::Vector3( 1.0f, 1.0f, 1.0f )
    );
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Block::init()
{
    // add the transform component
    m_components.add( m_transform );

    // TESTING
    omi::Sprite* sprite = omi::ResourceManager::getSprite(
        "ship_hull_steel", "", m_transform );
    omi::Animation* animation = dynamic_cast<omi::Animation*>(
        sprite->getMaterial().texture);
    animation->setFrame( 3 );
    animation->pause();
    m_components.add( sprite );

    // TODO: get components from ship components
}

void Block::update()
{
}
