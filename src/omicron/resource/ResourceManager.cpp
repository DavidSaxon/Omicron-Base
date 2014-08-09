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

    // iterate over all resources
    for (t_ResourceMap::iterator it =  m_resources.begin();
                                 it != m_resources.end()  ;
                               ++it                        ) {

        for (t_ResourceGroup::iterator itg =  it->second.begin();
                                       itg != it->second.end()  ;
                                     ++itg                        ) {

            // check the resource group
            if (itg->second->getGroup() == resourceGroup) {

                // load
                itg->second->load();
            }
        }
    }
}


//--------------------------------GET FUNCTIONS---------------------------------


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


//--------------------------------ADD FUNCTIONS---------------------------------


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
