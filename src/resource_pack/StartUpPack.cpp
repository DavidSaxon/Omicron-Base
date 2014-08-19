#include "Packs.hpp"

namespace pack {

void buildStartUpPack() {


    //---------------------------------SHADERS----------------------------------


    omi::ResourceManager::addShader(
        "test_shader",
        resource_group::START_UP,
        "res/gfx/shader/test/test_vertex.glsl",
        "res/gfx/shader/test/test_fragment.glsl"
    );


    //---------------------------------SPRITES----------------------------------

    // omicron logo text bottom
    omi::ResourceManager::addTextureMaterialSprite(
        "omicron_text_bottom", resource_group::START_UP,
        "test_shader",
        "res/gfx/texture/start_up/omicron/logo_text_bottom.png", 2,
        util::vec::Vector2(2, 2),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // omicron logo text top
    omi::ResourceManager::addTextureMaterialSprite(
        "omicron_text_top", resource_group::START_UP,
        "test_shader",
        "res/gfx/texture/start_up/omicron/logo_text_top.png", 3,
        util::vec::Vector2(2, 2),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // omicron long lens flare
    omi::ResourceManager::addTextureMaterialSprite(
        "omicron_flare_long", resource_group::START_UP,
        "test_shader",
        "res/gfx/texture/start_up/omicron/logo_flare_long.png", 4,
        util::vec::Vector2(2, 2),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
}


} // namespace pack
