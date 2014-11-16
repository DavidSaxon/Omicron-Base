#include "FinalRenderTexture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

FinalRenderTexture::FinalRenderTexture() :
    RenderTexture(
        "res/gfx/shader/omicron/render_texture_vertex.glsl",
        "res/gfx/shader/omicron/render_texture_fragment.glsl"
    )
{
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void FinalRenderTexture::shaderParameters( GLuint program )
{
    float randMul = static_cast<float>( rand() % 1000 ) / 100.0f;
    glUniform1f(
        glGetUniformLocation( program, "u_randMul" ), randMul );
}

} // namespace omi
