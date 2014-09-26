#include "RenderSettings.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RenderSettings::RenderSettings() :
    m_change         ( true ),
    m_depthTest      ( true ),
    m_backFaceCulling( true ),
    m_clearColour    ( 0.0f, 0.0f, 0.0f, 1.0f )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

//-----------------------------------GETTERS------------------------------------

bool RenderSettings::getDepthTest() const
{
    return m_depthTest;
}

bool RenderSettings::getBackFaceCulling() const
{
    return m_backFaceCulling;
}

const glm::vec4& RenderSettings::getClearColour() const
{
    return m_clearColour;
}

float RenderSettings::getAmbientStrength() const
{
    return m_ambientStrength;
}

const glm::vec3& RenderSettings::getAmbientColour() const
{
    return m_ambientColour;
}

//-----------------------------------SETTERS------------------------------------

void RenderSettings::setDepthTest(bool depthTest)
{
    m_change = true;
    m_depthTest = depthTest;
}

void RenderSettings::setBackFaceCulling( bool backFaceCulling )
{
    m_change = true;
    m_backFaceCulling = backFaceCulling;
}

void RenderSettings::setClearColour( const glm::vec4& clearColour )
{
    m_change = true;
    m_clearColour = clearColour;
}

void RenderSettings::setAmbientStrength( float strength )
{
    m_change = true;
    m_ambientStrength = strength;
}

void RenderSettings::setAmbientColour( const glm::vec3& colour )
{
    m_change = true;
    m_ambientColour = colour;
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool RenderSettings::check()
{
    bool temp = m_change;
    m_change = false;
    return temp;
}

} // namespace omi
