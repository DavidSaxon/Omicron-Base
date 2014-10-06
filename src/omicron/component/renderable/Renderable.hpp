#ifndef OMICRON_COMPONENT_RENDERABLE_RENDERABLE_H_
#   define OMICRON_COMPONENT_RENDERABLE_RENDERABLE_H_

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include "src/omicron/Omicron.hpp"
#include "src/omicron/component/Component.hpp"
#include "src/omicron/component/Camera.hpp"
#include "src/omicron/component/Transform.hpp"
#include "src/omicron/rendering/shading/Material.hpp"
#include "src/omicron/resource/loader/Loaders.hpp"

namespace omi {

/******************************************************************************\
| Abstract class that defines any component that can be rendered via Omicron's |
| renderer.                                                                    |
\******************************************************************************/
class Renderable : public Component {
public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the selection shader for renderables
    static Shader selectionShader;

    //! is true if this component will be rendered
    bool visible;
    // is true if the this renderable should render for selecting
    bool selectable;
    // is true if the renderable is currently selected
    bool selected;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Super constructor
    @param id the identifier of the component
    @param layer the render layer of the component
    @oaram transform the pointer to the transform to use for positioning
    @param material the material to use for the renderable*/
    Renderable(
            const std::string& id,
                  int          layer,
                  Transform*   transform,
            const Material     material );

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Renderable()
    {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Hidden
    Render this component
    @param camera the camera used to render this */
    void render( Camera* camera );

    /** #Hidden
    Render this component for colour picking */
    void renderSelectable(
            Camera* camera,
            unsigned char red,
            unsigned char green,
            unsigned char blue );

    //---------------------------------GETTERS----------------------------------

    /** #Override */
    virtual component::Type getType() const;

    /** @return the layer of the renderable */
    int getLayer() const;

    /** @return the transform used for positioning this renderable */
    Transform* getTransform();

    /** @return the material used for this renderable */
    Material& getMaterial();

    //---------------------------------SETTERS----------------------------------

    /** @param layer the new render layer of renderable */
    void setLayer( int layer );

    /** @param transform the new transform of the renderable */
    void setTransform( Transform* transform );

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the render layer
    int m_layer;
    // the transform
    Transform* m_transform;
    // the material
    Material  m_material;

    // the model matrix
    glm::mat4 m_modelMatrix;
    // the combined model, view, and projection matrix
    glm::mat4 m_modelViewProjectionMatrix;

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Applies transformations
    @param the camera to get the view and projection matrices from */
    void applyTransformations( Camera* camera );

    /** Sets up the shader for rendering and passes in all data */
    void setShader();

    /** Cleans up the shader */
    void unsetShader();

    /** Defines the geometry of the renderable */
    virtual void draw() = 0;
};

} // namespace omi

#endif
