#ifndef OMICRON_RESOURCE_PACK_BUILD_H_
#   define OMICRON_RESOURCE_PACK_BUILD_H_

#include "src/omicron/resource/ResourceManager.hpp"
#include "src/override/ResourceGroups.hpp"
#include "src/override/Values.hpp"

/************************************************************************\
| Contains all resources packs that can be built to add resources to the |
| resource manager.                                                      |
\************************************************************************/
namespace pack {

//------------------------------------------------------------------------------
//                                   PROTOTYPES
//------------------------------------------------------------------------------

//--------------------------------RESOURCE PACKS--------------------------------

void buildAllPack();

void buildStartUpPack();

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/** Builds all resource packs */
inline void build()
{
    buildAllPack();
    buildStartUpPack();
}

} // namespace pack

#endif
