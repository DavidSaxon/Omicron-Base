#include "ResourceManager.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

t_ResourceMap ResourceManager::m_resources;

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------


//--------------------------------LOAD FUNCTIONS--------------------------------


void ResourceManager::load(resource_group::ResourceGroup resourceGroup) {

    for (unsigned i = 0; i < m_resources.size(); ++i) {

        for (t_ResourceGroup::iterator it =  m_resources[i].begin();
                                       it != m_resources[i].end()  ;
                                     ++it                        ) {
            // check the resource group
            if (it->second->getGroup() == resourceGroup) {
                // load
                it->second->load();
            }
        }
    }
}


//--------------------------------GET FUNCTIONS---------------------------------


Shader ResourceManager::getShader(const std::string& id) {

    // create the shaders group if we need to
    createGroup(SHADER);

    // check if the shader is in the map
    if (m_resources[SHADER].find(id) == m_resources[SHADER].end()) {

        std::cout << "unable to find shader in resource manager" << std::endl;

        // TODO: throw an exception
    }

    // cast the resource and return
    return dynamic_cast<ShaderResource*>(
            m_resources[SHADER][id].get())->get();
}

Texture ResourceManager::getTexture(const std::string& id) {

    // create the textures group if we need to
    createGroup(TEXTURE);

    // check if the texture is in the map
    if (m_resources[TEXTURE].find(id) == m_resources[TEXTURE].end()) {

        std::cout << "unable to find texture in resource manager" << std::endl;

        // TODO: throw an exception
    }

    // cast the resource and return
    return dynamic_cast<TextureResource*>(
            m_resources[TEXTURE][id].get())->get();
}

Material ResourceManager::getMaterial(const std::string& id) {

    // create the materials group if we need to
    createGroup(MATERIAL);

    // check if the material is in the map
    if (m_resources[MATERIAL].find(id) == m_resources[MATERIAL].end()) {

        std::cout << "unable to find material in resource manager" << std::endl;

        // TODO: throw an exception
    }

    // cast the resource and return
    return dynamic_cast<MaterialResource*>(
            m_resources[MATERIAL][id].get())->get();
}

Geometry* ResourceManager::getGeometry(const std::string& id) {

    // create the geometry group if we need to
    createGroup(GEOMETRY);

    // check if the geometry is in the map
    if (m_resources[GEOMETRY].find(id) == m_resources[GEOMETRY].end()) {

        std::cout << "unable to find geometry in resource manager" << std::endl;

        // TODO: throw an exception
    }

    // cast the resource and return
    return dynamic_cast<GeometryResource*>(
            m_resources[GEOMETRY][id].get())->get();
}

Mesh* ResourceManager::getMesh(const std::string& id,
                              const std::string& componentId,
                                    Transform*   transform) {

    // create the mesh group if we need to
    createGroup(MESH);

    // check if the mesh is in the map
    if (m_resources[MESH].find(id) == m_resources[MESH].end()) {

        std::cout << "unable to find mesh in resource manager" << std::endl;

        // TODO: throw an exception
    }

    // cast the resource and return
    return dynamic_cast<MeshResource*>(
            m_resources[MESH][id].get())->get(componentId, transform);
}


//--------------------------------ADD FUNCTIONS---------------------------------


void ResourceManager::addShader(
        const std::string&                  id,
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  vertexPath,
        const std::string&                  fragmentShader) {

    // create the shaders group if we need to
    createGroup(SHADER);

    // insert in to the map
    m_resources[SHADER].insert(
        std::make_pair(
            id,
            t_ResourcePtr(new ShaderResource(
                resourceGroup,
                vertexPath,
                fragmentShader
            ))
        )
    );
}

void ResourceManager::addTexture(
        const std::string&                  id,
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  filePath) {

    // create the textures group if we need to
    createGroup(TEXTURE);

    // insert in to the map
    m_resources[TEXTURE].insert(std::make_pair(id,
        t_ResourcePtr(new TextureResource(resourceGroup, filePath))));
}

void ResourceManager::addMaterial(
    const std::string&                  id,
          resource_group::ResourceGroup resourceGroup,
    const std::string&                  shader,
    const util::vec::Vector4&           colour,
    const std::string&                  texture) {

    // create the materials group if we need to
    createGroup(MATERIAL);

    // insert in to the map
    m_resources[MATERIAL].insert(
        std::make_pair(
            id,
            t_ResourcePtr(new MaterialResource(
                resourceGroup,
                shader,
                colour,
                texture
            ))
        )
    );
}

void ResourceManager::addMaterial(
    const std::string&                  id,
          resource_group::ResourceGroup resourceGroup,
    const std::string&                  shader,
    const std::string&                  texture) {

    // create the materials group if we need to
    createGroup(MATERIAL);

    // insert in to the map
    m_resources[MATERIAL].insert(
        std::make_pair(
            id,
            t_ResourcePtr(new MaterialResource(
                resourceGroup,
                shader,
                util::vec::Vector4(1.0f, 1.0f, 1.0f, 1.0f),
                texture
            ))
        )
    );
}

void ResourceManager::addMaterial(
    const std::string&                  id,
          resource_group::ResourceGroup resourceGroup,
    const std::string&                  shader,
    const util::vec::Vector4&           colour) {

    // create the materials group if we need to
    createGroup(MATERIAL);

    // insert in to the map
    m_resources[MATERIAL].insert(
        std::make_pair(
            id,
            t_ResourcePtr(new MaterialResource(
                resourceGroup,
                shader,
                colour,
                ""
            ))
        )
    );
}

void ResourceManager::addGeometry(
    const std::string&                  id,
          resource_group::ResourceGroup resourceGroup,
    const std::string&                  filePath) {

    // create the geometry group if we need to
    createGroup(GEOMETRY);

    // insert in to the map
    m_resources[GEOMETRY].insert(
        std::make_pair(
            id,
            t_ResourcePtr(new GeometryResource(
                resourceGroup,
                filePath
            ))
        )
    );
}

void ResourceManager::addMesh(
    const std::string&                  id,
          resource_group::ResourceGroup resourceGroup,
          int                           layer,
    const std::string&                  geometry,
    const std::string&                  material) {

    // create the mesh group if we need to
    createGroup(MESH);

    // insert in to the map
    m_resources[MESH].insert(
        std::make_pair(
            id,
            t_ResourcePtr(new MeshResource(
                resourceGroup,
                layer,
                geometry,
                material
            ))
        )
    );
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void ResourceManager::createGroup(ResourceType type) {

    // look for the group
    if (m_resources.find(type) == m_resources.end()) {

        // create the group
        m_resources.insert(std::make_pair(type, t_ResourceGroup()));
    }
}

} // namespace omi
