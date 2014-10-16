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

    // top left scaffold cog transforms
    omi::Transform* m_topLeftCogHolderT;
    omi::Transform* m_topLeftCogT;
    omi::Transform* m_leftTopCogT;
    // top right scaffold cog transforms
    omi::Transform* m_topRightCogHolderT;
    omi::Transform* m_topRightCogT;
    omi::Transform* m_rightTopCogT;
    // bottom left scaffold cogs transforms
    omi::Transform* m_bottomLeftCogHolderT;
    omi::Transform* m_bottomLeftCogT;
    omi::Transform* m_leftBottomCogT;
    // bottom right scaffold cogs transforms
    omi::Transform* m_bottomRightCogHolderT;
    omi::Transform* m_bottomRightCogT;
    omi::Transform* m_rightBottomCogT;

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
