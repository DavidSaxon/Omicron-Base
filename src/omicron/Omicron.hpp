#ifndef OMICRON_OMICRON_H_
#   define OMICRON_OMICRON_H_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include "lib/glm/glm.hpp"

#include "src/omicron/logic/FPSManager.hpp"
#include "src/omicron/settings/AudioSettings.hpp"
#include "src/omicron/settings/DisplaySettings.hpp"
#include "src/omicron/settings/RenderSettings.hpp"
#include "src/omicron/settings/SystemSettings.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                GLOBAL VARIABLES
//------------------------------------------------------------------------------

//-----------------------------------SETTINGS-----------------------------------

// system settings
extern SystemSettings systemSettings;
// the display settings
extern DisplaySettings displaySettings;
// the render settings
extern RenderSettings renderSettings;
// the audio settings
extern AudioSettings audioSettings;

// the fps manager
extern FPSManager fpsManager;

// the scale of the current camera
extern glm::vec3 camScale;

} // namespace omi

#endif
