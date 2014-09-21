#ifndef VOIDWALKER_BUILDER_BUILDERENVIRONMENT_H_
#    define VOIDWALKER_BUILDER_BUILDERENVIRONMENT_H_

#include "src/omicron/entity/Entity.hpp"

/************************************************************\
| The static, non-interactive elements in the builder scene. |
\************************************************************/
class BuilderEnvironment : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Initialises the components */
    void initComponents();
};

#endif
