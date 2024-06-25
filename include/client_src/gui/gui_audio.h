#ifndef AUDIO_H
#define AUDIO_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_defines_frames.h"
#include "protocol_utils.h"

using SDL2pp::NullOpt;
using SDL2pp::Rect;
using SDL2pp::Renderer;
using SDL2pp::Texture;


class Audio {
private:
    Mixer& mixer;
    Chunk audio;

public:
    Audio(Mixer&, std::string);
    ~Audio();
    void run();
};

#endif
