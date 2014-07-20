#ifndef OMICRON_LOGIC_ENTITY_ENTITY_H_
#   define OMICRON_LOGIC_ENTITY_ENTITY_H_

namespace omi {

/****************************************************\
| Abstract base class that all entities will extend. |
\****************************************************/
class Entity {
public:

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Entity() {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Updates the entity and computes it's logic*/
    virtual void update() = 0;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //TODO: components

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //TODO: component update

    //TODO: clean up

};

} //namespace omi

#endif
