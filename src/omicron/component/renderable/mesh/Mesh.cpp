#include "Mesh.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Mesh::Mesh(const std::string& id,
                 Transform*   transform,
                 Geometry*    geometry,
                 Material*    material) :
    Renderable (id),
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

    glPushMatrix();

    // TODO: move this to be part of renderable?
    //apply translation
    util::vec::Vector3 translation(m_transform->computeTranslation());
    glTranslatef(translation.x, translation.y, translation.z);

    //apply rotation
    util::vec::Vector3 rotation(m_transform->computeRotation());
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);

    // colour
    glColor4f(m_material->colour.r,
              m_material->colour.g,
              m_material->colour.b,
              m_material->colour.a);

    // TODO: pass colour to shader instead

    // texture
    glBindTexture(GL_TEXTURE_2D, m_material->texture.getId());

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

    glPopMatrix();
}

} // namespace omi