#ifndef OMICRON_LOGIC_FPS_MANAGER_FPSMANAGER_H_
#   define OMICRON_LOGIC_FPS_MANAGER_FPSMANAGER_H_

#include <boost/date_time/date.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "lib/Utilitron/MacroUtil.hpp"

namespace omi {

/**************************************************************************\
| Records the current FPS and provides a time scale to apply to time-based |
| scene evolution.                                                         |
\**************************************************************************/
class FPSManager {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(FPSManager);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Creates a new FPSManager*/
    FPSManager();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~FPSManager();

};

} //namespace omi

#endif
