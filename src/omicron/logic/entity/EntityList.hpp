#ifndef OMICRON_LOGIC_ENTITY_ENTITY_LIST_H_
#   define OMICRON_LOGIC_ENTITY_ENTITY_LIST_H_

#include <vector>

#include "lib/Utilitron/MacroUtil.hpp"

namespace omi {

/**********************************************\
| Manages all entities currently in the scene. |
\**********************************************/
class EntityList {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(EntityList);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Creates a new entity list*/
    EntityList();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~EntityList();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Updates all entities and controls adding and removing of entities*/
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------


};

} //namespace omi

#endif
