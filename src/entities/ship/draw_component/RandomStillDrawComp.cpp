#include "RandomStillDrawComp.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RandomStillDrawComp::RandomStillDrawComp( const std::string& renderableName ) :
    m_renderableName( renderableName )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

omi::Component* RandomStillDrawComp::getComponent( omi::Transform* transform )
{
    // get the sprite
    omi::Sprite* sprite = omi::ResourceManager::getSprite(
        m_renderableName, "", transform );
    // get the texture as an animation
    omi::Animation* animation = dynamic_cast<omi::Animation*>(
        sprite->getMaterial().texture);
    // pause on a randomly selected frame
    animation->setFrame( 3 );
    animation->pause();

    return sprite;
}
