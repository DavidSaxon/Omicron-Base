#include "Mesh.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Mesh::Mesh(const std::string& id, Transform* transform) :
    Renderable(id),
    m_transform(transform) {
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

    //apply translation
    util::vec::Vector3 translation(m_transform->computeTranslation());
    glTranslatef(translation.x, translation.y, translation.z);

    //apply rotation
    util::vec::Vector3 rotation(m_transform->computeRotation());
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);

    glBindTexture(GL_TEXTURE_2D, 0);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);

    // front
    glVertex3f( 1.0f,  1.0f,  1.0);
    glVertex3f(-1.0f,  1.0f,  1.0);
    glVertex3f(-1.0f, -1.0f,  1.0);
    glVertex3f( 1.0f, -1.0f,  1.0);

    // left side
    glVertex3f(-1.0f,  1.0f,  1.0);
    glVertex3f(-1.0f,  1.0f, -1.0);
    glVertex3f(-1.0f, -1.0f, -1.0);
    glVertex3f(-1.0f, -1.0f,  1.0);

    // right side
    glVertex3f( 1.0f,  1.0f, -1.0);
    glVertex3f( 1.0f,  1.0f,  1.0);
    glVertex3f( 1.0f, -1.0f,  1.0);
    glVertex3f( 1.0f, -1.0f, -1.0);

    // back
    glVertex3f(-1.0f,  1.0f, -1.0);
    glVertex3f( 1.0f,  1.0f, -1.0);
    glVertex3f( 1.0f, -1.0f, -1.0);
    glVertex3f(-1.0f, -1.0f, -1.0);

    // top
    glVertex3f( 1.0f,  1.0f,  1.0);
    glVertex3f( 1.0f,  1.0f, -1.0);
    glVertex3f(-1.0f,  1.0f, -1.0);
    glVertex3f(-1.0f,  1.0f,  1.0);

    // bottom
    glVertex3f(-1.0f, -1.0f,  1.0);
    glVertex3f(-1.0f, -1.0f, -1.0);
    glVertex3f( 1.0f, -1.0f, -1.0);
    glVertex3f( 1.0f, -1.0f,  1.0);

    glEnd();

    glPopMatrix();
}

} // namespace omi