#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <exception>
#include <chrono>

#include <SDL2pp/SDL2pp.hh>

#include "thread.h"

#define RATE  15.0

using namespace std::chrono;
class Gui: public Thread {
private:
    int posx;
    int posy;
    int w;
    int h;
    bool & client_off;
    std::string & personaje;
public:
    Gui(int,int,int,int,bool&,std::string &);
    ~Gui();
    void run() override;
};

#endif