#ifndef OMICRON_RESOURCE_RESOURCEMANAGER_H_
#   define OMICRON_RESOURCE_RESOURCEMANAGER_H_

#include "src/override/ResourceGroups.hpp"

namespace omi {

/***********************************************************************\
| The resource manager stores, loads, and provides access to resources. |
\***********************************************************************/
class ResourceManager {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a resource manager */
    ResourceManager();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ResourceManager();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Loads the resources within the given group
    #NOTE: this function will only return once all resources are loaded */
    load(resource_group::ResourceGroup);
};

} // namespace omi

#endif
