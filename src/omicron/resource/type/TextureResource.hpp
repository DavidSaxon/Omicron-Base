#ifndef OMICRON_RESOURCE_TYPE_TEXTURERESOURCE_H_
#   define OMICRON_RESOURCE_TYPE_TEXTURERESOURCE_H_

#include <memory>

#include "src/omicron/rendering/shading/Texture.hpp"
#include "src/omicron/resource/type/Resource.hpp"

namespace omi {

/*********************************************\
| Contains the needed data to load a texture. |
\*********************************************/
class TextureResource : public Resource {
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

    /** #Override */
    void load();

    /** #Override */
    void release();

    /** @return the loaded texture */
    Texture* get() const;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the file path to load the texture from
    std::string m_filePath;

    // the omicron texture
    std::unique_ptr<Texture> m_texture;
};

} // namespace omi

#endif