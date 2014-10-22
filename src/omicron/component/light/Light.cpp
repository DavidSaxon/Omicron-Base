#include "Light.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Light::Light(
        const std::string&    id,
              omi::Transform* transform,
              float           strength,
        const glm::vec3&      colour )
    :
    Component  ( id ),
    m_transform( transform ),
    m_strength ( strength ),
    m_colour   ( colour )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

//-----------------------------------GETTERS------------------------------------

component::Type Light::getType() const
{
    return component::LIGHT;
}

glm::vec3 Light::getValue() const
{
    return m_colour * m_strength;
}

omi::Transform* Light::getTransform()
{
    return m_transform;
}

float Light::getStrength() const
{
    return m_strength;
}

const glm::vec3& Light::getColour() const
{
    return m_colour;
}

//-----------------------------------SETTERS------------------------------------

void Light::setTransform( omi::Transform* transform )
{
    m_transform = transform;
}

void Light::setStrength( float strength )
{
    m_strength = strength;
}

void Light::setColour( const glm::vec3& colour )
{
    m_colour = colour;
}

} // namespace omi
