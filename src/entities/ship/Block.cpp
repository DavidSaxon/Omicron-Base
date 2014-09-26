#include "Block.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Block::Block(const glm::vec3& pos ) :
    drawComponent( NULL )
{
    // set up the initial transform using the given position
    m_transform = new omi::Transform(
        "", pos,
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Block::~Block()
{
    // delete existing components
    delete drawComponent;
    drawComponent = NULL;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Block::init()
{
    // add the transform component
    m_components.add( m_transform );

    // TESTING
    // omi::Sprite* sprite = omi::ResourceManager::getSprite(
    //     "ship_hull_steel", "", m_transform );
    // omi::Animation* animation = dynamic_cast<omi::Animation*>(
    //     sprite->getMaterial().texture);
    // animation->setFrame( 3 );
    // animation->pause();
    // m_components.add( sprite );

    // get components from ship components
    if ( drawComponent )
    {
        m_components.add( drawComponent->getComponent( m_transform ) );
    }
}

void Block::update()
{
}
