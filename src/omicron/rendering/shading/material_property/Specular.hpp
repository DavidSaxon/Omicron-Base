#ifndef OMICRON_RENDERING_SHADING_MATERIAL_PROPERTY_SPECULAR_HPP_
#   define OMICRON_RENDERING_SHADING_MATERIAL_PROPERTY_SPECULAR_HPP_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include "lib/glm/glm.hpp"

/**********************************************************************\
| The specular property defines the existence and behavior of material |
| specularity.                                                         |
\**********************************************************************/
class Specular {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new specular property
    @param shininess the shininess of the material, which is shown by the size
                     of the specular highlights. Where a smaller number means a
                     larger highlight and a larger number means a smaller
                     highlight
    @param colour the colour of the specular highlights */
    Specular( float shininess, const glm::vec3& colour );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //---------------------------------GETTERS----------------------------------

    /** @return the shininess of the material */
    float getShininess() const;

    /** @return the colour of the material's specular highlights */
    const glm::vec3& getColour() const;

    //---------------------------------SETTERS----------------------------------

    /** @param shininess the new shininess of the material */
    void setShininess( float shininess );

    /** @param colour the new colour of the material's specular highlights */
    void setColour( const glm::vec3& colour );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    float m_shininess;
    glm::vec3 m_colour;
};

#endif
