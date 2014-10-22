#ifndef OMICRON_COMPONENT_LIGHT_LIGHT_HPP_
#   define OMICRON_COMPONENT_LIGHT_LIGHT_HPP_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include "lib/glm/glm.hpp"

#include "src/omicron/component/Component.hpp"
#include "src/omicron/component/Transform.hpp"

namespace omi {

namespace light {

//! the different possible types of lights
enum Type {
    DIRECTIONAL,
    POINT,
    SPOT
};

} // namespace light

/**********************************************************\
| Base class that represents a component that casts light. |
\**********************************************************/
class Light : public Component {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Super constructor for lights
    @param id the identifier of the component
    @param transform the transform to use for the light
    @param strength the strength of the light
    @param colour the colour of the light */
    Light(
            const std::string&    id,
                  omi::Transform* transform,
                  float           strength,
            const glm::vec3&      colour );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //---------------------------------GETTERS----------------------------------

    /** #Override */
    virtual component::Type getType() const;

    /** @return the type of light this is */
    virtual light::Type getLightType() const = 0;

    /** @return the value of the light ( colour * strength ) */
    glm::vec3 getValue() const;

    /** @return the transform of the light */
    omi::Transform* getTransform();

    /** @return the strength of the light */
    float getStrength() const;

    /** @return the colour of the light */
    const glm::vec3& getColour() const;

    //---------------------------------SETTERS----------------------------------

    /** @param transform the new transform of the light */
    void setTransform( omi::Transform* transform );

    /** @param strength the new strength of the light */
    void setStrength( float strength );

    /** @param colour the new colour of the light */
    void setColour( const glm::vec3& colour );

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the position of the light
    omi::Transform* m_transform;
    // the strength of the light
    float m_strength;
    // the colour of the light
    glm::vec3 m_colour;
};

} // namespace omi

#endif
