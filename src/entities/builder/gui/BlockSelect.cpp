#include "BlockSelect.hpp"

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

omi::Transform* BlockSelect::m_transform          = 0;
omi::Sprite* BlockSelect::m_selectSprite          = 0;
omi::Sprite* BlockSelect::m_topConnectionArrow    = 0;
omi::Sprite* BlockSelect::m_bottomConnectionArrow = 0;
omi::Sprite* BlockSelect::m_leftConnectionArrow   = 0;
omi::Sprite* BlockSelect::m_rightConnectionArrow  = 0;

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
    // create selector sprite
    m_selectSprite = omi::ResourceManager::getSprite(
        "builder_block_select", "", m_transform );
    m_selectSprite->visible = false;
    m_selectSprite->getMaterial().colour = glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f );
    m_components.add( m_selectSprite );

    // top connection arrow
    omi::Transform* topTransform = new omi::Transform(
        "", m_transform,
        glm::vec3(),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( topTransform );
    m_topConnectionArrow = omi::ResourceManager::getSprite(
        "builder_connection_arrow", "", topTransform );
    m_topConnectionArrow->visible = false;
    m_topConnectionArrow->getMaterial().colour =
            glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f );
    m_components.add( m_topConnectionArrow );

    // bottom connection arrow
    omi::Transform* bottomTransform = new omi::Transform(
        "", m_transform,
        glm::vec3(),
        glm::vec3( 0.0f, 0.0f, 180.0f ),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( bottomTransform );
    m_bottomConnectionArrow = omi::ResourceManager::getSprite(
        "builder_connection_arrow", "", bottomTransform );
    m_bottomConnectionArrow->visible = false;
    m_bottomConnectionArrow->getMaterial().colour =
            glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f );
    m_components.add( m_bottomConnectionArrow );

    // left connection arrow
    omi::Transform* leftTransform = new omi::Transform(
        "", m_transform,
        glm::vec3(),
        glm::vec3( 0.0f, 0.0f, 90.0f ),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( leftTransform );
    m_leftConnectionArrow = omi::ResourceManager::getSprite(
        "builder_connection_arrow", "", leftTransform );
    m_leftConnectionArrow->visible = false;
    m_leftConnectionArrow->getMaterial().colour =
            glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f );
    m_components.add( m_leftConnectionArrow );

    // right connection arrow
    omi::Transform* rightTransform = new omi::Transform(
        "", m_transform,
        glm::vec3(),
        glm::vec3( 0.0f, 0.0f, 270.0f ),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( rightTransform );
    m_rightConnectionArrow = omi::ResourceManager::getSprite(
        "builder_connection_arrow", "", rightTransform );
    m_rightConnectionArrow->visible = false;
    m_rightConnectionArrow->getMaterial().colour =
            glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f );
    m_components.add( m_rightConnectionArrow );
}

void BlockSelect::update()
{
    // do nothing
}

void BlockSelect::setVisibility( bool visible )
{
    m_selectSprite->visible          = visible;
    m_topConnectionArrow->visible    = visible;
    m_bottomConnectionArrow->visible = visible;
    m_leftConnectionArrow->visible   = visible;
    m_rightConnectionArrow->visible  = visible;
}

void BlockSelect::setPosition( const glm::vec3& pos )
{
    m_transform->translation = pos;
}

void BlockSelect::setValidColour()
{
    m_selectSprite->getMaterial().colour = glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f );
}

void BlockSelect::setInvalidColour()
{
    m_selectSprite->getMaterial().colour = glm::vec4( 1.0f, 0.0f, 0.0f, 1.0f );
}

void BlockSelect::setTopVisibility( bool visible )
{
    m_topConnectionArrow->visible = visible;
}

void BlockSelect::setBottomVisibility( bool visible )
{
    m_bottomConnectionArrow->visible = visible;
}

void BlockSelect::setLeftVisibility( bool visible )
{
    m_leftConnectionArrow->visible = visible;
}

void BlockSelect::setRightVisibility( bool visible )
{
    m_rightConnectionArrow->visible = visible;
}
