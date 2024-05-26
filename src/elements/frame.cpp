#include "../../include/frame.h"

Frame::Frame(Renderer & renderer,Texture & sprite)
        :renderer(renderer),sprite(sprite){}


Frame::~Frame(){}

void Frame::copy(){
    sprite.SetAlphaMod(255);
    renderer.Copy(
            sprite,
            Rect(vec_frames[0],vec_frames[1],vec_frames[2],vec_frames[3]),
            Rect(renderer.GetOutputWidth()/2-21, renderer.GetOutputHeight()/2-23, 75, 75)
    );
    SDL_Delay(1);
}

void Frame::setFrame(int x, int y, int w, int h){
    vec_frames.emplace_back(x);
    vec_frames.emplace_back(y);
    vec_frames.emplace_back(w);
    vec_frames.emplace_back(h);
}