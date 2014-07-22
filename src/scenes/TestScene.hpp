#ifndef OMICRON_SCENES_TESTSCENE_H_
#   define OMICRON_SCENES_TESTSCENE_H_

#include <memory>

#include "src/omicron/logic/scene/Scene.hpp"

#include "src/entities/test/TestEntity.hpp"

/**************************************\
| Testing scene for the Omicron engine |
\**************************************/
class TestScene : public omi::Scene {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Creates a new test scene*/
    TestScene();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~TestScene();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**#Override*/
    virtual bool update();

    /**#Override*/
    virtual omi::Scene* nextScene() const;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    std::unique_ptr<omi::Entity> m_test;
};

#endif
