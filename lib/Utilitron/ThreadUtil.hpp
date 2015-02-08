#ifndef UTILITRON_THREADUTIL_HPP_
#   define UTILITRON_THREADUTIL_HPP_

#include "lib/Utilitron/TypeUtil.hpp"

#ifdef OS_WINDOWS
#   include <windows.h>
#else
// TODO: linux includes
#endif

namespace util {

/****************************************\
| Utility functions relating to threads. |
\****************************************/
namespace thread {

/** Sets the priority of the current thread */
inline void setCurrentPriority( int priority )
{
#ifdef OS_WINDOWS
    // just to be safe this is working...
    if ( priority == 15 )
    {
        priority = THREAD_PRIORITY_TIME_CRITICAL;
    }
    else if ( priority == 0 )
    {
        priority = THREAD_PRIORITY_NORMAL;
    }

    SetThreadPriority( GetCurrentThread(), priority );
#else
    // TODO:
#endif
}

} // namespace thread

} // namespace util

#endif
