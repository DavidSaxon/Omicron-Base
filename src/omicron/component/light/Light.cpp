#include "Light.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Light::Light(
        const std::string& id,
        const glm::vec3&   position,
              float        strength,
        const glm::vec3&   colour )
    :
    Component ( id ),
    m_position( position ),
    m_strength( strength ),
    m_colour  ( colour )
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

const glm::vec3& Light::getPosition() const
{
    return m_position;
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

void Light::setPosition( const glm::vec3& position )
{
    m_position = position;
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
