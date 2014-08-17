#include "Texture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Texture::Texture() :
    m_id        (0) {
}

Texture::Texture(GLuint id) :
    m_id        (id){
}

Texture::Texture(const Texture& other) :
    m_id        (other.m_id) {
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

    return *this;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Texture::update() {

    // do nothing
}

GLuint Texture::getId() const {

    return m_id;
}

tex::Type Texture::getType() const {

    return tex::TEXTURE;
}

bool Texture::isVisible() const {

    return m_visible;
}

} // namespace omi