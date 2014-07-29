#include "TestEntity.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestEntity::TestEntity() {

    //create a transform
    omi::Transform transform("transform",
                        util::vec::Vector3(),
                        util::vec::Vector3(),
                        util::vec::Vector3());
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
