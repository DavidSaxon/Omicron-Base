#ifndef OMICRON_COMPONENT_RENDERABLE_KEYFRAMEMESH_HPP_
#   define OMICRON_COMPONENT_RENDERABLE_KEYFRAMEMESH_HPP_

#include <map>
#include <vector>

#include "src/omicron/component/renderable/Renderable.hpp"
#include "src/omicron/rendering/object_data/Geometry.hpp"

namespace omi {

/*****************************************************************************\
| A mesh that is create via the interpolation of multiple states of geometry. |
\*****************************************************************************/
class KeyFrameMesh : public Renderable {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new key frame mesh
    @param id the identifier of the component
    @param layer the render layer of the mesh
    @param transform a pointer to a transform to use for the mesh's position
    @param geometry a list of geometry used to make up the key's of the mesh
    @param material the material to use for the mesh */
    KeyFrameMesh(
            const std::string& id,
            int layer,
            Transform* transform,
            std::map<std::string, std::vector<Geometry*>> geometry,
            Material material );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void update();

protected:

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void draw();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the list of geometry key frames used to make up the mesh
    std::map<std::string, std::vector<Geometry*>> m_geometry;

    // the two geometries this is interpolating between
    Geometry* m_geo1;
    Geometry* m_geo2;

    // interpolation timer
    float m_timer;
    // the current frame this is on
    unsigned m_frame;
};

} // namespace omi

#endif
