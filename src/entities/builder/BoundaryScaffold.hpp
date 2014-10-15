#ifndef VOIDWALKER_BUILDER_BOUNDARYSCAFFOLD_H_
#    define VOIDWALKER_BUILDER_BOUNDARYSCAFFOLD_H_

#include "lib/Utilitron/MathUtil.hpp"

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

    // the building grid
    BuilderGrid* m_grid;

    // the transforms of the scaffold
    omi::Transform* m_topT;
    omi::Transform* m_bottomT;
    omi::Transform* m_leftT;
    omi::Transform* m_rightT;

    // transforms of the scaffold cogs
    omi::Transform* m_topCogHolderT;
    omi::Transform* m_topCogT;

    // the positions which the scaffold should be moving too
    float m_topTo;
    float m_bottomTo;
    float m_leftTo;
    float m_rightTo;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Calculates the interpolation points */
    void getInterpolationPoints();

    /** Sets up the components */
    void initComponents();
};

#endif
