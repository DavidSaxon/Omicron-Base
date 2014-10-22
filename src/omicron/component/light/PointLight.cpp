#include "PointLight.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PointLight::PointLight(
        const std::string& id,
        const glm::vec3&   position,
              float        strength,
              float        distance,
        const glm::vec3&   colour )
    :
    Light     ( id, position, strength, colour ),
    m_distance( distance )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

light::Type PointLight::getLightType() const
{
    return light::POINT;
}

float PointLight::getDistance() const
{
    return m_distance;
}

void PointLight::setDistance( float distance )
{
    m_distance = distance;
}

} // namespace omi
