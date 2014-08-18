#ifndef OMICRON_COMPONENT_CAMERA_H_
#   define OMICRON_COMPONENT_CAMERA_H_

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

#include "src/omicron/Omicron.hpp"
#include "src/omicron/component/Component.hpp"
#include "src/omicron/component/Transform.hpp"

namespace omi {

namespace cam {

// the mode of the camera
enum Mode {

    PERSPECTIVE,
    ORTHOGRAPHIC
};

} // namespace cam

class Camera : public Component {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a new camera
    @param id the identifier of the component
    @param mode the mode of the camera
    @param transform a pointer to the transform to use for the camera */
    Camera(const std::string& id,
                 cam::Mode    mode,
                 Transform*   transform);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Camera();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    component::Type getType() const;

    /** #Hidden
    Applies the effects of the camera to the render matrices */
    void apply();

    /** @return the mode of the camera */
    cam::Mode getMode() const;

    /** @return the transform used by the camera */
    Transform* getTransform();

    /** @param the new mode of the camera */
    void setMode(cam::Mode mode);

    /** @param the new transform to be used by the camera */
    void setTransform(Transform* transform);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the mode of the camera
    cam::Mode m_mode;
    // the transform of the camera
    Transform* m_transform;

};

 } // namespace omi

#endif