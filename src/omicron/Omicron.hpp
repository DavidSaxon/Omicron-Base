#ifndef OMICRON_OMICRON_H_
#   define OMICRON_OMICRON_H_

#include "src/omicron/logic/fps_manager/FPSManager.hpp"
#include "src/omicron/settings/DisplaySettings.hpp"
#include "src/omicron/settings/RenderSettings.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                GLOBAL VARIABLES
//------------------------------------------------------------------------------

//-----------------------------------SETTINGS-----------------------------------

//the display settings
extern DisplaySettings displaySettings;
//the render settings
extern RenderSettings renderSettings;

} //namespace omi

#endif