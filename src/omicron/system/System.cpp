// #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <GL/glew.h>

#include <iostream>
#include <memory>

#include "lib/Utilitron/Vector.hpp"

#include "src/omicron/display/Window.hpp"
#include "src/omicron/logic/LogicManager.hpp"
#include "src/omicron/rendering/Renderer.hpp"
#include "src/omicron/scene/Scene.hpp"
#include "src/override/StartUp.hpp"
#include "src/resource_pack/Packs.hpp"

namespace omi {

namespace {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the window
std::unique_ptr<Window> window;
// the renderer
std::unique_ptr<Renderer> renderer;
// the logic manager
std::unique_ptr<LogicManager> logicManager;

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/** Sorts components that have been created this execution cycle and reference
them to their appropriate managers */
void sortComponents() {

    //sort the components to be removed
    for (std::vector<Component*>::iterator it =
        logicManager->getRemoveComponents().begin();
        it != logicManager->getRemoveComponents().end(); ++it) {

        // sort the component based on its type
        switch ((*it)->getType()) {

            case component::UPDATEABLE: {

                // TODO:
                std::cout << "REMOVE UPDATEABLE" << std::endl;
                break;
            }
            case component::RENDERABLE: {

                // pass on to the renderer
                renderer->removeRenderable(dynamic_cast<Renderable*>(*it));
                break;
            }
            default: {

                // do nothing with simple components
                break;
            }
        }
    }

    // sort the new components
    for (std::set<Component*>::iterator it =
        logicManager->getNewComponents().begin();
        it != logicManager->getNewComponents().end(); ++it) {

        // sort the component based on its type
        switch ((*it)->getType()) {

            case component::UPDATEABLE: {

                // TODO:
                std::cout << "UPDATEABLE" << std::endl;
                break;
            }
            case component::RENDERABLE: {

                // pass on to the renderer
                renderer->addRenderable(dynamic_cast<Renderable*>(*it));
                break;
            }
            default: {

                // do nothing with simple components
                break;
            }
        }
    }
}

/** The main loop function of Omicron, controls callback to the rest of the
engine */
void execute() {

    // update the window
    window->update();

    // update logic
    logicManager->execute();

    // sort the new components that have added or removed this cycle
    sortComponents();

    // render
    renderer->render();

    // request call back
    glutPostRedisplay();
}

/** Sets up Omicron */
void init() {

    // initialise glut
    int ac = 1;
    char* av[1] = {(char*) "Omicron"};
    glutInit(&ac, av);

    // run the start up script and get the first scene from it
    Scene* initScene = start_up::init();

    // create the window
    window = std::unique_ptr<Window>(new Window());

    // create the renderer
    renderer = std::unique_ptr<Renderer>(new Renderer());

    // initialise glew
    glewInit();

    // build the resource packs
    pack::build();

    // create the logic manager
    logicManager = std::unique_ptr<LogicManager>(new LogicManager(initScene));

    // set the call back function of the glut main loop
    glutDisplayFunc(execute);
}

/** Begins Omicron */
void begin() {

    // start the glut main loop
    glutMainLoop();
}

} // namespace anonymous

} // namespace omi

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

int main(int argc, char** argv) {

    // TODO: parse arguments

    // set up
    omi::init();

    // begin
    omi::begin();

    // will never be reached
    return 0;
}
