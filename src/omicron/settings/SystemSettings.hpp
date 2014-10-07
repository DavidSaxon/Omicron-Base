#ifndef OMICRON_SETTINGS_SYSTEMSETTINGS_H_
#   define OMICRON_SETTINGS_SYSTEMSETTINGS_H_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include "lib/glm/glm.hpp"
#include "lib/Utilitron/MacroUtil.hpp"

namespace omi {

/****************************************************************************\
| An object that contains all system related settings controlled by Omicron. |
\****************************************************************************/
class SystemSettings {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN( SystemSettings );

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates new system settings with the default values */
    SystemSettings();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Hidden
    Checks if a change has been made to the settings */
    bool check();

    //---------------------------------GETTERS----------------------------------

    /** @return if the cursor is hideen */
    bool isCursorHidden() const;

    /** @return if the cursor is locked to a position */
    bool isCursorLocked() const;

    /** @return the position the mouse is locked */
    const glm::vec2& getCursorLockedPos() const;

    //---------------------------------SETTERS----------------------------------

    /** Sets if the cursor should be hidden */
    void setCursorHidden( bool hidden );

    /** Sets if the mouse should be locked to a position */
    void setCursorLocked( bool locked );

    /** Sets the position the cursor should be locked to if locking is
    enabled */
    void setCursorLockPosition( const glm::vec2& pos );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // if a setting has changed
    bool m_change;

    // if the cursor should be hidden
    bool m_cursorHidden;
    // if the cursor should be locked to a position
    bool m_cursorLocked;
    // the position to lock the cursor to if locking is enabled
    glm::vec2 m_cursorLockPos;
};

} // namespace omi

#endif
