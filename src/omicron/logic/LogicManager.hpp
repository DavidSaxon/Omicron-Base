#ifndef OMICRON_LOGIC_LOGICMANAGER_H_
#   define OMICRON_LOGIC_LOGICMANAGER_H_

#include <memory>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/logic/scene/Scene.hpp"

class FPSManager;

#include "src/omicron/Omicron.hpp"

namespace omi {

/**********************************************************************\
| Handles the FPS manager, the execution of the current scene, and the |
| changing of scenes.                                                  |
\**********************************************************************/
class LogicManager {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(LogicManager);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Creates a new Logic Manager
    @param initScene the initial scene to begin executing*/
    LogicManager(Scene* initScene);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~LogicManager();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Perfroms an execution cycle of logic*/
    void execute();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //the current scene
    std::unique_ptr<Scene> m_scene;
};

} //namespace omi

#endif
