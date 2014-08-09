#include "TextureResource.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TextureResource::TextureResource(
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  filePath)
    :
    Resource  (resourceGroup),
    m_filePath(filePath)       {        
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TextureResource::~TextureResource() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TextureResource::load() {

    if (!m_loaded) {

        m_texture = loader::textureFromImage(m_filePath);
        m_loaded = true;
    }
}

void TextureResource::release() {

    if (m_loaded) {

        GLuint id = m_texture.getId();
        glDeleteTextures(1, &id);
        m_texture = Texture();
        m_loaded = false;
    }
}

Texture TextureResource::get() const {

    if (!m_loaded) {

        std::cout << "attempted to get unloaded texture" << std::endl;

        //TODO: throw an exception
    }

    return m_texture;
}

} // namespace omi