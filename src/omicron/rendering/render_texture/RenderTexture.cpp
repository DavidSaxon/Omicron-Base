#include "RenderTexture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RenderTexture::RenderTexture()
    :
    m_frameBuffer      ( 0 ),
    m_depthRenderBuffer( 0 ),
    m_texture          ( 0 )
{
    // initialise
    init();
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RenderTexture::bind()
{
    // bind the frame buffer
    glBindFramebuffer( GL_FRAMEBUFFER, m_frameBuffer );
    // bind teh depth buffer
    glBindRenderbuffer( GL_RENDERBUFFER, m_depthRenderBuffer );
    //redraw background colour
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
}

void RenderTexture::render()
{
    // TODO: move this out ?
    //redraw background colour
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );

    // set up matrices
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RenderTexture::init()
{
    // generate the frame buffer
    glGenFramebuffers( 1, &m_frameBuffer );
    glBindFramebuffer( GL_FRAMEBUFFER, m_frameBuffer );

    // set up the depth buufer
    glGenRenderbuffers( 1, &m_depthRenderBuffer );
    glBindRenderbuffer( GL_RENDERBUFFER, m_depthRenderBuffer );
    glRenderbufferStorage(
        GL_RENDERBUFFER,
        GL_DEPTH_COMPONENT,
        static_cast<GLsizei>( displaySettings.getSize().x ),
        static_cast<GLsizei>( displaySettings.getSize().y )
    );
    glFramebufferRenderbuffer(
        GL_FRAMEBUFFER,
        GL_DEPTH_ATTACHMENT,
        GL_RENDERBUFFER,
        m_depthRenderBuffer
    );

    // generate the texture we will render to
    glGenTextures( 1, &m_texture );
    glBindTexture( GL_TEXTURE_2D, m_texture );
    // create an empty texture
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGB,
        static_cast<GLsizei>( displaySettings.getSize().x ),
        static_cast<GLsizei>( displaySettings.getSize().y ),
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        0
    );
    // set texture parameters
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

    // set up the frame buffer to render to our texture
    glFramebufferTexture2D(
        GL_FRAMEBUFFER,
        GL_COLOR_ATTACHMENT0,
        GL_TEXTURE_2D,
        m_texture,
        0
    );
    // TODO: do we need this??
    GLenum drawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers( 1, drawBuffers );

    // load shaders for the render texture
    m_shader = loader::loadShaderFromFiles(
        "res/gfx/shader/omicron/render_texture_vertex.glsl",
        "res/gfx/shader/omicron/render_texture_fragment.glsl"
    );

    // unbind
    glBindFramebuffer ( GL_FRAMEBUFFER,  0 );
    glBindRenderbuffer( GL_RENDERBUFFER, 0 );
    glBindTexture     ( GL_TEXTURE_2D,   0 );
}

} // namespace omi
