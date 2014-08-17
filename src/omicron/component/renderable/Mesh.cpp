#include "Mesh.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Mesh::Mesh(const std::string& id,
                 int          layer,
                 Transform*   transform,
                 Geometry*    geometry,
                 Material     material) :
    Renderable (id, layer, transform, material),
    m_geometry (geometry) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Mesh::~Mesh() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Mesh::render() {

    // update the material
    m_material.update();

    // only render if the mesh is visible
    if (!visible) {

        return;
    }

    glPushMatrix();

    // apply the transform to matrices
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
    if (m_material.texture != NULL) {

        glUniform1i(glGetUniformLocation(program, "u_hasTexture"), 1);
        glBindTexture(GL_TEXTURE_2D, m_material.texture->getId());
    }
    else {

        glUniform1i(glGetUniformLocation(program, "u_hasTexture"), 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    // geometry
    glBegin(GL_TRIANGLES);
    for (unsigned i = 0; i < m_geometry->vertices.size(); ++i) {


        // draw normals if the geometry contains them
        if (m_geometry->normals.size() > 0) {

            glNormal3f(m_geometry->normals[i].x,
                       m_geometry->normals[i].y,
                       m_geometry->normals[i].z);
        }

        // TODO: check if texture exists too
        // draw the texture coordinates if the exists
        if (m_geometry->uv.size() > 0) {

            glTexCoord2f(m_geometry->uv[i].x, m_geometry->uv[i].y);
        }

        // render vertices
        glVertex3f(m_geometry->vertices[i].x,
                   m_geometry->vertices[i].y,
                   m_geometry->vertices[i].z);
    }
    glEnd();

    //clean up
    glUseProgram(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();
}

} // namespace omi
