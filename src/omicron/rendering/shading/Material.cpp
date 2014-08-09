#include "Material.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Material::Material() :
    colour (1.0f, 1.0f, 1.0f, 1.0f),
    texture(),
    shader () {
}

Material::Material(const util::vec::Vector4& a_colour,
                   const Texture&            a_texture,
                   const Shader&             a_shader) :
    colour (a_colour),
    texture(a_texture),
    shader (a_shader) {
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

    colour  = other.colour;
    texture = other.texture;
    shader  = other.shader;

    return *this;
}

} // namespace omi