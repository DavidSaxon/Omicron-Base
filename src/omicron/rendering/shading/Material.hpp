#ifndef OMICRON_RENDERING_SHADING_MATERIAL_H_
#   define OMICRON_RENDERING_SHADING_MATERIAL_H_

#include "lib/Utilitron/Vector.hpp"

namespace omi {

/*********************************************************\
| A material contains all the shading data for an object. |
\*********************************************************/
class Material {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a material with the default set up */
    Material();

    // TODO:
    /** Creates a material using the given values
    @param colour the colour of the material */
    Material(const util::vec::Vector4& colour);

    /** Creates a copy of the given material
    @param other the material to copy from */
    Material(const Material& other);

    //--------------------------------------------------------------------------
    //                                 DESTUCTOR
    //--------------------------------------------------------------------------

    ~Material();

    //--------------------------------------------------------------------------
    //                                 OPERATORS
    //--------------------------------------------------------------------------

    /** Copies the values of the given material to this material
    @param other the material to copy from */
    const Material& operator=(const Material& other);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the colour of the material
    util::vec::Vector4 m_colour;
    // TODO: texture
    // TODO: shader
};

} // namespace omi

#endif 