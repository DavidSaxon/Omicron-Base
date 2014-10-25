#include "PointLight.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PointLight::PointLight(
        const std::string&    id,
              omi::Transform* transform,
              float           power,
              float           constantAtt,
              float           linearAtt,
              float           quadraticAtt,
        const glm::vec3&      colour )
    :
    Light         ( id, transform, power, colour ),
    m_constantAtt ( constantAtt ),
    m_linearAtt   ( linearAtt ),
    m_quadraticAtt( quadraticAtt )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

light::Type PointLight::getLightType() const
{
    return light::POINT;
}

float PointLight::getConstantAtt() const
{
    return m_constantAtt;
}

float PointLight::getLinearAtt() const
{
    return m_linearAtt;
}

float PointLight::getQuadraticAtt() const
{
    return m_quadraticAtt;
}

void PointLight::setConstantAtt( float constantAtt )
{
    m_constantAtt = constantAtt;
}

void PointLight::setLinearAtt( float linearAtt )
{
    m_linearAtt = linearAtt;
}

void PointLight::setQuadraticAtt( float quadraticAtt )
{
    m_quadraticAtt = quadraticAtt;
}

} // namespace omi
