#ifndef OMICRON_COMPONENT_LIGHT_SPOTLIGHT_HPP_
#   define OMICRON_COMPONENT_LIGHT_SPOTLIGHT_HPP_

#include "Light.hpp"

namespace omi {

/*********************************************************************\
| Represents an infinitely small light that casts light in a specific |
| direction.                                                          |
\*********************************************************************/
class SpotLight : public Light {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new spot light
    @param id the identifier of the component
    @param transform the transform of the light
    @param colour the colour of the light
    @param power the power of the light
    @param constantAtt the constant attenuation value of the light
    @param linearAtt the linear attenuation value of the light
    @param quadraticAtt the quadratic attenuation of the light
    @param outerArc the angle which determines the maximum size of the cone
    @param decay the rate at which the light decays to the outer edge of the
                 cone */
    SpotLight(
        const std::string&    id,
              omi::Transform* transform,
              float           power,
        const glm::vec3&      colour,
              float           constantAtt,
              float           linearAtt,
              float           quadraticAtt,
              float           arc,
              float           decay );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //---------------------------------GETTERS----------------------------------

    /** #Override */
    light::Type getLightType() const;

    /** @return the constant attenuation of the light */
    float getConstantAtt() const;

    /** @return the linear attenuation of the light */
    float getLinearAtt() const;

    /** @return the quadratic attenuation of the light */
    float getQuadraticAtt() const;

    /** @return the arc of the light */
    float getArc() const;

    /** @return the decay of the light */
    float getDecay() const;

    //---------------------------------SETTERS----------------------------------

    /** @param constantAtt the new constant attenuation of the light */
    void setConstantAtt( float constantAtt );

    /** @param linearAtt the new linear attenuation of the light */
    void setLinearAtt( float linearAtt );

    /** @param quadraticAtt the new quadratic attenuation of the light */
    void setQuadraticAtt( float quadraticAtt );

    /** @param arc the new arc of the light */
    void setArc( float arc );

    /** @param decay the new decay of the light */
    void setDecay( float decay );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    float m_constantAtt;
    float m_linearAtt;
    float m_quadraticAtt;
    float m_arc;
    float m_decay;
};

} // namespace omi

#endif
