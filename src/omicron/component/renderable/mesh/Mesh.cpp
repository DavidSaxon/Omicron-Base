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
    glBindTexture(GL_TEXTURE_2D, 0);

    // geometry
    glBegin(GL_TRIANGLES);
    for (unsigned i = 0; i < m_geometry->vertices.size(); ++i) {

        // begin a triangle
        if (i % 3 == 0) {

            
        } 

        // draw normals if the geometry contains them
        // if (m_geometry->normals.size() > 0) {

        //     glNormal3f(m_geometry->normals[i].x,
        //                m_geometry->normals[i].y,
        //                m_geometry->normals[i].z);
        // }

        // // TODO: check if texture exists too
        // // draw the texture coordinates if the exists
        // if (m_geometry->uv.size() > 0) {

        //     glTexCoord2f(m_geometry->uv[i].x, m_geometry->uv[i].y);
        // }

        // render vertices
        glVertex3f(m_geometry->vertices[i].x,
                   m_geometry->vertices[i].y,
                   m_geometry->vertices[i].z);

        // glVertex3f( 1.0,  1.0,  1.0);
        // glVertex3f(-1.0,  1.0,  1.0);
        // glVertex3f(-1.0, -1.0,  1.0);
    }
    glEnd();


    // glBegin(GL_TRIANGLES);

    // // front
    // glVertex3f( 1.0f,  1.0f,  1.0);
    // glVertex3f(-1.0f,  1.0f,  1.0);
    // glVertex3f(-1.0f, -1.0f,  1.0);
    // //glVertex3f( 1.0f, -1.0f,  1.0);

    // // left side
    // // glVertex3f(-1.0f,  1.0f,  1.0);
    // // glVertex3f(-1.0f,  1.0f, -1.0);
    // // glVertex3f(-1.0f, -1.0f, -1.0);
    // // glVertex3f(-1.0f, -1.0f,  1.0);

    // // // right side
    // // glVertex3f( 1.0f,  1.0f, -1.0);
    // // glVertex3f( 1.0f,  1.0f,  1.0);
    // // glVertex3f( 1.0f, -1.0f,  1.0);
    // // glVertex3f( 1.0f, -1.0f, -1.0);

    // // // back
    // // glVertex3f(-1.0f,  1.0f, -1.0);
    // // glVertex3f( 1.0f,  1.0f, -1.0);
    // // glVertex3f( 1.0f, -1.0f, -1.0);
    // // glVertex3f(-1.0f, -1.0f, -1.0);

    // // // top
    // // glVertex3f( 1.0f,  1.0f,  1.0);
    // // glVertex3f( 1.0f,  1.0f, -1.0);
    // // glVertex3f(-1.0f,  1.0f, -1.0);
    // // glVertex3f(-1.0f,  1.0f,  1.0);

    // // // bottom
    // // glVertex3f(-1.0f, -1.0f,  1.0);
    // // glVertex3f(-1.0f, -1.0f, -1.0);
    // // glVertex3f( 1.0f, -1.0f, -1.0);
    // // glVertex3f( 1.0f, -1.0f,  1.0);

    // glEnd();

    glPopMatrix();
}

} // namespace omi