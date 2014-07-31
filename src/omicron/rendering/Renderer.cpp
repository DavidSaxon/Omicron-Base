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

    // TODO: replace with camera (is a camera a type of entity??)
    glTranslatef(0.0f, 0.0f, -4.0f);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
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

    // TODO: move this to camera
    // switch to the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f,
        displaySettings.getSize().x / displaySettings.getSize().y,
        0.001f, 1000.0f);
    // revert to the model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

} // namespace omi
