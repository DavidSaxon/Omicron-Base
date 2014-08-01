#ifndef OMICRON_DISPLAY_WINDOW_H_
#   define OMICRON_DISPLAY_WINDOW_H_

#include <GL/glut.h>

#include "lib/Utilitron/MacroUtil.hpp"

class DisplaySettings;

#include "src/omicron/Omicron.hpp"

namespace omi {

/**************************************************************************\
| A display window which Omicron will render to. Currently only one active |
| window is supported.                                                     |
\**************************************************************************/
class Window {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(Window);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------
    /** Creates a new window
    #WARNING: currently only one active window is supported */
    Window();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Window();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Updates the window
    #NOTE: any changes to the window should be done through Omicron's display
    settings. This is a back end class that should only be used by Omicron */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the handle to the glut window
    GLuint m_window;
};

} // namespace omi

#endif
