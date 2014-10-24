#include "PointLight.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PointLight::PointLight(
        const std::string&    id,
              omi::Transform* transform,
              float           power,
              float           attenuation,
        const glm::vec3&      colour )
    :
    Light     ( id, transform, power, colour ),
    m_attenuation( attenuation )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

light::Type PointLight::getLightType() const
{
    return light::POINT;
}

float PointLight::getAttenuation() const
{
    return m_attenuation;
}

void PointLight::setAttenuation( float attenuation )
{
    m_attenuation = attenuation;
}

} // namespace omi
