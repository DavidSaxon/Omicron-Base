#ifndef OMICRON_COMPONENT_LIGHT_LIGHT_HPP_
#   define OMICRON_COMPONENT_LIGHT_LIGHT_HPP_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include "lib/glm/glm.hpp"

#include "src/omicron/component/Component.hpp"

namespace omi {

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
    @param position the position of the light
    @param strength the strength of the light
    @param colour the colour of the light */
    Light(
            const std::string& id,
            const glm::vec3&   position,
                  float        strength,
            const glm::vec3&   colour );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //---------------------------------GETTERS----------------------------------

    /** #Override */
    virtual component::Type getType() const;

    /** @return the value of the light ( colour * strength ) */
    glm::vec3 getValue() const;

    /** @return the position of the light */
    const glm::vec3& getPosition() const;

    /** @return the strength of the light */
    float getStrength() const;

    /** @return the colour of the light */
    const glm::vec3& getColour() const;

    //---------------------------------SETTERS----------------------------------

    /** @param position the new position of the light */
    void setPosition( const glm::vec3& position );

    /** @param strength the new strength of the light */
    void setStrength( float strength );

    /** @param colour the new colour of the light */
    void setColour( const glm::vec3& colour );

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the position of the light
    glm::vec3 m_position;
    // the strength of the light
    float m_strength;
    // the colour of the light
    glm::vec3 m_colour;
};

} // namespace omi

#endif
