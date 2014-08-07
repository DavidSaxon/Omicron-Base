#include "TestEntity.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestEntity::TestEntity() :
    Entity(),
    m_transform(dynamic_cast<omi::Transform*>(m_components.get("transform"))),
    m_sineCounter(0.0f) {

    // add a mesh
    m_components.add(
        new omi::Mesh(
            "cube",
            m_transform
        )
    );
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TestEntity::~TestEntity() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEntity::update() {

    // move the mesh up and down
    m_sineCounter += 0.05f; // * omi::fpsManager.getTimeScale();


    m_transform->translation.y = sin(m_sineCounter);
    m_transform->rotation.x += 0.3f * omi::fpsManager.getTimeScale();
}
