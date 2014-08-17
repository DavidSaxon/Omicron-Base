#include "Animation.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Animation::Animation() :
    m_frame(0) {
}

Animation::Animation(const t_TextureList& textures) :
    m_textures(textures),
    m_frame   (0) {
}

Animation::Animation(const Animation& other) :
    m_textures(other.m_textures),
    m_frame   (other.m_frame) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Animation::~Animation() { 
}

//------------------------------------------------------------------------------
//                                   OPERATORS
//------------------------------------------------------------------------------

const Animation& Animation::operator=(const Animation& other) {

    m_textures = other.m_textures;
    m_frame    = other.m_frame;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Animation::update() {

    ++m_frame;
    if (m_frame >= m_textures.size()) {

        m_frame = 0;
    }

    m_id = m_textures[m_frame];
}

tex::Type Animation::getType() const {

    return tex::ANIMATION;
}

} // namsepace omi