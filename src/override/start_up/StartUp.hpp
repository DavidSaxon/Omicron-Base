#ifndef OMICRON_OVERRIDE_STARTUP_STARTUP_H_
#   define OMICRON_OVERRIDE_STARTUP_STARTUP_H_

#include "src/omicron/Omicron.hpp"
#include "src/omicron/logic/scene/Scene.hpp"

#include "src/scenes/TestScene.hpp"

/**************************************************\
| functions used to initialise settings at launch. |
\**************************************************/
namespace start_up {

/**This function is called at initialisation of Omicron, it's used to set the
initial settings and provided the first scene to run
@return the first scene to run*/
omi::Scene* init();

} //namespace startup

#endif
