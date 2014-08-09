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

    //--------------------------------MATERIALS---------------------------------

    omi::ResourceManager::addMaterial(
        "test_brick",
        resource_group::TEST,
        "test_shader",
        util::vec::Vector4(1.0f, 1.0f, 1.0f, 1.0f),
        "test_brick"
    );
}

} // namespace pack