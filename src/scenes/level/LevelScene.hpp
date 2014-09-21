#ifndef VOIDWALKER_SCENES_LEVELSCENE_H_
#   define VOIDWALKER_SCENES_LEVELSCENE_H_

#include "src/omicron/input/Input.hpp"
#include "src/omicron/scene/Scene.hpp"

/****************************************\
| The scene where the game-play happens! |
\****************************************/
class LevelScene : public omi::Scene {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    LevelScene();

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