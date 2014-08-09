#ifndef OMICRON_RESOURCE_RESOURCEMANAGER_H_
#   define OMICRON_RESOURCE_RESOURCEMANAGER_H_

#include <map>
#include <memory>

#include "src/omicron/resource/type/TextureResource.hpp"
#include "src/override/ResourceGroups.hpp"

namespace omi {

//-----------------------------------TYPEDEF------------------------------------

typedef std::unique_ptr<TextureResource> t_TextureResourcePtr;
typedef std::map<std::string, t_TextureResourcePtr> t_TextureMap;


/***********************************************************************\
| The resource manager stores, loads, and provides access to resources. |
\***********************************************************************/
class ResourceManager {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a resource manager */
    ResourceManager();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~ResourceManager();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------


    //------------------------------LOAD FUNCTIONS------------------------------


    /** Loads the resources within the given group
    #NOTE: this function will only return once all resources are loaded */
    void load(resource_group::ResourceGroup);


    //------------------------------GET FUNCTIONS-------------------------------


    /** Gets the texture resource with the given identifier if it exists
    @param id the identifier of the texture
    @return the requested texture */
    Texture getTexture(const std::string& id);


    //------------------------------ADD FUNCTIONS-------------------------------


    /** Adds a texture to the resource map
    @param id the identifier of the texture resource
    @param resourceGroup the resource group of the texture
    @param filePath the image file to load the texture from */
    void addTexture(const std::string&                  id,
                          resource_group::ResourceGroup resourceGroup,
                    const std::string&                  filePath);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // map from ids to textures
    t_TextureMap m_textures;

};

} // namespace omi

#endif
