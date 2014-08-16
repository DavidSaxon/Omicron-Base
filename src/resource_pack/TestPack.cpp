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
    omi::ResourceManager::addMaterialGeometryMesh(
        "test_box_trail", resource_group::TEST,
        "test_shader",
        util::vec::Vector4(1.0f, 0.0f, 0.0f, 1.0f),
        "res/gfx/geometry/test/box.obj",
        1
    );
}

} // namespace pack
