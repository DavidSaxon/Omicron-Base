// #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <GL/glew.h>

#include <iostream>
#include <memory>
#include <stdlib.h>
#include <time.h>

#include "lib/Utilitron/Vector.hpp"

#include "src/omicron/display/Window.hpp"
#include "src/omicron/input/Input.hpp"
#include "src/omicron/logic/LogicManager.hpp"
#include "src/omicron/physics/collision_detect/CollisionDetect.hpp"
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
        if ((*it)->getType() & component::UPDATABLE) {

            // pass to logic manager
            logicManager->removeUpdatable(dynamic_cast<Updatable*>(*it));
        }
        else if ((*it)->getType() & component::RENDERABLE) {

            // pass on to the renderer
            renderer->removeRenderable(dynamic_cast<Renderable*>(*it));
        }
        else if ((*it)->getType() & component::CAMERA) {

                // pass on to the renderer
                renderer->removeCamera(dynamic_cast<Camera*>(*it));
        }
        else if ((*it)->getType() & component::PHYSICS) {

            // TODO:
        }
        else if ((*it)->getType() & component::COLLISION) {

            CollisionDetect::removeDetector(
                dynamic_cast<CollisionDetector*>(*it));
        }
    }

    // sort the new components
    for (std::set<Component*>::iterator it =
        logicManager->getNewComponents().begin();
        it != logicManager->getNewComponents().end(); ++it) {

        // sort the component based on its type
        if ((*it)->getType() & component::UPDATABLE) {

            // pass to logic manager
            logicManager->addUpdatable(dynamic_cast<Updatable*>(*it));
        }
        else if ((*it)->getType() & component::RENDERABLE) {

            // pass on to the renderer
            renderer->addRenderable(dynamic_cast<Renderable*>(*it));
        }
        else if ((*it)->getType() & component::CAMERA) {

                // pass on to the renderer
                renderer->setCamera(dynamic_cast<Camera*>(*it));
        }
        else if ((*it)->getType() & component::PHYSICS) {

            // TODO:
        }
        else if ((*it)->getType() & component::COLLISION) {

            CollisionDetect::addDetector(
                dynamic_cast<CollisionDetector*>(*it));
        }
    }
}

/** The main loop function of Omicron, controls callback to the rest of the
engine */
void execute() {

    // update logic
    if (logicManager->execute()) {

        // clear components
        renderer->clear();
    }

    // lock the mouse if enabled
    if (systemSettings.isCursorLocked()) {

        sf::Mouse::setPosition(sf::Vector2i(
            static_cast<int>(systemSettings.getCursorLockedPos().x),
            static_cast<int>(systemSettings.getCursorLockedPos().y)));
    }

    // other system settings
    if (systemSettings.check()) {

        // hide or show the mouse
        window->setCursorVisble(!systemSettings.isCursorHidden());
    }

    // sort the new components that have added or removed this cycle
    sortComponents();

    // update collision detection
    CollisionDetect::update();

    // render
    renderer->render();

    // update the window
    window->update();
}

/** Sets up Omicron */
void init() {

    // seed random number generators
    srand(static_cast<unsigned>(time(NULL)));

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
    while (true) {

        omi::execute();
    }

    // will never be reached
    return 0;
}
