#ifndef OMICRON_AUDIO_MUSICPLAYER_H_
#   define OMICRON_AUDIO_MUSICPLAYER_H_

#include <iostream>
#include <SFML/Audio.hpp>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/Omicron.hpp"

namespace omi {

class MusicPlayer {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(MusicPlayer);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new music player
    @param filePath the path the file to play
    @param a_load is true to load the music on construction */
    MusicPlayer(const std::string& filePath, bool a_load);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~MusicPlayer();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Loads the music */
    void load();

    /** Starts play back of the music */
    void play();

    /** Pauses playback of the music */
    void pause();

    /** Stops playback of the music */
    void stop();

    //---------------------------------GETTERS----------------------------------

    /** @return the volume of the music */
    float getVolume() const;

    /** @return if the music has stopped playing */
    bool isStopped() const;

    /** @return if the music is looping */
    bool isLooping() const;

    //---------------------------------SETTERS----------------------------------

    /** @param volume the new volume of the music */
    void setVolume(float volume);

    /** @param loop whether the music should loop or not */
    void setLoop(bool loop);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the file path to the music
    std::string m_filePath;

    // the sfml music object
    sf::Music m_music;
    // the volume of the music
    float m_volume;
    // the looping mode of the music
    bool m_loop;
};

} // namespace omi

#endif
