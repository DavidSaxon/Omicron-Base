#ifndef OMICRON_ENTITIES_TEST_BOXTRAIL_H_
#   define OMICRON_ENTITIES_TEST_BOXTRAIL_H_

#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/resource/ResourceManager.hpp"

class BoxTrail : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Constructor */
    BoxTrail(const omi::Transform* transform);

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the transform of the entity
    omi::Transform* m_transform;
    // the material of the entity
    omi::Material* m_material;
};

#endif
