#include "../../include/client_src/gui/gui_frame.h"

Frame::Frame(Renderer& renderer, Texture& sprite): renderer(renderer), sprite(sprite) {}

Frame::Frame(Renderer& renderer, Texture& sprite, int x, int y, int w, int h):
        renderer(renderer), sprite(sprite), vec_frames{x, y, w, h} {


    //this->setFrame(x, y, w, h);
}


Frame::~Frame() {}

void Frame::copy(bool flip, int pos_x, int pos_y) {
    std::cout << "vec_frames[0] "<< vec_frames[0] << std::endl;
    std::cout << "vec_frames[1] "<< vec_frames[1] << std::endl;
    std::cout << "vec_frames[2] "<< vec_frames[2] << std::endl;
    std::cout << "vec_frames[3] "<< vec_frames[3] << std::endl;
    sprite.SetAlphaMod(255);
    if (flip) {
        renderer.Copy(sprite, Rect(vec_frames[0], vec_frames[1], vec_frames[2], vec_frames[3]),
                      Rect(pos_x, pos_y, vec_frames[2], vec_frames[3]), 180.0, NullOpt, 2);
    } else {
        renderer.Copy(sprite, Rect(vec_frames[0], vec_frames[1], vec_frames[2], vec_frames[3]),
                      Rect(pos_x, pos_y, vec_frames[2], vec_frames[3]));
    }
}

void Frame::copy(bool flip, int pos_x, int pos_y, int area_x, int area_y) {
    sprite.SetAlphaMod(255);
    if (flip) {
        renderer.Copy(sprite, Rect(vec_frames[0], vec_frames[1], vec_frames[2], vec_frames[3]),
                      Rect(pos_x, renderer.GetOutputHeight() - pos_y - SCALING_VALUE_PIXEL * area_y,
                           area_x, area_y),
                      180.0, NullOpt, 2);
    } else {
        renderer.Copy(sprite, Rect(vec_frames[0], vec_frames[1], vec_frames[2], vec_frames[3]),
                      Rect(SCALING_VALUE_PIXEL * pos_x,
                           renderer.GetOutputHeight() - SCALING_VALUE_PIXEL * pos_y -
                                   SCALING_VALUE_PIXEL * area_y,
                           SCALING_VALUE_PIXEL * area_x, SCALING_VALUE_PIXEL * area_y));
    }
}


void Frame::setFrame(int x, int y, int w, int h) {
    vec_frames.emplace_back(x);
    vec_frames.emplace_back(y);
    vec_frames.emplace_back(w);
    vec_frames.emplace_back(h);
}

Frame& Frame::operator=(const Frame& other) {
    if (this != &other) {  // Evita autoasignación
        renderer = std::move(other.renderer);
        sprite = std::move(other.sprite);
        vec_frames = other.vec_frames;
    }
    return *this;
}

int Frame::getX() { return vec_frames[0]; }
int Frame::getY() { return vec_frames[1]; }
int Frame::getW() { return vec_frames[2]; }
int Frame::getH() { return vec_frames[3]; }
