#ifndef OMICRON_COMPONENT_RENDERABLE_RENDERABLE_H_
#   define OMICRON_COMPONENT_RENDERABLE_RENDERABLE_H_

#include <GL/glew.h>
#include <GL/glut.h>

#include "src/omicron/component/Component.hpp"
#include "src/omicron/component/Transform.hpp"

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
    @param layer the render layer of the component*/
    Renderable(const std::string& id, int layer)
        :
        Component(id),
        visible (true),
        m_layer(layer) {
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

    /** #Hidden
    Render this component */
    virtual void render() = 0;

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the render layer
    int m_layer;

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Applies the transformations of the given transform
    @param transform the transform to apply */
    void applyTransform(Transform* transform) {

        // do nothing if the transform is null
        if (!transform) {

            return;
        }

        // apply translation
        util::vec::Vector3 translation(transform->computeTranslation());
        glTranslatef(translation.x, translation.y, translation.z);

        // TODO: local and global shit
        // apply rotation
        util::vec::Vector3 rotation(transform->computeRotation());
        glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
        glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
        glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);

        // apply scale
        util::vec::Vector3 scale(transform->computeScale());
        glScalef(scale.x, scale.y, scale.z);
    }

};

} // namespace omi

#endif
