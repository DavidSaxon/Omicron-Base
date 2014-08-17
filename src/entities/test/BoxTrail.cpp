#include "BoxTrail.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BoxTrail::BoxTrail(const omi::Transform* transform) {

    m_transform = new omi::Transform("pos", *transform);
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BoxTrail::init() {

    m_components.add(m_transform);

    // add a mesh
    omi::Mesh* mesh =
        omi::ResourceManager::getMesh("test_torus", "mesh", m_transform);
    m_material = &mesh->getMaterial();
	// m_material->colour.a = 0.5f;
    m_components.add(mesh);
}

void BoxTrail::update() {

    m_material->colour.a -= 0.005 * omi::fpsManager.getTimeScale();

    if (m_material->colour.a <= 0.0f) {

        remove();
    }
}
