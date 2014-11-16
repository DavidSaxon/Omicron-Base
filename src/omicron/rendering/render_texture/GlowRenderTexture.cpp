#include "GlowRenderTexture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

GlowRenderTexture::GlowRenderTexture() :
    RenderTexture(
        "res/gfx/shader/omicron/glow_render_texture_vertex.glsl",
        "res/gfx/shader/omicron/glow_render_texture_fragment.glsl"
    )
{
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GlowRenderTexture::shaderParameters( GLuint program )
{
    // do nothing
}

} // namespace omi
