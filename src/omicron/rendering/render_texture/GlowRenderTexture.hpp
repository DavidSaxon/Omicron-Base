#ifndef OMICRON_RENDERING_RENDER_TEXTURE_GLOWRENDERTEXTURE_HPP_
#   define OMICRON_RENDERING_RENDER_TEXTURE_GLOWRENDERTEXTURE_HPP_

#include "src/omicron/rendering/render_texture/RenderTexture.hpp"

namespace omi {

/***********************************************************************\
| Render texture that performs a glow pass on objects which have a glow |
| material.                                                             |
\***********************************************************************/
class GlowRenderTexture : public RenderTexture {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new glow texture */
    GlowRenderTexture();

protected:

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    virtual void shaderParameters( GLuint program );

};

} // namespace omi

#endif
