#include "../../include/client_src/gui/gui_platform.h"

PlatformGui::PlatformGui(const msgPlataforma& msg):
        pos_x(msg.plataforma[POS_POSX_PLATAFORMA]),
        pos_y(msg.plataforma[POS_POSY_PLATAFORMA]),
        flip(msg.flip),
        type(msg.tipo_plataforma),
        height(msg.plataforma[POS_HEIGHT_PLATAFORM]),
        width(msg.plataforma[POS_WIDTH_PLATAFORMA]),
        platform(nullptr) {}

PlatformGui::~PlatformGui() {}

void PlatformGui::setFrame(std::shared_ptr<Frame>& frame_plat, int width, int heigth) {
    platform=frame_plat;
    w_window = width;
    h_window = heigth;
}

float PlatformGui::rotateToFloat() {

    float rot = 0;
    switch (type) {
        case static_cast<int>(platform::DIAGONAL):
            rot = 45;
            break;
        case static_cast<int>(platform::VERTICAL):
            rot = 90;
            break;
        default:
            break;
    }

    if (!flip) {
        rot += 180;
    }
    return rot;
}

void PlatformGui::show(int dif_x, int dif_y) {
    float rotate = this->rotateToFloat();
    if (((dif_x - pos_x)  < 30 && (dif_x - pos_x)  > -30) ||
        ((dif_y - pos_y) < 14 && (dif_y - pos_y) > -14)) {
        platform->copy(rotate, (dif_x - pos_x) * SCALING_VALUE_PIXEL_X +w_window/2,
                      (dif_y - pos_y) * SCALING_VALUE_PIXEL_Y+h_window/2, width * SCALING_VALUE_PIXEL_X,
                      height * SCALING_VALUE_PIXEL_Y);
    }
}
