#include "Packs.hpp"

namespace pack {

void buildAllPack()
{
    //---------------------------------SHADERS----------------------------------

    // default shader
    omi::ResourceManager::addShader(
        "default_shader",
        resource_group::ALL,
        "res/gfx/shader/omicron/default_vertex.glsl",
        "res/gfx/shader/omicron/default_fragment.glsl"
    );

    // testing shader
    omi::ResourceManager::addShader(
        "test_shader",
        resource_group::ALL,
        "res/gfx/shader/omicron/test_vertex.glsl",
        "res/gfx/shader/omicron/test_fragment.glsl"
    );

    //-------------------------------GUI ELEMENTS-------------------------------

    // standard curosor
    omi::ResourceManager::addTextureMaterialSprite(
        "GUI_cursor_standard", resource_group::ALL,
        "test_shader",
        "res/gfx/texture/gui/cursor_std.png",
        layer::GUI_CURSOR,
        glm::vec2( 1, 1 ),
        glm::vec2( 1, 1 ),
        glm::vec2( 0, 0 ),
        omi::texture::CLAMP | omi::texture::SHOW_PIXELS,
        omi::material::SHADELESS
    );
}

} // namespace pack
