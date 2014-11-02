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

    // the ids of the texture to render to
    GLuint m_texture[2];
    // the texture currently begin rendered to
    unsigned m_currentTexture;

    // the shader to render with
    Shader m_shader;
    // the shader to render performance motion blur with
    Shader m_performanceMotionBlurShader;
    // the current resolution of the texture
    glm::vec2 m_resolution;

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Initialises this render texture */
    void init();

    /** Sets up a texture for rendering to
    @ param index the index of the texture */
    void initTextre( unsigned index ); 
};

} // namespace omi

#endif
