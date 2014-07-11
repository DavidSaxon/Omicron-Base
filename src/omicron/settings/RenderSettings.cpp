#include "RenderSettings.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RenderSettings::RenderSettings() :
    m_change(true),
    m_depthTest(true),
    m_backFaceCulling(true),
    m_clearColour(0.0f, 0.0f, 0.0f, 1.0f) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

RenderSettings::~RenderSettings() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool RenderSettings::getDepthTest() const {

    return m_depthTest;
}

void RenderSettings::setDepthTest(bool depthTest) {

    m_change = true;
    m_depthTest = depthTest;
}

bool RenderSettings::getBackFaceCulling() const {

    return m_backFaceCulling;
}

void RenderSettings::setBackFaceCulling(bool backFaceCulling) {

    m_change = true;
    m_backFaceCulling = backFaceCulling;
}

const util::vec::Vector4& RenderSettings::getClearColour() const {

    return m_clearColour;
}

void RenderSettings::setClearColour(const util::vec::Vector4& clearColour) {

    m_change = true;
    m_clearColour = clearColour;
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool RenderSettings::check() {

    bool temp = m_change;
    m_change = false;
    return temp;
}

} //namespace omi