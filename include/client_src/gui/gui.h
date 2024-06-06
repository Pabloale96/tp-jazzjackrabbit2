#ifndef GUI_H
#define GUI_H

#include <chrono>
#include <exception>
#include <iostream>
#include <string>

#include <SDL2pp/SDL2pp.hh>

#include "game_state.h"
#include "gui_clase_texturas.h"
#include "gui_defines_frames.h"
#include "msgToSent.h"
#include "queue.h"
#include "thread.h"

#define RATE 15.0

using std::chrono::duration;
using std::chrono::nanoseconds;
using std::chrono::steady_clock;

class Gui: public Thread {
private:
    int posx;
    int posy;
    int w;
    int h;
    bool& client_off;
    std::string& personaje;
    Queue<msgAccion>& client_commands;

public:
    Gui(int, int, int, int, bool&, std::string&, Queue<msgAccion>&);
    ~Gui();
    void run() override;
    void setGameState(GameState&, uint16_t);
};

#endif
