#ifndef OMICRON_RESOURCE_TYPE_TEXTURERESOURCE_H_
#   define OMICRON_RESOURCE_TYPE_TEXTURERESOURCE_H_

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/rendering/shading/Texture.hpp"
#include "src/omicron/resource/loader/Loaders.hpp"
#include "src/override/ResourceGroups.hpp"

namespace omi {

/*********************************************\
| Contains the needed data to load a texture. |
\*********************************************/
class TextureResource {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(TextureResource);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new texture resource
    @param resourceGroup the resource group of the texture
    @param filePath the path to the image file to use for the texture */
    TextureResource(      resource_group::ResourceGroup resourceGroup,
                    const std::string&                  filePath);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~TextureResource();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Loads the texture */
    void load();

    /** Releases the texture */
    void release();

    /** @return the loaded texture */
    Texture get() const;

    /** @return the resource group the texture is in */
    resource_group::ResourceGroup getGroup() const;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // true once the texture has been loaded
    bool m_loaded;
    // the resource group of the texture
    resource_group::ResourceGroup m_resourceGroup;
    // the file path to load the texture from
    std::string m_filePath;

    // the omicron texture
    Texture m_texture;
};

} // namespace omi

#endif