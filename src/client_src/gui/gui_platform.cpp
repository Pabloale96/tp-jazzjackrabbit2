#include "../../include/client_src/gui/gui_platform.h"

PlatformGui::PlatformGui(ClaseTexturas& texturas, const msgPlataforma& msg):
        texturas(texturas),
        pos_x(msg.plataforma[POS_POSX_PLATAFORMA]),
        pos_y(msg.plataforma[POS_POSY_PLATAFORMA]),
        flip(msg.flip),
        type(msg.tipo_plataforma),
        height(msg.plataforma[POS_HEIGHT_PLATAFORM]),
        width(msg.plataforma[POS_WIDTH_PLATAFORMA]),
        platform(texturas.findFrame(PLATFORM_BEACH_TYPE_1)->at(0)) {}

PlatformGui::~PlatformGui() {}

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
    if ((pos_x - dif_x < 30 && pos_x - dif_x > -30) ||
        (pos_y - dif_y < 14 && pos_y - dif_y > -14)) {
        platform.copy(rotate, abs(pos_x - dif_x) * SCALING_VALUE_PIXEL_X,
                      abs(pos_y - dif_y) * SCALING_VALUE_PIXEL_Y, width * SCALING_VALUE_PIXEL_X,
                      height * SCALING_VALUE_PIXEL_Y);
    }
}
