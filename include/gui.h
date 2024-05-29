#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <exception>
#include <chrono>
#include <thread>

#include <SDL2pp/SDL2pp.hh>

#define RATE  15.0

using namespace std::chrono;
class Gui {
private:
    int posx;
    int posy;
    int w;
    int h;
public:
    Gui();
    ~Gui();
    void run();
};

#endif