#include  "LogicManager.hpp"

#include <iostream>

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LogicManager::LogicManager() {
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

    //update the fps manager
    fpsManager.update();

    std::cout << fpsManager.getTimeScale() << std::endl;
}

} //namespace omi