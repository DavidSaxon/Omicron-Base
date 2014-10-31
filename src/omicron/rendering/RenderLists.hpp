#ifndef OMICRON_ENTITY_RENDERING_RENDERLISTS_H_
#   define OMICRON_ENTITY_RENDERING_RENDERLISTS_H_

#include <algorithm>
#include <map>
#include <sstream>
#include <vector>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/component/light/DirectionalLight.hpp"
#include "src/omicron/component/light/PointLight.hpp"
#include "src/omicron/component/light/SpotLight.hpp"
#include "src/omicron/component/renderable/Renderable.hpp"
#include "src/omicron/input/Input.hpp"
#include "src/omicron/rendering/render_texture/RenderTexture.hpp"

namespace omi {

//-----------------------------------TYPEDEF------------------------------------

typedef std::map<int, std::vector<Renderable*>> t_RenderableMap;

/**********************************\
| Object for transparency sorting. |
\**********************************/
struct RenderableDepthSorter {

    // the camera to sort depth with
    Camera* camera;

    /** The sorting function */
    bool operator ()( Renderable* a, Renderable* b )
    {

        // compared based on their distances from the camera
        float distanceA = glm::distance(
            a->getTransform()->translation,
            camera->getTransform()->translation
        );

        float distanceB = glm::distance(
            b->getTransform()->translation,
            camera->getTransform()->translation
        );

        return distanceA < distanceB;
    }
};

/*************************************************************************\
| A set of lists that contain all objects to be rendered by the renderer. |
\*************************************************************************/
class RenderLists {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN( RenderLists );

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new set of render lists */
    RenderLists();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Renders all of the renderable components contained within the render
    lists
    @param the camera to use for rendering */
    void render( Camera* camera );

    /** Removes all components from the render lists */
    void clear();

    /** Adds a renderable component to the render lists
    @param renderable the renderable to add */
    void addRenderable( Renderable* renderable );

    /** Removes a renderable from the render lists
    @param renderable the renderable to remove */
    void removeRenderable( Renderable* renderable );

    /** Adds a light to render lists
    @param light the light to add */
    void addLight( Light* light );

    /** Removes a light from the render lists
    @param light  the light remove */
    void removeLight( Light* light );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the list of renderables
    std::vector<Renderable*> m_renderables;
    // the list of lights
    std::vector<Light*> m_lights;
    // the final render texture
    RenderTexture m_finalRenTex;

    // the depth sorter
    RenderableDepthSorter depthSorter;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Builds light data */
    void buildLightData( Camera* camera, LightData& lightData );

};

} // namespace omi

#endif
