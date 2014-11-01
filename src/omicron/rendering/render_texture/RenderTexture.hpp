#ifndef OMICRON_RENDERING_RENDER_TEXTURE_RENDERTEXTURE_HPP_
#   define OMICRON_RENDERING_RENDER_TEXTURE_RENDERTEXTURE_HPP_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include <iostream>
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include "lib/glm/glm.hpp"
#include "lib/glm/gtx/transform.hpp"

#include "lib/Utilitron/MathUtil.hpp"

#include "src/omicron/Omicron.hpp"
#include "src/omicron/resource/loader/Loaders.hpp"

namespace omi {

class RenderTexture {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Super constructor */
    RenderTexture();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Binds this as the texture to render to */
    void bind();

    /** Reverts OpenGL to default to-screen rendering */
    void unbind();

    /** Renders this texture to a quad in front of the screen */
    void render();

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the id of the frame buffer being rendered to
    GLuint m_frameBuffer;
    // the depth buffer
    GLuint m_depthRenderBuffer;
    // the id of the texture to render to
    GLuint m_texture;

    // the shader to render with
    Shader m_shader;

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Initialises this render texture */
    void init();
};

} // namespace omi

#endif
