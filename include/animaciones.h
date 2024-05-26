#ifndef ANIMACIONES_H
#define ANIMACIONES_H

#include <iostream>
#include <exception>
#include<vector>
#include <SDL2pp/SDL2pp.hh>

#include "frame.h"

using namespace SDL2pp;
class Animacion {
    private:
        Renderer & render;
        Texture & sprites;
    public:
        Animacion(Renderer&,Texture&);
        ~Animacion();

        void run(){}
};

class AnimacionDerecha : public Animacion {
    private:
        int scr_x=0;
        int scr_y=0;
        std::vector<Frame> frames;
        int x_frames[8] = {4,52,103,154,205,257,307,356};
        int y_frames[8] = {944,944,944,944,944,944,944,944};
        int w_frames[8] = {43,43,43,43,43,43,43,43};
        int h_frames[8] = {45,46,45,45,46,45,45,46};

    public:
        AnimacionDerecha(Renderer&,Texture&);
        ~AnimacionDerecha();

        void run();
};



#endif