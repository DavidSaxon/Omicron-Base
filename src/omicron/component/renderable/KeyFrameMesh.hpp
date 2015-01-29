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
    @param geometry a map from animation names to the key's geometry
    @param frames a map from animation names to the number of frames between
                  each key
    @param defaultAni the name of the default animation to use
    @param material the material to use for the mesh */
    KeyFrameMesh(
            const std::string& id,
            int layer,
            Transform* transform,
            std::map<std::string, std::vector<Geometry*>> geometry,
            std::map<std::string, std::vector<unsigned>> frames,
            const std::string& defaultAni,
            Material material );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void update();

    /** Transitions the current animation to the given animation over a certain
    amount of frames */
    void transition( const std::string animation, unsigned frames );

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
    // a map from animation name to frame lengths between each key
    std::map<std::string, std::vector<unsigned>> m_frameMap;

    // the default animation of the key frame mesh
    std::string m_defaultAni;

    // the two geometries this is interpolating between
    Geometry* m_geo1;
    Geometry* m_geo2;

    // the current animation
    std::string m_currAni;
    // the previous animation if we are transitioning
    std::string m_prevAni;
    // the frame length of the current transition
    int m_transition;
    // the current frame the animation is in
    float m_frame;
    // the current key of the animation
    unsigned m_key;

    // the ratio between each key
    float m_r1;
    float m_r2;
};

} // namespace omi

#endif
