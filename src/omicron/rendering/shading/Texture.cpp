#include "Texture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Texture::Texture() :
    m_id        (0),
    m_format    (0),
    m_dimensions(),
    m_alpha     (false) {
}

Texture::Texture(      GLuint              id,
                       int                 format,
                 const util::vec::Vector2& dimensions,
                       bool                alpha) :
    m_id        (id),
    m_format    (format),
    m_dimensions(dimensions),
    m_alpha     (alpha) {
}

Texture::Texture(const Texture& other) :
    m_id        (other.m_id),
    m_format    (other.m_format),
    m_dimensions(other.m_dimensions),
    m_alpha     (other.m_alpha) {
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
    m_format =     other.m_format;
    m_dimensions = other.m_dimensions;
    m_alpha =      other.m_alpha;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

GLuint Texture::getId() const {

    return m_id;
}

int Texture::getFormat() const {

    return m_format;
}

const util::vec::Vector2& Texture::getDimesions() const {

    return m_dimensions;
}

bool Texture::hasAlpha() const {

    return m_alpha;
}

} // namespace omi