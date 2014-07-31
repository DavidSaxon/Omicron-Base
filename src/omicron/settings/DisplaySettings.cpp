#include "DisplaySettings.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

DisplaySettings::DisplaySettings() :
    m_change(true),
    m_title("Omicron"),
    m_size(640, 480),
    m_pos(0, 0),
    m_fullscreen(false) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

DisplaySettings::~DisplaySettings() {
}

//------------------------------------------------------------------------------
//                             PUBLIC MEMBER FUNCIONS
//------------------------------------------------------------------------------

const std::string& DisplaySettings::getTitle() const {

    return m_title;
}

void DisplaySettings::setTitle(const std::string& title) {

    m_title = title;
    m_change = true;
}

const util::vec::Vector2& DisplaySettings::getSize() const {

    return m_size;
}

void DisplaySettings::setSize(const util::vec::Vector2& size) {

    m_size = size;
    m_change = true;
}

const util::vec::Vector2& DisplaySettings::getPos() const {

    return m_pos;
}

void DisplaySettings::setPos(const util::vec::Vector2& pos) {

    m_pos = pos;
    m_change = true;
}

bool DisplaySettings::getFullscreen() const {

    return m_fullscreen;
}

void DisplaySettings::setFullscreen(bool fullscreen) {

    m_fullscreen = fullscreen;
    m_change = true;
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool DisplaySettings::check() {

    bool temp = m_change;
    m_change = false;
    return temp;
}

} // namespace omi
