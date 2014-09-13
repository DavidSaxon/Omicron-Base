#ifndef BOF_SCENES_LEVELSCENE_H_
#   define BOF_SCENES_LEVELSCENE_H_

#include "src/omicron/input/Input.hpp"
#include "src/omicron/scene/Scene.hpp"

#include "src/entities/level/PlayerShip.hpp"

class LevelScene: public omi::Scene {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    LevelScene();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~LevelScene();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void init();

    /** #Override */
    virtual bool update();

    /** #Override */
    virtual omi::Scene* nextScene() const;
};

#endif