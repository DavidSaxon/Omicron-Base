#ifndef OMICRON_SETTINGS_RENDERSETTINGS_H_
#   define OMICRON_SETTINGS_RENDERSETTINGS_H_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include "lib/glm/glm.hpp"
#include "lib/Utilitron/MacroUtil.hpp"

namespace omi {

/*************************************************************\
| An object that contains all settings relating to rendering. |
\*************************************************************/
class RenderSettings {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN( RenderSettings );

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates new render settings initialised with default values */
    RenderSettings();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Hidden
    Checks if a change has been made to the settings */
    bool check();

    //---------------------------------GETTERS----------------------------------

    /** @return if depth testing is enabled */
    bool getDepthTest() const;

    /** @return if back face culling is enabled */
    bool getBackFaceCulling() const;

    /** @return the clear colour */
    const glm::vec4& getClearColour() const;

    /** @return the resolution being rendered to */
    const glm::vec2& getResolution() const;

    /** @return the strength of the ambient light */
    float getAmbientStrength() const;

    /** @return the colour of the ambient light */
    const glm::vec3& getAmbientColour() const;

    /** @return the amount of film grain */
    float getFilmGrain() const;

    //---------------------------------SETTERS----------------------------------

    /** @param depthTest whether depth testing should be enabled */
    void setDepthTest(bool depthTest);

    /** @param backFaceCulling whether back face culling should be enabled */
    void setBackFaceCulling (bool backFaceCulling );

    /** @param clearColour the new clear colour */
    void setClearColour( const glm::vec4& clearColour );

    /** @param resolution the new resolution to be rendered to */
    void setResolution( const glm::vec2& resolution );

    /** @param strength the new strength of ambient light */
    void setAmbientStrength( float strength );

    /** @param colour the new colour of ambient light */
    void setAmbientColour( const glm::vec3& colour );

    /**@param filmGrain the amount of film grain to be applied to the final
              output */
    void setFilmGrain( float filmGrain );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // if a setting has changed
    bool m_change;

    // if depth testing is enabled
    bool m_depthTest;
    // if back face culling should be enabled
    bool m_backFaceCulling;
    // the clear colour
    glm::vec4 m_clearColour;

    // the resolution being rendered to
    glm::vec2 m_resolution;

    // the strength of ambient light
    float m_ambientStrength;
    // the colour of ambient light
    glm::vec3 m_ambientColour;

    // the amount of film grain to be applied to the final output
    float m_filmGrain;
};

} // namespace omi

#endif
