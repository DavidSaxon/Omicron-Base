#ifndef OMICRON_RENDERING_SHADING_MATERIAL_PROPERTY_GLOW_HPP_
#   define OMICRON_RENDERING_SHADING_MATERIAL_PROPERTY_GLOW_HPP_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include "lib/glm/glm.hpp"

/******************************************************************************\
| The glow property defines the existence and behavior of a material's glowing |
| radius.                                                                      |
\******************************************************************************/
class Glow {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new glow property
    @param colour the colour of the glow halo which must have a combined rgb
                  value of 0.05
    @param brightness the brightness of the glow */
    Glow( const glm::vec3& colour, float brightness );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //---------------------------------GETTERS----------------------------------

    /** @return the colour of the glow halo */
    const glm::vec3& getColour() const;

    /** @return the brightness of the glow */
    float getBrightness() const;

    //---------------------------------SETTERS----------------------------------

    /** @param colour the colour of the glow halo */
    void setColour( const glm::vec3& colour );

    /** @param brightness the brightness of the glow */
    void setBrightness( float brightness );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the colour of the glow
    glm::vec3 m_colour;
    // the brightness of the glow
    float m_brightness;

};

#endif

