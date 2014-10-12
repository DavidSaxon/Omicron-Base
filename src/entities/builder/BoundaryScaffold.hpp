#ifndef VOIDWALKER_BUILDER_BOUNDARYSCAFFOLD_H_
#    define VOIDWALKER_BUILDER_BOUNDARYSCAFFOLD_H_

#include "src/omicron/entity/Entity.hpp"

#include "src/scenes/builder/grid/BuilderGrid.hpp"

/***************************************************************\
| Aesthetic entity that shows the outline of the building grid. |
\***************************************************************/
class BoundaryScaffold : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    BoundaryScaffold( BuilderGrid* grid );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                VARIABLES
    //--------------------------------------------------------------------------

    // the transforms of the scaffold
    omi::Transform* m_topT;
    omi::Transform* m_bottomT;
    omi::Transform* m_leftT;
    omi::Transform* m_rightT;

    // the building grid
    BuilderGrid* m_grid;
};

#endif
