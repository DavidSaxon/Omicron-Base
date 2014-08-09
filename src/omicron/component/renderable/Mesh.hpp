#ifndef OMICRON_COMPONENT_RENDERABLE_MESH_H_
#   define OMICRON_COMPONENT_RENDERABLE_MESH_H_

#include "src/omicron/component/renderable/Renderable.hpp"
#include "src/omicron/rendering/object_data/Geometry.hpp"
#include "src/omicron/rendering/shading/Material.hpp"

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

    /** Creates a new mesh
    @param id the identifier of the component
    @param transform a pointer to a transform to use for the mesh's position
    @param geometry a pointer to the geometry to use for the mesh
    @param material the material to use for the mesh*/
    Mesh(const std::string& id,
               Transform*   transform,
               Geometry*    geometry,
               Material     material);

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
    // the material to use for the mesh
    Material  m_material;
};

} // namespace omi

#endif