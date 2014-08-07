#ifndef OMICRON_COMPONENT_RENDERABLE_MESH_MESH_H_
#   define OMICRON_COMPONENT_RENDERABLE_MESH_MESH_H_

#include "src/omicron/component/Transform.hpp"
#include "src/omicron/component/renderable/Renderable.hpp"
#include "src/omicron/rendering/data/structure/Geometry.hpp"

namespace omi {

/****************************************************************************\
| Geometry that contains an arbitrary number vertices, and is shaded using a |
| standard material.                                                         |
\****************************************************************************/
class Mesh : public Renderable {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    //TODO: vertices, materials and shit
    /** Creates a new mesh
    @param id the identifier of the component
    @param transform a pointer to a transform to use for the mesh's position
    @param geometry a pointer to the geometry to use for the mesh*/
    Mesh(const std::string& id,
               Transform*   transform,
               Geometry*    geometry);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Mesh();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Hidden
    Render the mesh */
    void render();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // pointer to the transform to use for the mesh's position
    Transform* m_transform;

    // pointer to the geometry to use for the mesh
    Geometry* m_geometry;
};

} // namespace omi

#endif