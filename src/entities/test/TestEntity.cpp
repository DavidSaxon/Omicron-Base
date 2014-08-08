#include "TestEntity.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestEntity::TestEntity() :
    Entity(),
    m_transform(dynamic_cast<omi::Transform*>(m_components.get("transform"))),
    m_sineCounter(0.0f) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TestEntity::~TestEntity() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEntity::init() {

    // load some geometry yo
    omi::Geometry* geo =
        omi::loader::geoFromWavefront("res/gfx/geometry/test/box.obj");

    // load a texture
    omi::Texture* texture =
        omi::loader::textureFromImage("res/gfx/texture/test/brick.png");

    // create a material
    omi::Material* material = new omi::Material();

    // memory leaks!

    // add a mesh
    m_components.add(
        new omi::Mesh("cube", m_transform, geo, material));
}

void TestEntity::update() {

    // move the mesh up and down
    m_sineCounter += 0.05f * omi::fpsManager.getTimeScale();
    m_transform->translation.y = sin(m_sineCounter);

    // flip the mesh
    m_transform->rotation.x += 1.0f * omi::fpsManager.getTimeScale();
}
