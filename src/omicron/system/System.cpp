#include <iostream>
#include <memory>

#include <GL/glut.h>

#include "lib/Utilitron/Vector.hpp"

#include "src/omicron/graphics/display/Window.hpp"
#include "src/omicron/graphics/renderer/Renderer.hpp"
#include "src/override/start_up/StartUp.hpp"

namespace omi {

namespace {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

//the window
std::unique_ptr<Window> window;
//the renderer
std::unique_ptr<Renderer> renderer;
//TODO: the logic manager

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/**The main loop function of Omicron, controls callback to the rest of the
engine*/
void execute() {

    //update the window
    window->update();

    //render
    renderer->render();

    //swap buffers and request call back
    //TODO: renderer should swap buffers??
    glutSwapBuffers();
    glutPostRedisplay();
}

/**Sets up Omicron*/
void init() {

    //initialise glut
    int ac = 1;
    char* av[1] = {(char*) "Omicron"};
    glutInit(&ac, av);

    //run the start up script
    //TODO: get scene from start up
    start_up::init();

    //create the window
    window = std::unique_ptr<Window>(new Window());

    //create the renderer
    renderer = std::unique_ptr<Renderer>(new Renderer());

    //fps manager?

    //logic manager

    //set the call back function of the glut main loop
    glutDisplayFunc(execute);
}

/**Begins Omicron*/
void begin() {

    //start the glut main loop
    glutMainLoop();
}

} //namespace anonymous

} //namespace omi

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

int main(int argc, char** argv) {

    //TODO: parse arguments

    //set up
    omi::init();

    //begin
    omi::begin();

    //will never be reached
    return 0;
}
