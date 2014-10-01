#include "SpriteDrawComp.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

SpriteDrawComp::SpriteDrawComp( const std::string& renderableName ) :
    m_renderableName( renderableName )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void SpriteDrawComp::init( omi::Transform* transform )
{
    // get the sprite and add to the list of renderables
    m_renderables.push_back( omi::ResourceManager::getSprite(
        m_renderableName, "", transform ) );
}
