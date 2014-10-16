#include "BoundaryScaffold.hpp"

namespace {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

// the move speed of the scaffolding
static const float MOVE_SPEED   = 0.05f;
// the extra room to add around the furtherest blocks
static const float ROOM_TO_MOVE = 3.0f;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BoundaryScaffold::BoundaryScaffold( BuilderGrid* grid )
    :
    m_grid( grid )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BoundaryScaffold::init()
{
    // set the initial interpolation points
    getInterpolationPoints();

    initComponents();
}

void BoundaryScaffold::update()
{
    // get the interpolation points
    getInterpolationPoints();
    // interpolate scaffolding
    m_topT->translation.y = util::math::interpolate(
        m_topT->translation.y,
        m_topTo,
        MOVE_SPEED * omi::fpsManager.getTimeScale()
    );
    m_bottomT->translation.y = util::math::interpolate(
        m_bottomT->translation.y,
        m_bottomTo,
        MOVE_SPEED * omi::fpsManager.getTimeScale()
    );
    m_leftT->translation.x = util::math::interpolate(
        m_leftT->translation.x,
        m_leftTo,
        MOVE_SPEED * omi::fpsManager.getTimeScale()
    );
    m_rightT->translation.x = util::math::interpolate(
        m_rightT->translation.x,
        m_rightTo,
        MOVE_SPEED * omi::fpsManager.getTimeScale()
    );

    // update top left cogs
    m_topLeftCogHolderT->translation.x = m_leftT->translation.x + 1.0f;
    m_topLeftCogHolderT->translation.y = m_topT->translation.y  - 1.0f;
    m_topLeftCogT->rotation.z = m_topT->translation.y  * 90.0f;
    m_leftTopCogT->rotation.z = m_leftT->translation.x * 90.0f;
    // update top right cogs
    m_topRightCogHolderT->translation.x = m_rightT->translation.x - 1.0f;
    m_topRightCogHolderT->translation.y = m_topT->translation.y   - 1.0f;
    m_topRightCogT->rotation.z = m_topT->translation.y   * -90.0f;
    m_rightTopCogT->rotation.z = m_rightT->translation.x *  90.0f;
    // update bottom left cogs
    m_bottomLeftCogHolderT->translation.x = m_leftT->translation.x   + 1.0f;
    m_bottomLeftCogHolderT->translation.y = m_bottomT->translation.y + 1.0f;
    m_bottomLeftCogT->rotation.z = m_bottomT->translation.y *  90.0f;
    m_leftBottomCogT->rotation.z = m_leftT->translation.x   * -90.0f;
    // update bottom right cogs
    m_bottomRightCogHolderT->translation.x = m_rightT->translation.x  - 1.0f;
    m_bottomRightCogHolderT->translation.y = m_bottomT->translation.y + 1.0f;
    m_bottomRightCogT->rotation.z = m_bottomT->translation.y * -90.0f;
    m_rightBottomCogT->rotation.z = m_rightT->translation.x  * -90.0f;
 }

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BoundaryScaffold::getInterpolationPoints()
{
    // reset to zero
    m_topTo    = 0.0f;
    m_bottomTo = 0.0f;
    m_leftTo   = 0.0f;
    m_rightTo  = 0.0f;
    // get distances
    m_grid->getSize( m_leftTo, m_rightTo, m_bottomTo, m_topTo );
    // add room to move
    m_topTo    += ROOM_TO_MOVE;
    m_bottomTo -= ROOM_TO_MOVE;
    m_leftTo   -= ROOM_TO_MOVE;
    m_rightTo  += ROOM_TO_MOVE;
}

void BoundaryScaffold::initComponents()
{
    //-------------------------------TOP BOUNDARY-------------------------------
    m_topT = new omi::Transform(
        "",
        glm::vec3( 0.0f, m_topTo, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_topT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_horizontal", "", m_topT));
    //-----------------------------BOTTOM BOUNDARY------------------------------
    m_bottomT = new omi::Transform(
        "",
        glm::vec3( 0.0f, m_bottomTo, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_bottomT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_horizontal", "", m_bottomT));
    //------------------------------LEFT BOUNDARY-------------------------------
    m_leftT = new omi::Transform(
        "",
        glm::vec3( m_leftTo, 0.0f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_leftT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_vertical", "", m_leftT));
    //------------------------------RIGHT BOUNDARY------------------------------
    m_rightT = new omi::Transform(
        "",
        glm::vec3( m_rightTo, 0.0f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_rightT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_vertical", "", m_rightT));

    //------------------------------TOP LEFT COGS-------------------------------
    m_topLeftCogHolderT = new omi::Transform(
        "",
        glm::vec3( m_leftTo + 1, m_topTo - 1, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_topLeftCogHolderT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog_holder", "", m_topLeftCogHolderT));

    m_topLeftCogT = new omi::Transform(
        "", m_topLeftCogHolderT,
        glm::vec3( -0.25f, -0.25f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_topLeftCogT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog", "", m_topLeftCogT));

    m_leftTopCogT = new omi::Transform(
        "", m_topLeftCogHolderT,
        glm::vec3( 0.25f, 0.25f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_leftTopCogT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog", "", m_leftTopCogT));

    //------------------------------TOP RIGHT COGS------------------------------
    m_topRightCogHolderT = new omi::Transform(
        "",
        glm::vec3( m_rightTo - 1, m_topTo - 1, 0.0f ),
        glm::vec3( ),
        glm::vec3( -1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_topRightCogHolderT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog_holder", "", m_topRightCogHolderT));

    m_topRightCogT = new omi::Transform(
        "", m_topRightCogHolderT,
        glm::vec3( 0.25f, -0.25f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_topRightCogT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog", "", m_topRightCogT));

    m_rightTopCogT = new omi::Transform(
        "", m_topRightCogHolderT,
        glm::vec3( -0.25f, 0.25f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_rightTopCogT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog", "", m_rightTopCogT));

    //-----------------------------BOTTOM LEFT COGS-----------------------------
    m_bottomLeftCogHolderT = new omi::Transform(
        "",
        glm::vec3( m_leftTo + 1, m_topTo - 1, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, -1.0f, 1.0f )
    );
    m_components.add(m_bottomLeftCogHolderT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog_holder", "", m_bottomLeftCogHolderT));

    m_bottomLeftCogT = new omi::Transform(
        "", m_bottomLeftCogHolderT,
        glm::vec3( -0.25f, 0.25f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_bottomLeftCogT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog", "", m_bottomLeftCogT));

    m_leftBottomCogT = new omi::Transform(
        "", m_bottomLeftCogHolderT,
        glm::vec3( 0.25f, -0.25f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_leftBottomCogT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog", "", m_leftBottomCogT));

    //----------------------------BOTTOM RIGHT COGS-----------------------------
    m_bottomRightCogHolderT = new omi::Transform(
        "",
        glm::vec3( m_leftTo + 1, m_topTo - 1, 0.0f ),
        glm::vec3(),
        glm::vec3( -1.0f, -1.0f, 1.0f )
    );
    m_components.add(m_bottomRightCogHolderT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog_holder", "", m_bottomRightCogHolderT));

    m_bottomRightCogT = new omi::Transform(
        "", m_bottomRightCogHolderT,
        glm::vec3( 0.25f, 0.25f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_bottomRightCogT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog", "", m_bottomRightCogT));

    m_rightBottomCogT = new omi::Transform(
        "", m_bottomRightCogHolderT,
        glm::vec3( -0.25f, -0.25f, 0.0f ),
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add(m_rightBottomCogT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_cog", "", m_rightBottomCogT));
}
