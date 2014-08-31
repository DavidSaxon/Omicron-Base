#include "Packs.hpp"

namespace pack {

void buildTestPack() {

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


    //----------------------------------SOUNDS----------------------------------

    omi::ResourceManager::addSound(
        "test_sound_1", resource_group::TEST,
        "res/sound/fx/test/test_sound_2.ogg", 3
    );
}

} // namespace pack
