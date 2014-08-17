#include  "LogicManager.hpp"

#include <iostream>

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LogicManager::LogicManager(Scene* initScene) :
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

void LogicManager::execute() {

    // update the fps manager
    fpsManager.update();

    // execute the current scene
    if (m_scene->execute()) {

        // get the next scene
        m_scene = std::unique_ptr<Scene>(m_scene->nextScene());
        // initialise the next scene
        m_scene->init();
        // zero the fps manager
        fpsManager.zero();
    }
}

std::set<Component*>& LogicManager::getDirtyComponents() {

    return m_scene->dirtyComponents;
}

std::vector<Component*>& LogicManager::getRemoveComponents() {

    return m_scene->removeComponents;
}

} // namespace omi
