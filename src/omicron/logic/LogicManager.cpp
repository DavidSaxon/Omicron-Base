#include  "LogicManager.hpp"

#include <iostream>

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LogicManager::LogicManager(Scene* initScene) :
    m_sceneInit(false),
    m_scene(initScene) {

    // initialise the first scene
    m_scene->init();
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
