#ifndef OMICRON_ENTITY_COMPONENT_RENDERABLE_MESH_H_
#   define OMICRON_ENTITY_COMPONENT_RENDERABLE_MESH_H_

#include <iostream>

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
    @param id the identifier of the component */
    Mesh(const std::string& id);
    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Mesh();

protected:

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Render the mesh */
    void render();
};

} // namespace omi

#endif