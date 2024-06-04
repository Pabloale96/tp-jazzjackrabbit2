#include "../../include/client_src/gui/gui_platform.h"


PlatformGui::PlatformGui(Renderer& render, Texture& sprite, int pos_x, int pos_y):
        renderer(render), sprites(sprite), pos_x(pos_x), pos_y(pos_y) {}
PlatformGui::~PlatformGui() {}

void PlatformGui::show(int dif_x, int dif_y) {
    pos_x += dif_x;
    pos_y += dif_y;
    platform.copy(flip, pos_x, pos_y, 500, 30);
}

