#include "Sprite.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Sprite::Sprite(const std::string& id,
             Transform*   transform,
             Material     material) :
    Renderable(id),
    m_transform(transform),
    m_material(material) {
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

    glPushMatrix();

    // apply the transform to the matrices
    applyTransform(m_transform);

    // use the shader
    glUseProgram(m_material.shader.getProgram());

    // pass in colour to the shader
    glUniform4f(
        glGetUniformLocation(m_material.shader.getProgram(), "u_colour"),
        m_material.colour.r,
        m_material.colour.g,
        m_material.colour.b,
        m_material.colour.a
    );

    // texture
    glBindTexture(GL_TEXTURE_2D, m_material.texture.getId());

    // draw the sprite
    glBegin(GL_TRIANGLES);

        glNormal3f  ( 0.0f,  0.0f, 1.0f);
        glTexCoord2f( 1.0f,  1.0f);
        glVertex3f  ( 1.0f,  1.0f, 0.0f);

        glNormal3f  ( 0.0f,  0.0f, 1.0f);
        glTexCoord2f( 0.0f,  1.0f);
        glVertex3f  (-1.0f,  1.0f, 0.0f);

        glNormal3f  ( 0.0f,  0.0f, 1.0f);
        glTexCoord2f( 1.0f,  0.0f);
        glVertex3f  ( 1.0f, -1.0f, 0.0f);

        glNormal3f  ( 0.0f,  0.0f, 1.0f);
        glTexCoord2f( 0.0f,  0.0f);
        glVertex3f  (-1.0f, -1.0f, 0.0f);

        glNormal3f  ( 0.0f,  0.0f, 1.0f);
        glTexCoord2f( 1.0f,  0.0f);
        glVertex3f  ( 1.0f, -1.0f, 0.0f);

        glNormal3f  ( 0.0f,  0.0f, 1.0f);
        glTexCoord2f( 0.0f,  1.0f);
        glVertex3f  (-1.0f,  1.0f, 0.0f);

    glEnd();

    //clean up
    glUseProgram(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();
}

} // namespace omi