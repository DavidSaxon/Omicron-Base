#ifndef OMICRON_ENTITY_RENDERING_RENDERLISTS_H_
#   define OMICRON_ENTITY_RENDERING_RENDERLISTS_H_

#include <map>
#include <set>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/entity/component/renderable/Renderable.hpp"
#include "src/omicron/rendering/Renderer.hpp"

namespace omi {

//-----------------------------------TYPEDEF------------------------------------

typedef std::map<int, std::set<Renderable*>> t_RenderableMap;

/*************************************************************************\
| A set of lists that contain all objects to be rendered by the renderer. |
\*************************************************************************/
class RenderLists {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(RenderLists);

public:

    //--------------------------------------------------------------------------
    //                                  FRIENDS
    //--------------------------------------------------------------------------

    friend class Renderer;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new set of render lists */
    RenderLists();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~RenderLists();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Adds a renderable component to the render lists
    @param renderable the renderable to add
    @param layer the layer to add the renderable to */
    void addRenderable(Renderable* renderable, int layer);

    /** Removes a renderable from the render lists
    @param renderable the renderable to remove */
    void removeRenderable(Renderable* renderable);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // all renderable components grouped by layer
    t_RenderableMap m_renderables;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Renders all of the renderable components contained within the render
    lists */
    void render();
};

} // namespace omi

#endif
