#include "Glow.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Glow::Glow( const glm::vec3& colour ) :
    m_colour( colour )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

const glm::vec3& Glow::getColour() const
{
    return m_colour;
}

void Glow::setColour( const glm::vec3& colour )
{
    m_colour = colour;
}
