#include "StartUpCamera.hpp"

//------------------------------------------------------------------------------
//                             PUBLIC MEMBER FUNCTION
//------------------------------------------------------------------------------

void StartUpCamera::init() {

    // transform
    m_transform = new omi::Transform(
        "transform",
        util::vec::Vector3(),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_transform);
    m_transform->translation.z = -1.0f;
    // add a camera
    m_components.add(
        new omi::Camera("camera", omi::cam::ORTHOGRAPHIC, m_transform));
}

void StartUpCamera::update() {
}
