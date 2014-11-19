#include "Glow.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Glow::Glow( const glm::vec3& colour, float brightness ) :
    m_colour    ( colour ),
    m_brightness( brightness )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

//-----------------------------------GETTERS------------------------------------

const glm::vec3& Glow::getColour() const
{
    return m_colour;
}

float Glow::getBrightness() const
{
    return m_brightness;
}

//-----------------------------------SETTERS------------------------------------

void Glow::setColour( const glm::vec3& colour )
{
    m_colour = colour;
}

void Glow::setBrightness( float brightness )
{
    m_brightness = brightness;
}
