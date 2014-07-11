#include "Window.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Window::Window() {

    //TODO; stuff like accum and stencil buffer are enabled here?
    //initialise the windows display mode
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    //set up the window
    glutInitWindowSize(
        displaySettings.getSize().x,
        displaySettings.getSize().y);

    glutInitWindowPosition(
        displaySettings.getPos().x,
        displaySettings.getPos().y);

    if (displaySettings.getFullscreen()) {

        glutFullScreen();
    }

    //create the window
    m_window = glutCreateWindow(displaySettings.getTitle().c_str());
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Window::~Window() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Window::update() {

    //check if there has been a change in settings
    if (displaySettings.check()) {

        glutReshapeWindow(displaySettings.getSize().x,
            displaySettings.getSize().y);

        glutPositionWindow(displaySettings.getPos().x,
            displaySettings.getPos().y);

        //TODO: how to exit fullscreen
        if (displaySettings.getFullscreen()) {

            glutFullScreen();
        }

        glutSetWindowTitle(displaySettings.getTitle().c_str());
    }
}

} //namespace omi