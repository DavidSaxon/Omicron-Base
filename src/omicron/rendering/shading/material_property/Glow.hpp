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
    value of 0.05 */
    Glow( const glm::vec3& colour );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** @return the colour of the glow halo */
    const glm::vec3& getColour() const;

    /** @param colour the colour of the glow halo */
    void setColour( const glm::vec3& colour );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    glm::vec3 m_colour;
};

#endif

