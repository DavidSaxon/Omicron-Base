#ifndef VOIDWALKER_SCENES_BUILDER_BUILDERSCENE_H_
#   define VOIDWALKER_SCENES_BUILDER_BUILDERSCENE_H_

#include "src/omicron/input/Input.hpp"
#include "src/omicron/scene/Scene.hpp"

#include "src/scenes/level/LevelScene.hpp"

#include "src/entities/builder/BuilderControl.hpp"
#include "src/entities/builder/BuilderEnvironment.hpp"
#include "src/entities/builder/gui/BlockSelect.hpp"
#include "src/entities/gui/Cursor.hpp"
#include "src/entities/ship/BlockFactory.hpp"

/*****************************************************\
| The scene where ships and designed and constructed. |
\*****************************************************/
class BuilderScene : public omi::Scene {

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void init();

    /** #Override */
    virtual bool update();

    /** #Override */
    virtual omi::Scene* nextScene() const;

private:

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Adds the initial entities to the scene */
    void initEntities();

};

#endif
