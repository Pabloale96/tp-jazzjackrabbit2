#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include <exception>

#include <SDL2pp/SDL2pp.hh>

using namespace SDL2pp;
class Frame {
    private:
        Renderer & renderer;
        Texture & sprite;
        std::vector<int> vec_frames;

    public:
        Frame();
        Frame(Renderer &,Texture &);
        Frame(Renderer &,Texture &,int,int,int,int);
        ~Frame();
        void copy(bool,int,int);
        void copy(bool,int,int,int,int);
        void setFrame(int,int,int,int);
};

#endif