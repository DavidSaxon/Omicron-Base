#include "TestEntity.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEntity::init() {

    // initialise values
    m_counter = 0;
    m_sineCounter = 0.0;

    // store the transform
    m_transform = dynamic_cast<omi::Transform*>(m_components.get("transform"));

    // add a mesh
    m_components.add(omi::ResourceManager::getMesh(
            "test_torus", "mesh", m_transform));
}

void TestEntity::update() {

    // move the mesh up and down
    m_sineCounter += 0.05f * omi::fpsManager.getTimeScale();
    m_transform->translation.y = sin(m_sineCounter);
    m_transform->translation.z = sin(m_sineCounter / 7.0f) * 6.0f;

    // flip the mesh
    m_transform->rotation.x += 1.0f * omi::fpsManager.getTimeScale();

    // add a box trail entity
    if (m_counter == 0) {
        
        addEntity(new BoxTrail(m_transform));
    }

    ++m_counter;
    m_counter = m_counter % 8;
}
