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

    // create a material
    omi::Material* material =
        new omi::Material(
            util::vec::Vector4(1.0f, 1.0f, 1.0f, 1.0f),
            omi::ResourceManager::getTexture("test_brick"),
            omi::ResourceManager::getShader ("test_shader")
        );

    // memory leaks!

    // add a mesh
    m_components.add(
        new omi::Mesh(
            "cube",
            m_transform,
            geo,
            material
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
