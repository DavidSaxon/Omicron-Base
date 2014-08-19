#include "Packs.hpp"

namespace pack {

void buildAllPack() {

    //---------------------------------SHADERS----------------------------------

    // testing shader
    omi::ResourceManager::addShader(
        "test_shader",
        resource_group::ALL,
        "res/gfx/shader/omicron/test_vertex.glsl",
        "res/gfx/shader/omicron/test_fragment.glsl"
    );
}

} // namespace pack