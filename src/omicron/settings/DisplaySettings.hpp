#ifndef OMICRON_SETTINGS_DISPLAYSETTINGS_H_
#   define OMICRON_SETTINGS_DISPLAYSETTINGS_H_

#include <GL/glut.h>

#include "lib/Utilitron/MacroUtil.hpp"
#include "lib/Utilitron/Vector.hpp"

#include "src/omicron/display/Window.hpp"

namespace omi {

/******************************************************************************\
| An object that contains all settings relating to the display window that are |
| controlled by Omicron.                                                       |
\******************************************************************************/
class DisplaySettings {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(DisplaySettings);

public:

    //--------------------------------------------------------------------------
    //                                  FRIENDS
    //--------------------------------------------------------------------------

    friend class Window;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Creates new window settings initialised with the default values*/
    DisplaySettings();

    //--------------------------------------------------------------------------
    //                                 DESTRCUTOR
    //--------------------------------------------------------------------------

    ~DisplaySettings();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**@return the title of the window*/
    const std::string& getTitle() const;

    /**@param title the new title of the window*/
    void setTitle(const std::string& title);

    /**@return the size of the window*/
    const util::vec::Vector2& getSize() const;

    /**@param size the new size of the window*/
    void setSize(const util::vec::Vector2& size);

    /**@return the position of the window*/
    const util::vec::Vector2& getPos() const;

    /**@param pos the new position of the window*/
    void setPos(const util::vec::Vector2& pos);

    /**@return if the window is in fullscreen*/
    bool getFullscreen() const;

    /**@param fullscreen the new fullscreen mode of the window*/
    void setFullscreen(bool fullscreen);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //if a setting has changed
    bool m_change;

    //the title of the window
    std::string m_title;
    //the size of the window
    util::vec::Vector2 m_size;
    //the position of the window
    util::vec::Vector2 m_pos;
    //is true if the window is in fullscreen
    bool m_fullscreen;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Checks if a change has been made to the settings*/
    bool check();
};


} //namespace omi

#endif
