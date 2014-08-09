#include "ResourceManager.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

ResourceManager::ResourceManager() {

    // TODO: initialise resource packs
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

ResourceManager::~ResourceManager() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------


//--------------------------------LOAD FUNCTIONS--------------------------------


void ResourceManager::load(resource_group::ResourceGroup) {

    // TODO:
}


//--------------------------------GET FUNCTIONS---------------------------------


Texture ResourceManager::getTexture(const std::string& id) {

    // check if the texture is in the map

    return m_textures[id]->get();
}


//--------------------------------ADD FUNCTIONS---------------------------------


void ResourceManager::addTexture(
        const std::string&                  id,
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  filePath) {


}

} // namespace omi