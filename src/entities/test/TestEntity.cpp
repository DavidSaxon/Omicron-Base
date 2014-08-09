#include "TestEntity.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEntity::init() {

    // initialise values
    m_sineCounter = 0.0;

    // store the transform
    m_transform = dynamic_cast<omi::Transform*>(m_components.get("transform"));

    // load some geometry yo
    omi::Geometry* geo =
        omi::loader::geoFromWavefront("res/gfx/geometry/test/box.obj");

    // memory leaks!

    // add a mesh
    m_components.add(
        new omi::Mesh(
            "cube",
            1,
            m_transform,
            geo,
            omi::ResourceManager::getMaterial("test_brick")
        )
    );
}

void TestEntity::update() {

    // move the mesh up and down
    m_sineCounter += 0.05f * omi::fpsManager.getTimeScale();
    m_transform->translation.y = sin(m_sineCounter);
    m_transform->translation.z = sin(m_sineCounter / 7.0f) * 6.0f;

    // flip the mesh
    m_transform->rotation.x += 1.0f * omi::fpsManager.getTimeScale();
}
