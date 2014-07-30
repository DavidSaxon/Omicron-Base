#include "TestEntity.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestEntity::TestEntity() {

    //create a transform
    m_components.add(
        new omi::Transform(
            "transform",
            util::vec::Vector3(8.0f, 3.0f, 2.0f),
            util::vec::Vector3(),
            util::vec::Vector3()
        )
    );

    omi::Transform* t =
            dynamic_cast<omi::Transform*>(m_components.get("transform"));

    std::cout << t->translation.x << std::endl;

    m_components.remove("transform");

    std::cout << t->translation.x << std::endl;
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TestEntity::~TestEntity() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEntity::update() {

    glBindTexture(GL_TEXTURE_2D, 0);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f( 1.0f,  1.0f, 0.0);
    glVertex3f(-1.0f,  1.0f, 0.0);
    glVertex3f(-1.0f, -1.0f, 0.0);
    glVertex3f( 1.0f, -1.0f, 0.0);
    glEnd();
}
