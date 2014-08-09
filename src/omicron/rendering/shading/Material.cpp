#include "Material.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Material::Material() 
    :
    shader (),
    colour (1.0f, 1.0f, 1.0f, 1.0f),
    texture() {
}

Material::Material(const Shader&             a_shader,
                   const util::vec::Vector4& a_colour,
                   const Texture&            a_texture)
    :
    shader (a_shader),
    colour (a_colour),
    texture(a_texture) {
}

Material::Material(const Material& other) :
    colour (other.colour),
    texture(other.texture),
    shader (other.shader) {
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

    shader  = other.shader;
    colour  = other.colour;
    texture = other.texture;

    return *this;
}

} // namespace omi