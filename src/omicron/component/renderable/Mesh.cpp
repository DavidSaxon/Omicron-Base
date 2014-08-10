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
    Renderable (id, layer),
    m_transform(transform),
    m_geometry (geometry),
    m_material (material) {
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

    // only render if the mesh is visible
    if (!visible) {

        return;
    }

    glPushMatrix();

    // apply the transform to matrices
    applyTransform(m_transform);

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
    GLuint texture = m_material.texture.getId();
    glUniform1i(glGetUniformLocation(program, "u_hasTexture"), texture);
    glBindTexture(GL_TEXTURE_2D, texture);

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
