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

    // load the test resource group
    omi::ResourceManager::load(resource_group::TEST);

    // add the test entity to the scene
    addEntity(m_test);
    addEntity(new SpriteTest());
    addEntity(new Skybox());
}

bool TestScene::update() {

    return false;
}

omi::Scene* TestScene::nextScene() const {

    // TODO:
    return 0;
}
