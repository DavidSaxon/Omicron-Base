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

        m_texture = std::unique_ptr<Texture>(
            loader::textureFromImage(m_filePath));
        m_loaded = true;
    }
}

void TextureResource::release() {

    if (m_loaded) {

        GLuint id = m_texture->getId();
        glDeleteTextures(1, &id);
        m_texture = std::unique_ptr<Texture>();
        m_loaded = false;
    }
}

Texture* TextureResource::get() const {

    if (!m_loaded) {

        std::cout << "attempted to get unloaded texture" << std::endl;

        //TODO: throw an exception
    }

    //copy the texture based on type
    Texture* tex;
    if (m_texture->getType() == tex::ANIMATION) {

        tex = new Animation(*dynamic_cast<Animation*>(m_texture.get()));
    }
    else {

        tex = new Texture(*m_texture.get());
    }

    return tex;
}

} // namespace omi