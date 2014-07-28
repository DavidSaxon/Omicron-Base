#ifndef OMICRON_SETTINGS_RENDERSETTINGS_H_
#   define OMICRON_SETTINGS_RENDERSETTINGS_H_

#include <GL/glut.h>

#include "lib/Utilitron/MacroUtil.hpp"
#include "lib/Utilitron/Vector.hpp"

#include "src/omicron/rendering/Renderer.hpp"

namespace omi {

/*************************************************************\
| An object that contains all settings relating to rendering. |
\*************************************************************/
class RenderSettings {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(RenderSettings);

public:

    //--------------------------------------------------------------------------
    //                                  FRIENDS
    //--------------------------------------------------------------------------

    friend class Renderer;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Creates new render settings initialised with default values*/
    RenderSettings();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~RenderSettings();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**@return if depth testing is enabled*/
    bool getDepthTest() const;

    /**@param depthTest whether depth testing should be enabled*/
    void setDepthTest(bool depthTest);

    /**@return if back face culling is enabled*/
    bool getBackFaceCulling() const;

    /**@param backFaceCulling whether back face culling should be enabled*/
    void setBackFaceCulling(bool backFaceCulling);

    /**@return the clear colour*/
    const util::vec::Vector4& getClearColour() const;

    /**@param clearColour the new clear colour*/
    void setClearColour(const util::vec::Vector4& clearColour);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //if a setting has changed
    bool m_change;

    //if depth testing is enabled
    bool m_depthTest;
    //if back face culling should be enabled
    bool m_backFaceCulling;
    //the clear colour
    util::vec::Vector4 m_clearColour;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Checks if a change has been made to the settings*/
    bool check();
};

} //namespace omi

#endif
