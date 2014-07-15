#ifndef OMICRON_LOGIC_LOGICMANAGER_H_
#   define OMICRON_LOGIC_LOGICMANAGER_H_

#include "lib/Utilitron/MacroUtil.hpp"

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
    
    /**Creates a new Logic Manager*/
    LogicManager();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~LogicManager();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Perfroms an execution cycle of logic*/
    void execute();
};

} //namespace omi

#endif