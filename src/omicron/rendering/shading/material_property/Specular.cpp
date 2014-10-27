#include "Specular.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Specular::Specular( float shininess, const glm::vec3& colour )
    :
    m_shininess( shininess ),
    m_colour   ( colour )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

float Specular::getShininess() const
{
    return m_shininess;
}

const glm::vec3& Specular::getColour() const
{
    return m_colour;
}

void Specular::setShininess( float shininess )
{
    m_shininess = shininess;
}

void Specular::setColour( const glm::vec3& colour )
{
    m_colour = colour;
}
