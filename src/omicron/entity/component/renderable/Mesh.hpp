#ifndef OMICRON_ENTITY_COMPONENT_RENDERABLE_MESH_H_
#   define OMICRON_ENTITY_COMPONENT_RENDERABLE_MESH_H_

#include "src/omicron/entity/component/Transform.hpp"
#include "src/omicron/entity/component/renderable/Renderable.hpp"

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
    @param transform a pointer to a transform to use for the mesh's position */
    Mesh(const std::string& id, Transform* transform);

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
};

} // namespace omi

#endif