#ifndef SONIDOS_H
#define SONIDOS_H

#include <chrono>
#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_defines_audio.h"
#include "gui_audio.h"


class ClaseSonidos {
private:


public:
    explicit ClaseSonidos(Mixer& mixer);
    ~ClaseSonidos();

    Mixer& mixer;

    std::map<std::string, Audio> audios_map;
    Audio& findAudio(std::string);
    void addAudioCastle();
    void addAudioJump();
    void addAudioExplosion();
    void addAudioHit();
    void addAudioShoot();
    void addAudioPick();
    void addAudio(std::string key,Audio & audio);
};

#endif
