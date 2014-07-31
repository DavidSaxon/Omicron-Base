#include "TestScene.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestScene::TestScene() :
    m_test(new TestEntity()) {

    // add the test entity to the scene
    addEntity(m_test);
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TestScene::~TestScene() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool TestScene::update() {

    return false;
}

omi::Scene* TestScene::nextScene() const {

    // TODO:
    return 0;
}
