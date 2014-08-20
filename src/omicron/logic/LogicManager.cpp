#include  "LogicManager.hpp"

#include <iostream>

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LogicManager::LogicManager(Scene* initScene) :
    m_sceneInit(true),
    m_scene(initScene) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

LogicManager::~LogicManager() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool LogicManager::execute() {

    // initialise a new scene
    if (m_sceneInit) {

        m_scene->init();
        fpsManager.zero();
        m_sceneInit = false;
    }

    // update the fps manager
    fpsManager.update();

    // execute the current scene
    if (m_scene->execute()) {

        // get the next scene
        m_scene = std::unique_ptr<Scene>(m_scene->nextScene());
        //if the scene we get is null we're done
        if (!m_scene) {

            exit(0);
        }
        m_sceneInit = true;
        return true;
    }

    return false;
}

std::set<Component*>& LogicManager::getNewComponents() {

    return m_scene->newComponents;
}

std::vector<Component*>& LogicManager::getRemoveComponents() {

    return m_scene->removeComponents;
}

} // namespace omi
