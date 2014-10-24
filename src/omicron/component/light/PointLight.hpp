#ifndef OMICRON_COMPONENT_LIGHT_POINTLIGHT_HPP_
#   define OMICRON_COMPONENT_LIGHT_POINTLIGHT_HPP_

#include "Light.hpp"

namespace omi {

/*********************************************************************\
| Represents a infinitely small point which casts light evenly in all |
| directions.                                                         |
\*********************************************************************/
class PointLight : public Light {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new point light
    @param id the identifier of the component
    @param transform the transform of the light
    @param power the power of the light
    @param attenuation the distance the light travels before falling off
           completely
    @param colour the colour of the light */
    PointLight(
            const std::string&    id,
                  omi::Transform* transform,
                  float           power,
                  float           attenuation,
            const glm::vec3&      colour );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    light::Type getLightType() const;

    /** @return the attenuation of the light can reach */
    float getAttenuation() const;

    /** @param attenuation the new attenuation of the light */
    void setAttenuation( float attenuation );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    float m_attenuation;
};

} // namespace omi

#endif
