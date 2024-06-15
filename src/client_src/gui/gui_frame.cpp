#include "../../include/client_src/gui/gui_frame.h"

Frame::Frame(Renderer& renderer, Texture& sprite): renderer(renderer), sprite(sprite) {}

Frame::Frame(Renderer& renderer, Texture& sprite, int x, int y, int w, int h):
        renderer(renderer), sprite(sprite), vec_frames{x, y, h, w} {


    // this->setFrame(x, y, w, h);
}


Frame::~Frame() {}

void Frame::copy(bool flip, int pos_x, int pos_y) {
    sprite.SetAlphaMod(255);
    if (flip) {
        renderer.Copy(sprite, Rect(vec_frames[0], vec_frames[1], vec_frames[2], vec_frames[3]),
                      Rect(pos_x, pos_y, vec_frames[2], vec_frames[3]), 180.0, NullOpt, 2);
    } else {
        renderer.Copy(sprite, Rect(vec_frames[0], vec_frames[1], vec_frames[2], vec_frames[3]),
                      Rect(pos_x, pos_y, vec_frames[2], vec_frames[3]));
    }
}

void Frame::copy(float rotate, int pos_x, int pos_y, int area_x, int area_y) {
    sprite.SetAlphaMod(255);
    renderer.Copy(sprite, Rect(vec_frames[0], vec_frames[1], vec_frames[2], vec_frames[3]),
                    Rect(renderer.GetOutputWidth()/2 - pos_x, renderer.GetOutputHeight()/2- pos_y, area_x, area_y), rotate, NullOpt, 2);
}

void Frame::copyTest() {
    renderer.Copy(sprite, Rect(vec_frames[0], vec_frames[1], vec_frames[2], vec_frames[3]),
                  Rect(renderer.GetOutputWidth() / 2, renderer.GetOutputHeight() / 2, 75, 75));
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
