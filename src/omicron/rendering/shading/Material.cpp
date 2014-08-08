#include "Material.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Material::Material() :
    m_colour(1.0f, 1.0f, 1.0f, 1.0f) {
}

Material::Material(const util::vec::Vector4& colour) :
    m_colour(colour) {
}

Material::Material(const Material& other) :
    m_colour(other.m_colour) {
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

    m_colour = other.m_colour;
}

} // namespace omi