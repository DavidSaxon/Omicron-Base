#include "Texture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Texture::Texture() :
    m_id        (0),
    m_dimensions() {
}

Texture::Texture(GLuint id, const util::vec::Vector2& dimensions) :
    m_id        (id),
    m_dimensions(dimensions) {
}

Texture::Texture(const Texture& other) :
    m_id        (other.m_id),
    m_dimensions(other.m_dimensions) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Texture::~Texture() {
}

//------------------------------------------------------------------------------
//                                   OPERATORS
//------------------------------------------------------------------------------

const Texture& Texture::operator=(const Texture& other) {

    m_id =         other.m_id;
    m_dimensions = other.m_dimensions;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

GLuint Texture::getId() const {

    return m_id;
}

const util::vec::Vector2& Texture::getDimesions() const {

    return m_dimensions;
}

} // namespace omi