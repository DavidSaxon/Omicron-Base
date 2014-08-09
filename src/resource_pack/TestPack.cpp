#include "Packs.hpp"

namespace pack {

void buildTestBack() {


    //---------------------------------SHADERS----------------------------------


    omi::ResourceManager::addShader(
        "test_shader",
        resource_group::TEST,
        "res/gfx/shader/test/test_vertex.glsl",
        "res/gfx/shader/test/test_fragment.glsl"
    );


    //---------------------------------TEXTURES---------------------------------


    omi::ResourceManager::addTexture(
        "test_brick",
        resource_group::TEST,
        "res/gfx/texture/test/brick.png"
    );
}

} // namespace pack