#include "MusicPlayer.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

MusicPlayer::MusicPlayer(const std::string& filePath, bool a_load) :
    m_filePath(filePath),
    m_volume(1.0f),
    m_loop(false) {

    // load the sound if requested
    if (a_load) {

        load();
    }
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

MusicPlayer::~MusicPlayer() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void MusicPlayer::load() {

    if (!m_music.openFromFile(m_filePath)) {

        // TODO: throw an exception??
        std::cout << "music failed to load" << std::endl;
    }
}

void MusicPlayer::play() {

    // don't play if music is disabled
    if (audioSettings.isMusicDisabled()) {

        return;
    }

    // set up the music settings
    m_music.setVolume(m_volume * audioSettings.getMusicVolume() * 100);
    m_music.setLoop(m_loop);

    // play the music
    m_music.play();
}

void MusicPlayer::pause() {

    m_music.pause();
}

void MusicPlayer::stop() {

    m_music.stop();
}

//-----------------------------------GETTERS------------------------------------

float MusicPlayer::getVolume() const {

    return m_volume;
}

bool MusicPlayer::isStopped() const {

    return m_music.getStatus() == 0;
}

bool MusicPlayer::isLooping() const {

    return m_loop;
}

//-----------------------------------SETTERS------------------------------------

void MusicPlayer::setVolume(float volume) {

    m_volume = volume;
}

void MusicPlayer::setLoop(bool loop) {

    m_loop = loop;
}

} // namespace omi