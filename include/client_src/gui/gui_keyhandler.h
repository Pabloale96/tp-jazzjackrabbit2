#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "../../common_src/catedra/queue.h"

#include "gui_defines_frames.h"
#include "gui_personaje.h"
#include "msgToSent.h"

using SDL2pp::NullOpt;
using SDL2pp::Rect;
using SDL2pp::Renderer;
using SDL2pp::Texture;

class KeyboardHandler {
private:
    SDL_Event event;


public:
    KeyboardHandler();

    bool keyBoardManaged(Queue<msgAccion>&,const uint8_t &);

    bool checkKeyPress(SDL_Keycode);
};

#endif
