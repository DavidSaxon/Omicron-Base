#include "Sprite.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Sprite::Sprite(const std::string&        id,
                     int                 layer,
                     Transform*          transform,
                     Material            material,
               const util::vec::Vector2& size,
               const util::vec::Vector2& texSize,
               const util::vec::Vector2& texOffset)
    :
    Renderable (id, layer, transform, material),
    m_size     (size),
    m_half     (size.x / 2.0f, size.y / 2.0f),
    m_texSize  (texSize),
    m_texOffset(texOffset),
    m_texCoord (texOffset.x + texSize.x, texOffset.y + texSize.y) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Sprite::~Sprite() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Sprite::render() {

    // update the material
    m_material.update();

    // only render if the sprite is visible
    if (!visible) {

        return;
    }

    glPushMatrix();

    // apply the transform to the matrices
    applyTransformations();

    // the OpenGL program
    GLuint program = m_material.shader.getProgram();

    // use the shader
    glUseProgram(program);

    // pass in colour to the shader
    glUniform4f(
        glGetUniformLocation(program, "u_colour"),
        m_material.colour.r,
        m_material.colour.g,
        m_material.colour.b,
        m_material.colour.a
    );

    // texture
    GLuint texture = m_material.texture->getId();
    glUniform1i(glGetUniformLocation(program, "u_hasTexture"), texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // short hand for half sprite size


    // draw the sprite
    glBegin(GL_TRIANGLES);

        glTexCoord2f(m_texCoord.x, m_texCoord.y);
        glNormal3f( 0.0f,      0.0f,     1.0f);
        glVertex3f( m_half.x,  m_half.y, 0.0f);

        glTexCoord2f(m_texOffset.x, m_texCoord.y);
        glNormal3f( 0.0f,      0.0f,     1.0f);
        glVertex3f(-m_half.x,  m_half.y, 0.0f);

        glTexCoord2f(m_texCoord.x, m_texOffset.y);
        glNormal3f( 0.0f,      0.0f,     1.0f);
        glVertex3f( m_half.x, -m_half.y, 0.0f);

        glTexCoord2f(m_texOffset.x, m_texOffset.y);
        glNormal3f( 0.0f,      0.0f,     1.0f);
        glVertex3f(-m_half.x, -m_half.y, 0.0f);

        glTexCoord2f(m_texCoord.x, m_texOffset.y);
        glNormal3f( 0.0f,      0.0f,     1.0f);
        glVertex3f( m_half.x, -m_half.y, 0.0f);

        glTexCoord2f(m_texOffset.x, m_texCoord.y);
        glNormal3f( 0.0f,      0.0f,     1.0f);
        glVertex3f(-m_half.x,  m_half.y, 0.0f);

    glEnd();

    //clean up
    glUseProgram(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();
}

const util::vec::Vector2& Sprite::getSize() const {

    return m_size;
}

const util::vec::Vector2& Sprite::getTexSize() const {

    return m_texSize;
}

const util::vec::Vector2& Sprite::getTexOffset() const {

    return m_texOffset;
}

void Sprite::setSize(const util::vec::Vector2& size) {

    m_size = size;
    m_half.x = size.x / 2.0f;
    m_half.y = size.y / 2.0f;
}

void Sprite::setTexSize(const util::vec::Vector2& texSize) {

    m_texSize = texSize;
    m_texCoord.x = m_texOffset.x + m_texSize.x;
    m_texCoord.y = m_texOffset.y + m_texSize.y;
}

void Sprite::setTexOffset(const util::vec::Vector2& texOffset) {

    m_texOffset = texOffset;
    m_texCoord.x = m_texOffset.x + m_texSize.x;
    m_texCoord.y = m_texOffset.y + m_texSize.y;
}

} // namespace omi
