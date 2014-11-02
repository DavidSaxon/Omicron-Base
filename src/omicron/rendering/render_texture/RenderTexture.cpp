#include "RenderTexture.hpp"

namespace omi {

namespace {

// TODO: variables titles

// the number of textures being rendered to
static const unsigned TEXTURE_COUNT = 2;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RenderTexture::RenderTexture()
    :
    m_frameBuffer      ( 0 ),
    m_depthRenderBuffer( 0 ),
    m_currentTexture   ( 0 )
{
    // initialise
    init();
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RenderTexture::bind()
{
    // if the resolution has changed rebuild the render texture
    if ( m_resolution != renderSettings.getResolution() )
    {
        init();
    }

    // bind the frame buffer
    glBindFramebuffer( GL_FRAMEBUFFER, m_frameBuffer );
    // switch the texture we're rendering to
    m_currentTexture = ( m_currentTexture + 1 ) % TEXTURE_COUNT;
    glFramebufferTexture2D(
        GL_FRAMEBUFFER,
        GL_COLOR_ATTACHMENT0,
        GL_TEXTURE_2D,
        m_texture[ m_currentTexture ],
        0
    );
    // bind teh depth buffer
    glBindRenderbuffer( GL_RENDERBUFFER, m_depthRenderBuffer );
    //redraw background colour
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
    // set the view port to the size of the render texture
    glViewport(
        0,
        0,
        renderSettings.getResolution().x,
        renderSettings.getResolution().y
    );
}

void RenderTexture::unbind()
{
    glBindFramebuffer ( GL_FRAMEBUFFER,  0 );
    glBindRenderbuffer( GL_RENDERBUFFER, 0 );
    glBindTexture     ( GL_TEXTURE_2D,   0 );
    // revert the view port to screen size
    glViewport(
        0,
        0,
        displaySettings.getSize().x,
        displaySettings.getSize().y
    );
}

void RenderTexture::render()
{
    // turn off depth testing
    glDisable( GL_DEPTH_TEST );

    //redraw background colour
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );

    // set up matrices
    float aspectRatio =
        displaySettings.getSize().x / displaySettings.getSize().y;
    glm::mat4 projection = glm::ortho(
        -aspectRatio, aspectRatio, -1.0f, 1.0f, 0.01f, 1000.0f );
    glm::mat4 view = glm::lookAt(
        glm::vec3( 0, 0, 1.0f ),
        glm::vec3( 0, 0, 0 ),
        glm::vec3( 0, 1, 0 )
    );
    view *= glm::translate( glm::vec3( 0.0f, 0.0f, 0.0f ) );
    glm::mat4 mvp = projection * view;

    // TODO: clean up into functions

    // Render the motion blur textures

    GLuint program = m_performanceMotionBlurShader.getProgram();
    // use the shader
    glUseProgram( program );

    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelViewProjectionMatrix" ),
        1, GL_FALSE, &mvp[0][0] );

    unsigned motionBlurIndex =
        ( m_currentTexture + 1 ) % TEXTURE_COUNT;
    glBindTexture( GL_TEXTURE_2D, m_texture[motionBlurIndex] );

    // draw geometry
    glBegin(GL_TRIANGLES);

        glTexCoord2f( 1.0f, 1.0f );
        glVertex3f(  aspectRatio,  1.0, 0.0f );

        glTexCoord2f( 0.0f, 1.0f );
        glVertex3f( -aspectRatio,  1.0, 0.0f );

        glTexCoord2f( 1.0f, 0.0f );
        glVertex3f(  aspectRatio, -1.0, 0.0f );

        glTexCoord2f( 0.0f, 0.0f );
        glVertex3f( -aspectRatio, -1.0, 0.0f );

        glTexCoord2f( 1.0f, 0.0f );
        glVertex3f(  aspectRatio, -1.0, 0.0f );

        glTexCoord2f( 0.0f, 1.0f );
        glVertex3f( -aspectRatio,  1.0, 0.0f );

    glEnd();

    glUseProgram( 0 );
    glBindTexture( GL_TEXTURE_2D, 0 );

    // Render the standard render texture

    // get the OpenGL program
    program = m_shader.getProgram();
    // use the shader
    glUseProgram( program );

    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelViewProjectionMatrix" ),
        1, GL_FALSE, &mvp[0][0] );

    glBindTexture( GL_TEXTURE_2D, m_texture[m_currentTexture] );

    // draw geometry
    glBegin(GL_TRIANGLES);

        glTexCoord2f( 1.0f, 1.0f );
        glVertex3f(  aspectRatio,  1.0, 0.0f );

        glTexCoord2f( 0.0f, 1.0f );
        glVertex3f( -aspectRatio,  1.0, 0.0f );

        glTexCoord2f( 1.0f, 0.0f );
        glVertex3f(  aspectRatio, -1.0, 0.0f );

        glTexCoord2f( 0.0f, 0.0f );
        glVertex3f( -aspectRatio, -1.0, 0.0f );

        glTexCoord2f( 1.0f, 0.0f );
        glVertex3f(  aspectRatio, -1.0, 0.0f );

        glTexCoord2f( 0.0f, 1.0f );
        glVertex3f( -aspectRatio,  1.0, 0.0f );

    glEnd();

    // clean up
    if ( renderSettings.getDepthTest() )
    {
        glEnable( GL_DEPTH_TEST  );
    }
    glUseProgram( 0 );
    glBindTexture( GL_TEXTURE_2D, 0 );
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RenderTexture::init()
{
    // store the resolution
    m_resolution = renderSettings.getResolution();

    // generate the frame buffer
    glGenFramebuffers( 1, &m_frameBuffer );
    glBindFramebuffer( GL_FRAMEBUFFER, m_frameBuffer );

    // set up the depth buufer
    glGenRenderbuffers( 1, &m_depthRenderBuffer );
    glBindRenderbuffer( GL_RENDERBUFFER, m_depthRenderBuffer );
    glRenderbufferStorage(
        GL_RENDERBUFFER,
        GL_DEPTH_COMPONENT,
        static_cast<GLsizei>( renderSettings.getResolution().x ),
        static_cast<GLsizei>( renderSettings.getResolution().y )
    );
    glFramebufferRenderbuffer(
        GL_FRAMEBUFFER,
        GL_DEPTH_ATTACHMENT,
        GL_RENDERBUFFER,
        m_depthRenderBuffer
    );

    // generate the textures we will render to
    glGenTextures( 2, &m_texture[0] );
    for ( unsigned i = 0; i < TEXTURE_COUNT; ++i )
    {
        initTextre( i );
    }

    // set up the frame buffer to render to our texture
    glFramebufferTexture2D(
        GL_FRAMEBUFFER,
        GL_COLOR_ATTACHMENT0,
        GL_TEXTURE_2D,
        m_texture[ m_currentTexture ],
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
    m_performanceMotionBlurShader = loader::loadShaderFromFiles(
        "res/gfx/shader/omicron/performance_motion_blur_vertex.glsl",
        "res/gfx/shader/omicron/performance_motion_blur_fragment.glsl"
    );

    // unbind
    glBindFramebuffer ( GL_FRAMEBUFFER,  0 );
    glBindRenderbuffer( GL_RENDERBUFFER, 0 );
    glBindTexture     ( GL_TEXTURE_2D,   0 );
}

void RenderTexture::initTextre( unsigned index )
{
    glBindTexture( GL_TEXTURE_2D, m_texture[index] );
    // create an empty texture
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGB,
        static_cast<GLsizei>( renderSettings.getResolution().x ),
        static_cast<GLsizei>( renderSettings.getResolution().y ),
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        0
    );
    // glTexImage2DMultisample(
    //     GL_TEXTURE_2D_MULTISAMPLE,
    //     3,
    //     GL_RGB,
    //     static_cast<GLsizei>( renderSettings.getResolution().x ),
    //     static_cast<GLsizei>( renderSettings.getResolution().y ),
    //     GL_TRUE
    // );
    // set texture parameters
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
}


} // namespace omi
