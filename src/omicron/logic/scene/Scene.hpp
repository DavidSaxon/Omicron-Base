#ifndef OMICRON_LOGIC_SCENE_SCENE_H_
#   define OMICRON_LOGIC_SCENE_SCENE_H_

namespace omi {

/*********************************************\
| Abstract base class that all scenes extend. |
\*********************************************/
class Scene {
public:

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Scene() {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**executes a logic cycle of the scene
    @return if true the scene has finished execution and next scene should
    begin execution*/
    virtual bool execute() = 0;

    /**@return the next scene to be executed*/
    virtual Scene* nextScene() const = 0;

    //TODO: input

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //TODO: entity list

};

} //namespace omi

#endif
