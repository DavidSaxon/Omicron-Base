#include "Packs.hpp"

namespace pack {

void buildTestPack() {


    //---------------------------------SHADERS----------------------------------


    omi::ResourceManager::addShader(
        "test_shader",
        resource_group::TEST,
        "res/gfx/shader/test/test_vertex.glsl",
        "res/gfx/shader/test/test_fragment.glsl"
    );


    //---------------------------------SPRITES----------------------------------


    // omi::ResourceManager::addTextureMaterialSprite(
    //     "test_explosion_1", resource_group::TEST,
    //     "test_shader", util::vec::Vector4(0, 0, 1, 1),
    //     "res/gfx/texture/test/explosion_1/explosion.png",
    //     55, true, 1, 12, 2,
    //     util::vec::Vector2(4.0f, 4.0f),
    //     util::vec::Vector2(1.0f, 1.0f),
    //     util::vec::Vector2(0.0f, 0.0f)
    // );


    //----------------------------------MESHES----------------------------------


    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_skybox", resource_group::TEST,
        "test_shader",
        "res/gfx/texture/test/skybox.png",
        "res/gfx/geometry/test/skybox.obj",
        0
    );
    omi::ResourceManager::addMaterialGeometryMesh(
        "test_torus", resource_group::TEST,
        "test_shader",
        util::vec::Vector4(1.0f, 0.0f, 0.0f, 1.0f),
        "res/gfx/geometry/test/torus.obj",
        1
    );
}

} // namespace pack
