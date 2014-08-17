#include "Renderer.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Renderer::Renderer() {

    // initialise
    init();
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Renderer::~Renderer() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Renderer::render() {

    // update any settings that have changed
    applySettings();

    // clear the window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // m_rot += 0.5f * fpsManager.getTimeScale();

    // TODO: replace with camera (is a camera a type of entity??)
    glTranslatef(0.0f, 0.0f, -10.0f);
    glRotatef(25.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(m_rot, 0.0f, 1.0f, 0.0f);

    // render the render lists
    m_renderLists->render();

    // swap the buffers
    glutSwapBuffers();
}

void Renderer::addRenderable(Renderable* renderable) {

    m_renderLists->addRenderable(renderable);
}

void Renderer::removeRenderable(Renderable* renderable) {

    m_renderLists->removeRenderable(renderable);
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Renderer::applySettings() {

    if (renderSettings.check()) {

        // depth test
        renderSettings.getDepthTest() ?
            glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
        // back face culling
        renderSettings.getBackFaceCulling() ?
            glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);

        glClearColor(
            renderSettings.getClearColour().r,
            renderSettings.getClearColour().g,
            renderSettings.getClearColour().b,
            renderSettings.getClearColour().a);
    }
}

void Renderer::init() {

    // apply the render settings
    applySettings();

    // apply non changeable settings
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glCullFace(GL_BACK);
    glClearDepth(1.0f);
    glEnable(GL_TEXTURE_2D);

    // TODO: move this to camera
    // switch to the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f,
        displaySettings.getSize().x / displaySettings.getSize().y,
        0.001f, 1000.0f);
    // revert to the model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // initialise DevIL
    ilInit();

    // create the render lists
    m_renderLists = std::unique_ptr<RenderLists>(new RenderLists());
}

} // namespace omi
