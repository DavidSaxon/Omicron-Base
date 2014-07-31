#include  "LogicManager.hpp"

#include <iostream>

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LogicManager::LogicManager(Scene* initScene) :
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

void LogicManager::execute() {

    // update the fps manager
    fpsManager.update();

    // execute the current scene
    if (m_scene->execute()) {

        // get the next scene
        m_scene = std::unique_ptr<Scene>(m_scene->nextScene());
        // zero the fps manager
        fpsManager.zero();
    }
}

} // namespace omi
