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
    @param strength the strength of the light
    @param distance the distance the light casts over
    @param colour the colour of the light */
    PointLight(
            const std::string&    id,
                  omi::Transform* transform,
                  float           strength,
                  float           distance,
            const glm::vec3&      colour );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    light::Type getLightType() const;

    /** @return the distance of the light can reach */
    float getDistance() const;

    /** @param distance the new distance the light can reach */
    void setDistance( float distance );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    float m_distance;
};

} // namespace omi

#endif
