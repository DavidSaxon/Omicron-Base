#include "CameraControl.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CameraControl::init() {

    // store the transform
    m_transform = dynamic_cast<omi::Transform*>(m_components.get("transform"));
    m_transform->translation.y = -5.0f;
    m_transform->translation.z = -15.0f;
    m_transform->rotation.x = 25.0f;

    // add a camera
    m_components.add(
        new omi::Camera("camera", omi::cam::ORTHOGRAPHIC, m_transform));
}

void CameraControl::update() {
}