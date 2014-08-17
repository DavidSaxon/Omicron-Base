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




    omi::ResourceManager::addTexture(
        "test_sprite", resource_group::TEST,
        "res/gfx/texture/test/sprite_test.png"
    );

    omi::ResourceManager::addMaterial(
        "test_sprite", resource_group::TEST,
        "test_shader", "test_sprite"
    );


    //---------------------------------SPRITES----------------------------------


    omi::ResourceManager::addSprite(
        "test_sprite", resource_group::TEST,
        2, "test_sprite",
        util::vec::Vector2(4.0f, 4.0f),
        util::vec::Vector2(1.0f, 1.0f),
        util::vec::Vector2(0.0f, 0.0f)
    );

    //----------------------------------MESHES----------------------------------


    // omi::ResourceManager::addTextureMaterialGeometryMesh(
    //     "test_brick_cube", resource_group::TEST,
    //     "test_shader",
    //     "res/gfx/texture/test/brick.png",
    //     "res/gfx/geometry/test/torus.obj",
    //     1
    // );
    omi::ResourceManager::addMaterialGeometryMesh(
        "test_brick_cube", resource_group::TEST,
        "test_shader",
        util::vec::Vector4(1.0f, 0.0f, 0.0f, 1.0f),
        "res/gfx/geometry/test/torus.obj",
        1
    );
    omi::ResourceManager::addMaterialGeometryMesh(
        "test_box_trail", resource_group::TEST,
        "test_shader",
        util::vec::Vector4(1.0f, 0.0f, 0.0f, 1.0f),
        "res/gfx/geometry/test/torus.obj",
        1
    );
}

} // namespace pack
