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
    // update cogs
    m_topCogHolderT->translation.x = m_leftT->translation.x + 1.0f;
    m_topCogHolderT->translation.y = m_topT->translation.y  - 1.0f;
    // TODO: fix me
    m_topCogT->rotation.z = m_leftT->translation.x * -90.0f;
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
    glm::vec3(1.0f, 1.0f, 1.0f)
);
m_components.add(m_topT);
m_components.add(omi::ResourceManager::getSprite(
    "builder_boundary_scaffold_horizontal", "", m_topT));
//-----------------------------BOTTOM BOUNDARY------------------------------
m_bottomT = new omi::Transform(
    "",
    glm::vec3( 0.0f, m_bottomTo, 0.0f ),
    glm::vec3(),
    glm::vec3(1.0f, 1.0f, 1.0f)
);
m_components.add(m_bottomT);
m_components.add(omi::ResourceManager::getSprite(
    "builder_boundary_scaffold_horizontal", "", m_bottomT));
//------------------------------LEFT BOUNDARY-------------------------------
m_leftT = new omi::Transform(
    "",
    glm::vec3( m_leftTo, 0.0f, 0.0f ),
    glm::vec3(),
    glm::vec3(1.0f, 1.0f, 1.0f)
);
m_components.add(m_leftT);
m_components.add(omi::ResourceManager::getSprite(
    "builder_boundary_scaffold_vertical", "", m_leftT));
//------------------------------RIGHT BOUNDARY------------------------------
m_rightT = new omi::Transform(
    "",
    glm::vec3( m_rightTo, 0.0f, 0.0f ),
    glm::vec3(),
    glm::vec3(1.0f, 1.0f, 1.0f)
);
m_components.add(m_rightT);
m_components.add(omi::ResourceManager::getSprite(
    "builder_boundary_scaffold_vertical", "", m_rightT));
//---------------------------------TOP LEFT COG---------------------------------
m_topCogHolderT = new omi::Transform(
    "",
    glm::vec3( m_leftTo + 1, m_topTo - 1, 0.0f ),
    glm::vec3(),
    glm::vec3(1.0f, 1.0f, 1.0f)
);
m_components.add(m_topCogHolderT);
m_components.add(omi::ResourceManager::getSprite(
    "builder_boundary_scaffold_cog_holder", "", m_topCogHolderT));
m_topCogT = new omi::Transform(
    "", m_topCogHolderT,
    glm::vec3( ),
    glm::vec3(),
    glm::vec3(1.0f, 1.0f, 1.0f)
);
m_components.add(m_topCogT);
m_components.add(omi::ResourceManager::getSprite(
    "builder_boundary_scaffold_cog", "", m_topCogT));
}
