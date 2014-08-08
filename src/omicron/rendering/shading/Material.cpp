#include "Material.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Material::Material() :
    colour (1.0f, 1.0f, 1.0f, 1.0f),
    texture() {
}

Material::Material(const util::vec::Vector4& a_colour,
                   const Texture&            a_texture) :
    colour (a_colour),
    texture(a_texture) {
}

Material::Material(const Material& other) :
    colour (other.colour),
    texture(other.texture) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Material::~Material() {
}

//------------------------------------------------------------------------------
//                                   OPERATORS
//------------------------------------------------------------------------------

const Material& Material::operator=(const Material& other) {

    colour  = other.colour;
    texture = other.texture;
}

} // namespace omi