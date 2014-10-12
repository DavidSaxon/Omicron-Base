#include "BoundaryScaffold.hpp"

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
    // top boundary
    m_topT = new omi::Transform(
        "",
        glm::vec3( 0.0f, 5.0f, 0.0f ),
        glm::vec3(),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_topT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_horizontal", "", m_topT));
    // bottom boundary
    m_bottomT = new omi::Transform(
        "",
        glm::vec3( 0.0f, -5.0f, 0.0f ),
        glm::vec3(),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_bottomT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_horizontal", "", m_bottomT));
    // left boundary
    m_leftT = new omi::Transform(
        "",
        glm::vec3( -5.0f, 0.0f, 0.0f ),
        glm::vec3(),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_leftT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_vertical", "", m_leftT));
    // right boundary
    m_rightT = new omi::Transform(
        "",
        glm::vec3( 5.0f, 0.0f, 0.0f ),
        glm::vec3(),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_rightT);
    m_components.add(omi::ResourceManager::getSprite(
        "builder_boundary_scaffold_vertical", "", m_rightT));
}

void BoundaryScaffold::update()
{
    // get the distances of the grid
    float minX = 0.0f;
    float maxX = 0.0f;
    float minY = 0.0f;
    float maxY = 0.0f;
    m_grid->getSize( minX, maxX, minY, maxY );
    m_topT->translation.y    = maxY + 3.0f;
    m_bottomT->translation.y = minY - 3.0f;
    m_leftT->translation.x   = minX - 3.0f;
    m_rightT->translation.x  = maxX + 3.0f;
    std::cout << "minX: " << minX << std::endl;
    std::cout << "maxX: " << maxX << std::endl;
    std::cout << "minY: " << minY << std::endl;
    std::cout << "maxY: " << maxY << std::endl;
 }

