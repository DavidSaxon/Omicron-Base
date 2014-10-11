#include "BlockSelect.hpp"

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

omi::Transform* BlockSelect::m_transform = 0;
omi::Sprite* BlockSelect::m_sprite = 0;

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------


void BlockSelect::init()
{
    // create the transform
    m_transform = new omi::Transform(
        "",
        glm::vec3(),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_transform);
    // create the sprite
    m_sprite = omi::ResourceManager::getSprite(
        "builder_block_select", "", m_transform );
    m_sprite->visible = false;
    m_sprite->getMaterial().colour = glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f );
    m_components.add( m_sprite );
}

void BlockSelect::update()
{
    // do nothing
}

void BlockSelect::setVisibility( bool visible )
{
    m_sprite->visible = visible;
}

void BlockSelect::setPosition( const glm::vec3& pos )
{
    m_transform->translation = pos;
}

void BlockSelect::setValidColour()
{
    m_sprite->getMaterial().colour = glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f );
}

void BlockSelect::setInvalidColour()
{
    m_sprite->getMaterial().colour = glm::vec4( 1.0f, 0.0f, 0.0f, 1.0f );
}
