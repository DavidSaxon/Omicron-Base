#ifndef OMICRON_COMPONENT_TRANSFORM_H_
#   define OMICRON_COMPONENT_TRANSFORM_H_

#include "lib/glm/glm.hpp"

#include "src/omicron/component/Component.hpp"

namespace omi {

/**********************************************************************************\
| The types of axis spaces that can be used to compute the effects of a transform. |
\**********************************************************************************/

namespace axis_space {

enum AxisSpace {
    LOCAL,
    PARENT,
    GLOBAL
};

} //namespace axis_space

/***************************************************************************\
| A transform defines the translation, rotation, and position of an entity. |
| There must always be exactly one transform component per entity and is    |
| created by default under the id "transform".                              |
\***************************************************************************/
class Transform : public Component {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_DEFAULT_COPY( Transform );

public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //! the translation of the entity
    glm::vec3 translation;
    //! the rotation of the entity
    glm::vec3 rotation;
    //! the scale of the entity
    glm::vec3 scale;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a new transform component
    @param id the identifier of the component
    @param t the initial translation
    @param r the initial rotation
    @param s the initial scale
    @param axisSpace the axis space to use for computing the transform */
    Transform(
              const std::string           id,
              const glm::vec3&            t,
              const glm::vec3&            r,
              const glm::vec3&            s,
                    axis_space::AxisSpace axisSpace = axis_space::LOCAL ) :
        Component  ( id ),
        translation( t ),
        rotation   ( r ),
        scale      ( s )
    {
    }

    /** Creates a new component by copying from another and providing a new
    identifier
    @param id the new identifier
    @param other the other component to copy from */
    Transform( const std::string& id, const Transform& other ) :
        Component  ( id ),
        translation( other.translation ),
        rotation   ( other.rotation ),
        scale      ( other.scale )
    {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** @return the axis space being used by this transform */
    axis_space::AxisSpace getAxisSpace() const
    {
        return m_axisSpace;
    }

    /** Compute the translation values to be applied taking into regards the
    parent transform and the axis space.
    @return the computed translation */
    glm::vec3 computeTranslation() const
    {
        // TODO:
        glm::vec3 computed( translation );

        return computed;
    }

    /** Compute the rotation values to be applied taking into regards the
    parent transform and the axis space.
    @return the computed rotation */
    glm::vec3 computeRotation() const
    {
        // TODO:
        glm::vec3 computed( rotation );

        return computed;
    }

    /** Compute the scale values to be applied taking into regards the parent
    transform and the axis space.
    @return the computed scale */
    glm::vec3 computeScale() const
    {
        // TODO:
        glm::vec3 computed( scale );

        return scale;
    }

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the axis space to use
    axis_space::AxisSpace m_axisSpace;
};

} // namespace omi

#endif
