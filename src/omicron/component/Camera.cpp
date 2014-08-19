#include "Camera.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Camera::Camera(const std::string& id,
             cam::Mode    mode,
             Transform*   transform)
    :
    Component  (id),
    m_mode     (mode),
    m_transform(transform) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Camera::~Camera() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

component::Type Camera::getType() const {

    return component::CAMERA;
}

void Camera::apply() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (m_mode == cam::PERSPECTIVE) {

        // set up the projection matrix
        gluPerspective(60.0f,
            displaySettings.getSize().x / displaySettings.getSize().y,
            0.001f, 1000.0f);
    }
    else {

        // set up the orthographic matrix
        float aspectRatio = 
            displaySettings.getSize().x / displaySettings.getSize().y;
        glOrtho(-aspectRatio, aspectRatio, -1.0f, 1.0f, 0.001f, 1000.0f);
    }

    // set up the model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // scale
    util::vec::Vector3 scale(m_transform->computeScale());
    glScalef(scale.x, scale.y, scale.z);
    //rotation
    util::vec::Vector3 rotation(m_transform->computeRotation());
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
    // translation
    util::vec::Vector3 translation = m_transform->computeTranslation();
    glTranslatef(translation.x, translation.y, translation.z);
}

cam::Mode Camera::getMode() const {

    return m_mode;
}

Transform* Camera::getTransform() {

    return m_transform;
}

void Camera::setMode(cam::Mode mode) {

    m_mode = mode;
}

void Camera::setTransform(Transform* transform) {

    m_transform = transform;
}

} // namespace omi