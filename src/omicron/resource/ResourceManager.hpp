#ifndef OMICRON_RESOURCE_RESOURCEMANAGER_H_
#   define OMICRON_RESOURCE_RESOURCEMANAGER_H_

#include <map>
#include <memory>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/component/renderable/Mesh.hpp"
#include "src/omicron/resource/type/GeometryResource.hpp"
#include "src/omicron/resource/type/MaterialResource.hpp"
#include "src/omicron/resource/type/MeshResource.hpp"
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
        GEOMETRY,
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


    /** Gets the shader with the given identifier if it exists
    @param id the identifier of the shader
    @return the requested shader */
    static Shader getShader(const std::string& id);

    /** Gets the texture with the given identifier if it exists
    @param id the identifier of the texture
    @return the requested texture */
    static Texture getTexture(const std::string& id);

    /** Gets the material with the given identifier if it exists
    @param id the identifier of the material
    @return the requested material */
    static Material getMaterial(const std::string& id);

    /** Gets the geometry with the given identifier if it exists
    @param id the identifier of the geometry
    @return the requested geometry */
    static Geometry* getGeometry(const std::string& id);

    /** Gets the mesh with the given identifier if it exists
    @param id the identifier of the mesh
    @param componentId the component identifier to use for the mesh
    @oaram transform the transform to use for the mesh
    @return the requested mesh */
    static Mesh* getMesh(const std::string& id,
                        const std::string& componentId,
                              Transform*   transform);


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

    /** Adds a material to the resource map
    @param id the identifier of the material resource
    @param resourceGroup the resource group of the material
    @param shader the resource id of the shader to use for the material
    @param colour the colour to use for the material
    @param texture the resource id of the texture to use for the material */
    static void addMaterial(
        const std::string&                  id,
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  shader,
        const util::vec::Vector4&           colour,
        const std::string&                  texture);

    /** Adds a material to the resource map using default white as the colour
    of the material
    @param id the identifier of the material resource
    @param resourceGroup the resource group of the material
    @param shader the resource id of the shader to use for the material
    @param texture the resource id of the texture to use for the material */
    static void addMaterial(
        const std::string&                  id,
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  shader,
        const std::string&                  texture);

    /** Adds a material with no texture to the resource map
    @param id the identifier of the material resource
    @param resourceGroup the resource group of the material
    @param shader the resource id of the shader to use for the material
    @param colour the colour to use for the material */
    static void addMaterial(
        const std::string&                  id,
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  shader,
        const util::vec::Vector4&           colour);

    /** Adds geometry to the resource map
    @param id the identifier of the geometry resource
    @param resourceGroup the resource group of the geometry
    @param filePath the image file to load the geometry from */
    static void addGeometry(
        const std::string&                  id,
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  filePath);

    /** Adds a mesh to the resource map
    @param id the identifier of the mesh resource
    @param resourceGroup the resource group of the mesh
    @param layer the layer of the mesh
    @param geometry the resource id of the meshes' geometry
    @param material the resource if of the meshes' material*/
    static void addMesh(
        const std::string&                  id,
              resource_group::ResourceGroup resourceGroup,
              int                           layer,
        const std::string&                  geometry,
        const std::string&                  material);

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
