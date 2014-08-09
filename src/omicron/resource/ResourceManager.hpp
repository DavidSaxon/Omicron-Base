#ifndef OMICRON_RESOURCE_RESOURCEMANAGER_H_
#   define OMICRON_RESOURCE_RESOURCEMANAGER_H_

#include <map>
#include <memory>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/resource/type/Resource.hpp"
#include "src/omicron/resource/type/ShaderResource.hpp"
#include "src/omicron/resource/type/TextureResource.hpp"
#include "src/override/ResourceGroups.hpp"

namespace omi {

//--------------------------------------------------------------------------
//                              TYPE DEFINITIONS
//--------------------------------------------------------------------------

typedef std::unique_ptr<Resource>            t_ResourcePtr;
typedef std::map<std::string, t_ResourcePtr> t_ResourceGroup;
typedef std::map<int, t_ResourceGroup>       t_ResourceMap;

/***********************************************************************\
| The resource manager stores, loads, and provides access to resources. |
\***********************************************************************/
class ResourceManager {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    //DISALLOW_CONSTRUCTION(ResourceManager);

    //--------------------------------------------------------------------------
    //                                ENUMERATORS
    //--------------------------------------------------------------------------

    //! the types of resources
    enum ResourceType {

        SHADER,
        TEXTURE,
        MATERIAL,
        MESH,
        SPRITE
    };

public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------


    //------------------------------LOAD FUNCTIONS------------------------------


    /** Loads the resources within the given group
    #NOTE: this function will only return once all resources are loaded */
    static void load(resource_group::ResourceGroup resourceGroup);


    //------------------------------GET FUNCTIONS-------------------------------


    /** Gets the shader resource with the given identifier if it exists 
    @param id the identifier of the shader
    @return the requested shader */
    static Shader getShader(const std::string& id);

    /** Gets the texture resource with the given identifier if it exists
    @param id the identifier of the texture
    @return the requested texture */
    static Texture getTexture(const std::string& id);


    //------------------------------ADD FUNCTIONS-------------------------------


    /** Adds a shader to the resource map
    @param id the identifier of the shader resource
    @param resourceGroup the resource group of the shader
    @param vertexPath the path to the vertex shader
    @param fragmentPath the path to the fragment shader */
    static void addShader(
            const std::string&                  id,
                  resource_group::ResourceGroup resourceGroup,
            const std::string&                  vertexPath,
            const std::string&                  fragmentShader);


    /** Adds a texture to the resource map
    @param id the identifier of the texture resource
    @param resourceGroup the resource group of the texture
    @param filePath the image file to load the texture from */
    static void addTexture(
        const std::string&                  id,
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  filePath);


private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the map of all resources
    static t_ResourceMap m_resources;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Checks if a resource type group exists in the map, if not create it
    @param type the resource type to check if it exists*/
    static void createGroup(ResourceType type);
};

} // namespace omi

#endif
