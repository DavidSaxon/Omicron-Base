#include "Packs.hpp"

namespace pack {
    
void buildLevelPack() {

    //--------------------------------------------------------------------------
    //                                  SHADERS
    //--------------------------------------------------------------------------

    omi::ResourceManager::addShader(
        "engine_trail_shader",
        resource_group::ALL,
        "res/gfx/shader/level/engine_trail_vertex.glsl",
        "res/gfx/shader/level/engine_trail_fragment.glsl"
    );

    omi::ResourceManager::addShader(
        "effect_shader",
        resource_group::ALL,
        "res/gfx/shader/level/effect_vertex.glsl",
        "res/gfx/shader/level/effect_fragment.glsl"
    );

    //--------------------------------------------------------------------------
    //                                  SPRITES
    //--------------------------------------------------------------------------

    //---------------------------------TERRAIN----------------------------------

    // MAIN 1
    omi::ResourceManager::addTextureMaterialSprite(
        "terrain", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/terrain/grass.png", TERRAIN,
        util::vec::Vector2(65, 65),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );

    // GRASS
    omi::ResourceManager::addTexture(
        "terrain_grass", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/grass.png"
    );
    omi::ResourceManager::addTexture(
        "terrain_grass_to_dirt", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/grass_to_dirt.png"
    );
    omi::ResourceManager::addTexture(
        "terrain_grass_to_cave", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/grass_to_cave.png"
    );
    // DIRT
    omi::ResourceManager::addTexture(
        "terrain_dirt", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/dirt.png"
    );
    omi::ResourceManager::addTexture(
        "terrain_dirt_to_grass", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/dirt_to_grass.png"
    );
    omi::ResourceManager::addTexture(
        "terrain_dirt_to_desert", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/dirt_to_desert.png"
    );
    // DESERT
    omi::ResourceManager::addTexture(
        "terrain_desert", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/desert.png"
    );
    omi::ResourceManager::addTexture(
        "terrain_desert_to_dirt", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/desert_to_dirt.png"
    );
    // CAVE
    omi::ResourceManager::addTexture(
        "terrain_cave", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/cave.png"
    );
    omi::ResourceManager::addTexture(
        "terrain_cave_to_grass", resource_group::LEVEL,
        "res/gfx/texture/level/terrain/cave_to_grass.png"
    );

    // CAVE OPENING
    omi::ResourceManager::addTextureMaterialSprite(
        "cave_opening", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/terrain/cave_open.png", TOP,
        util::vec::Vector2(65, 65),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );

    //----------------------------------BLOCKS----------------------------------

    // HUB PLAYER
    omi::ResourceManager::addTextureMaterialSprite(
        "block_hub_player", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/block/hub_player.png", SHIP_BLOCK,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // HUB ENEMY
    omi::ResourceManager::addTextureMaterialSprite(
        "block_hub_enemy", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/block/hub_enemy.png", SHIP_BLOCK,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // RUSTY
    omi::ResourceManager::addTextureMaterialSprite(
        "block_rusty", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/block/rusty.png", SHIP_BLOCK,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "weapon_rusty", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/weapon/rusty.png", SHIP_WEAPON,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "bullet_rusty", resource_group::LEVEL,
        "effect_shader",
        util::vec::Vector4(0.0f, 0.0f, 0.0f, 1.0f),
        "res/gfx/texture/level/ship/bullet/rusty.png", BULLET,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "engine_rusty", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/engine/rusty.png", SHIP_ENGINE,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addMaterialGeometryMesh(
        "trail_rusty", resource_group::LEVEL,
        "engine_trail_shader",
        util::vec::Vector4(1.0f, 1.0f, 0.0f, 1.0f),
        "res/gfx/geometry/level/engine_trail.obj", ENGINE_TRAIL
    );
    // STEEL
    omi::ResourceManager::addTextureMaterialSprite(
        "block_steel", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/block/steel.png", SHIP_BLOCK,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "weapon_steel", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/weapon/steel.png", SHIP_WEAPON,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "bullet_steel", resource_group::LEVEL,
        "effect_shader",
        util::vec::Vector4(0.0f, 0.0f, 0.0f, 1.0f),
        "res/gfx/texture/level/ship/bullet/steel.png", BULLET,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "engine_steel", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/engine/steel.png", SHIP_ENGINE,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addMaterialGeometryMesh(
        "trail_steel", resource_group::LEVEL,
        "engine_trail_shader",
        util::vec::Vector4(1.0f, 0.5f, 0.0f, 1.0f),
        "res/gfx/geometry/level/engine_trail.obj", ENGINE_TRAIL
    );
    // STEEL
    omi::ResourceManager::addTextureMaterialSprite(
        "block_copper", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/block/copper.png", SHIP_BLOCK,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "weapon_copper", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/weapon/copper.png", SHIP_WEAPON,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "bullet_copper", resource_group::LEVEL,
        "effect_shader",
        util::vec::Vector4(0.0f, 0.0f, 0.0f, 1.0f),
        "res/gfx/texture/level/ship/bullet/copper.png", BULLET,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "engine_copper", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/engine/copper.png", SHIP_ENGINE,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addMaterialGeometryMesh(
        "trail_copper", resource_group::LEVEL,
        "engine_trail_shader",
        util::vec::Vector4(0.0f, 1.0f, 0.5f, 1.0f),
        "res/gfx/geometry/level/engine_trail.obj", ENGINE_TRAIL
    );

    //FX
    omi::ResourceManager::addTextureMaterialSprite(
        "bullet_explosion_1", resource_group::LEVEL,
        "effect_shader",
        util::vec::Vector4(1.0f, 1.0f, 0.0f, 1.0f),
        "res/gfx/texture/level/fx/bullet_explosion_1/explosion.png",
        60, false, 1, 19, BULLET_EXPLOSION,
        util::vec::Vector2(2.0, 2.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "bullet_explosion_2", resource_group::LEVEL,
        "effect_shader",
        util::vec::Vector4(0.0f, 0.75f, 1.0f, 1.0f),
        "res/gfx/texture/level/fx/bullet_explosion_1/explosion.png",
        60, false, 1, 19, BULLET_EXPLOSION,
        util::vec::Vector2(2.0, 2.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    omi::ResourceManager::addTextureMaterialSprite(
        "block_explosion_1", resource_group::LEVEL,
        "effect_shader",
        util::vec::Vector4(0.0f, 0.0f, 0.0f, 1.0f),
        "res/gfx/texture/level/fx/block_explosion_1/explosion.png",
        60, false, 1, 19, BULLET_EXPLOSION,
        util::vec::Vector2(4.0, 4.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );

    //----------------------------------SOUNDS----------------------------------

    omi::ResourceManager::addSound(
        "bullet_rusty", resource_group::LEVEL,
        "res/sound/fx/level/rusty.ogg", 3
    );
    omi::ResourceManager::addSound(
        "bullet_steel", resource_group::LEVEL,
        "res/sound/fx/level/steel.ogg", 3
    );
    omi::ResourceManager::addSound(
        "bullet_copper", resource_group::LEVEL,
        "res/sound/fx/level/copper.ogg", 3
    );
}

} // namespace pack