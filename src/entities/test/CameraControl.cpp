#include "CameraControl.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CameraControl::init() {

    // transform
    m_transform = new omi::Transform(
        "transform",
        util::vec::Vector3(),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_transform->translation.y = -5.0f;
    m_transform->translation.z = -15.0f;
    m_transform->rotation.x = 25.0f;
    m_components.add(m_transform);

    // add a camera
    m_components.add(
        new omi::Camera("camera", omi::cam::PERSPECTIVE, m_transform));
}

void CameraControl::update() {
}
