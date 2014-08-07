#include "TestEntity.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestEntity::TestEntity() :
    Entity(),
    m_transform(dynamic_cast<omi::Transform*>(m_components.get("transform"))),
    m_sineCounter(0.0f) {

    // load some geometry yo
    omi::Geometry* geo =
        omi::loader::geoFromWavefront("res/gfx/geometry/test/teapot.obj");

    // add a mesh
    m_components.add(
        new omi::Mesh(
            "cube",
            m_transform,
            geo
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
    m_sineCounter += 0.05f * omi::fpsManager.getTimeScale();
    m_transform->translation.y = sin(m_sineCounter);

    // flip the mesh
    m_transform->rotation.x += 1.0f * omi::fpsManager.getTimeScale();
}
