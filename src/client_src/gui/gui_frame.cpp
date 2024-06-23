#include "../../include/client_src/gui/gui_frame.h"

#include <cassert>

Frame::Frame(Renderer& renderer, Texture& sprite): renderer(renderer), sprite(sprite), vec_frames{0, 0, 0, 0} {}

Frame::Frame(Renderer& renderer, Texture& sprite, int x, int y, int w, int h):
        renderer(renderer), sprite(sprite), vec_frames{x, y, h, w} {}

void Frame::copy(bool flip, int pos_x, int pos_y) {
    //sprite.SetAlphaMod(255);

    // assert(vec_frames.size() == 4);

    std::cout << "copiando frame con "<< flip << " desde x: " << pos_x << " y: " << pos_y << std::endl;
    std::cout << "Frame: " << vec_frames[0] << std::endl;
    std::cout << vec_frames[1] << std::endl;
    std::cout << vec_frames[2] << std::endl;
    std::cout << vec_frames[3] << std::endl;

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
                  Rect(pos_x, pos_y, area_x, area_y), rotate, NullOpt, 2);
}

void Frame::copyTest() {
    renderer.Copy(sprite, Rect(vec_frames[0], vec_frames[1], vec_frames[2], vec_frames[3]),
                  Rect(0, 0, 75, 75), 315, NullOpt, 2);
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

Frame::~Frame() {}
