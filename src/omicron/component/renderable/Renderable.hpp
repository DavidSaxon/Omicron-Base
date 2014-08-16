#ifndef OMICRON_COMPONENT_RENDERABLE_RENDERABLE_H_
#   define OMICRON_COMPONENT_RENDERABLE_RENDERABLE_H_

#include <GL/glew.h>
#include <GL/glut.h>

#include "src/omicron/component/Component.hpp"
#include "src/omicron/component/Transform.hpp"
#include "src/omicron/rendering/shading/Material.hpp"

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

    //! is true if this component will be rendered
    bool visible;

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
            const Material     material)
        :
        Component  (id),
        visible    (true),
        m_layer    (layer),
        m_transform(transform),
        m_material (material) {
    }

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Renderable() {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual component::Type getType() const {

        return component::RENDERABLE;
    }

    // TODO: setting layer (gets complicated)

    /** @return the layer of the renderable */
    int getLayer() const {

        return m_layer;
    }

    /** @return the transform used for positioning this renderable */
    Transform* getTransform() {

        return m_transform;
    }

    /** @return the material used for this renderable */
    Material& getMaterial() {

        return m_material;
    }

    /** #Hidden
    Render this component */
    virtual void render() = 0;

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

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Applies transformations */
    void applyTransformations() {

        // do nothing if the transform is null
        if (!m_transform) {

            return;
        }

        // apply translation
        util::vec::Vector3 translation(m_transform->computeTranslation());
        glTranslatef(translation.x, translation.y, translation.z);

        // TODO: local and global shit
        // apply rotation
        util::vec::Vector3 rotation(m_transform->computeRotation());
        glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
        glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
        glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);

        // apply scale
        util::vec::Vector3 scale(m_transform->computeScale());
        glScalef(scale.x, scale.y, scale.z);
    }

};

} // namespace omi

#endif
