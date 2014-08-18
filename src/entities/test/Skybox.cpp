#include "Skybox.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Skybox::init() {

    // add a mesh
    m_components.add(omi::ResourceManager::getMesh("test_skybox",
        "mesh",  dynamic_cast<omi::Transform*>(m_components.get("transform"))));
}

void Skybox::update() {
}
