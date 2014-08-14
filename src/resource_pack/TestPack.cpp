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


    //----------------------------------MESHES----------------------------------


    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_brick_cube", resource_group::TEST,
        "test_shader",
        "res/gfx/texture/test/brick.png",
        "res/gfx/geometry/test/box.obj",
        1
    );
}

} // namespace pack
