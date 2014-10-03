#include "Cursor.hpp"

namespace {

//----------------------------------CONSTANTS-----------------------------------
static const float     CURSOR_SIZE  = 0.4f;
static const glm::vec3 OFFSET       ( 0.5f, -0.5f, 0.0f );

} // namespace anonymous

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Cursor::init()
{
    // create the transform
    m_transform = new omi::Transform(
        "",
        glm::vec3(),
        glm::vec3(),
        glm::vec3( CURSOR_SIZE, CURSOR_SIZE, CURSOR_SIZE )
    );
    m_components.add( m_transform );
    // create the sprite
    m_components.add( omi::ResourceManager::getSprite(
        "GUI_cursor_standard", "", m_transform ) );
}

void Cursor::update()
{
    // move to the mouse position
    glm::vec3 mousePos =
        omi::util::screenToWorld2D( omi::input::getMousePos() );
    m_transform->translation = mousePos + ( OFFSET * CURSOR_SIZE );
}

