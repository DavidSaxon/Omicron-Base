#include "TestScene.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestScene::TestScene() :
    m_test(new TestEntity()) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TestScene::~TestScene() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestScene::init() {

    // add entities
    addEntity(new Player());
    addEntity(m_test);
    addEntity(new Skybox());
}

bool TestScene::update() {

    // exit if the escape key has been pressed
    if (omi::input::isKeyPressed(27)) {

        return true;
    }

    return false;
}

omi::Scene* TestScene::nextScene() const {

    // TODO:
    return 0;
}
