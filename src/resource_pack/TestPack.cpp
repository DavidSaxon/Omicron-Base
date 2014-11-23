#include "Packs.hpp"

namespace pack {

void buildTestPack()
{
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_skybox", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/skybox.png",
        "res/gfx/geometry/test/skybox.obj",
        0, 0,
        omi::material::SHADELESS
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_floor_1", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/floor_1.png",
        "res/gfx/geometry/test/floor_1.obj",
        1
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_tunnel_1", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/wall_1.png",
        "res/gfx/geometry/test/tunnel_1.obj",
        1
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_tunnel_pipe_1", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/pipe_1.png",
        "res/gfx/geometry/test/tunnel_pipe_1.obj",
        1
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_tunnel_pipe_holder_1", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/pipe_holder_1.png",
        "res/gfx/geometry/test/tunnel_pipe_holder_1.obj",
        1
    );
    omi::ResourceManager::addMaterialGeometryMesh(
        "test_tunnel_light_bulb_1", resource_group::TEST,
        "default_shader",
        glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f ),
        "res/gfx/geometry/test/light_bulb_1.obj",
        1,
        omi::material::SHADELESS
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_tunnel_light_socket_1", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/light_socket_1.png",
        "res/gfx/geometry/test/light_socket_1.obj",
        1
    );
    omi::ResourceManager::addMaterialGeometryMesh(
        "test_monkey", resource_group::TEST,
        "default_shader",
        glm::vec4( 1.0f, 0.0f, 0.0f, 1.0f ),
        "res/gfx/geometry/test/monkey.obj",
        2
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_human", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/human.png",
        "res/gfx/geometry/test/human.obj",
        2
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "glow_cube", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/glow_cube.png",
        "res/gfx/geometry/test/glow_cube.obj",
        2, 0, omi::material::SHADELESS
    );
}

} // namespace pack
