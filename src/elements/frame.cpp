#include "../../include/frame.h"

Frame::Frame(Renderer & renderer,Texture & sprite)
        :renderer(renderer),sprite(sprite){}

Frame::Frame(Renderer & renderer,Texture & sprite,int x,int y,int w,int h)
        :renderer(renderer),sprite(sprite){

    this->setFrame(x,y,w,h);
}


Frame::~Frame(){}

void Frame::copy(bool flip,int pos_x,int pos_y){
    sprite.SetAlphaMod(255);
    if (flip)
    {
        renderer.Copy(
            sprite,
            Rect(vec_frames[0],vec_frames[1],vec_frames[2],vec_frames[3]),
            Rect(pos_x,pos_y, 75, 75),
            180.0,
            NullOpt,
            2
        );
    } else {
        renderer.Copy(
            sprite,
            Rect(vec_frames[0],vec_frames[1],vec_frames[2],vec_frames[3]),
            Rect(pos_x,pos_y, 75, 75)
        );
    }
}

void Frame::copy(bool flip,int pos_x,int pos_y,int area_x,int area_y){
    sprite.SetAlphaMod(255);
    if (flip)
    {
        renderer.Copy(
            sprite,
            Rect(vec_frames[0],vec_frames[1],vec_frames[2],vec_frames[3]),
            Rect(pos_x,pos_y, area_x, area_y),
            180.0,
            NullOpt,
            2
        );
    } else {
        renderer.Copy(
            sprite,
            Rect(vec_frames[0],vec_frames[1],vec_frames[2],vec_frames[3]),
            Rect(pos_x,pos_y, area_x, area_y)
        );
    }
}



void Frame::setFrame(int x, int y, int w, int h){
    vec_frames.emplace_back(x);
    vec_frames.emplace_back(y);
    vec_frames.emplace_back(w);
    vec_frames.emplace_back(h);
}