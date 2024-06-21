#ifndef GUI_PLATFORM_H
#define GUI_PLATFORM_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "../../common_src/defines_msg.h"
#include "../../common_src/msgToSent.h"

#include "gui_clase_texturas.h"
#include "gui_frame.h"

using SDL2pp::Renderer;
using SDL2pp::Texture;

class PlatformGui {
private:
    float pos_x;
    float pos_y;
    bool flip = false;
    int type = 0;
    int height;
    int width;
    std::shared_ptr<std::vector<Frame>>& platform;

public:
    explicit PlatformGui(ClaseTexturas&, const msgPlataforma&);
    ~PlatformGui();

    void show(float dif_x, float dif_y, int h_window, int w_window, int);
    float rotateToFloat();
    void setFrame(std::shared_ptr<Frame>&, int, int);
    bool checkIsInWindow(int, int, int, int);

    int getW() { return width; }
    int getH() { return height; }
    int getX() { return pos_x; }
    int getY() { return pos_y; }
};

#endif
