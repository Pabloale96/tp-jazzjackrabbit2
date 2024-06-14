#include "../../include/client_src/gui/gui_platform.h"

PlatformGui::PlatformGui(ClaseTexturas& texturas, const msgPlataforma& msg):
        texturas(texturas),
        pos_x(msg.plataforma[POS_POSX_PLATAFORMA]),
        pos_y(msg.plataforma[POS_POSY_PLATAFORMA]),
        rotate(msg.rotate),
        flip(msg.plataforma[POS_FLIP_PLATAFORMA]),
        type(msg.tipo_plataforma),
        height(msg.plataforma[POS_HEIGHT_PLATAFORM]),
        width(msg.plataforma[POS_WIDTH_PLATAFORMA]),
        platform(texturas.findFrame(PLATFORM_BEACH_TYPE_1)->at(0)) {}

PlatformGui::~PlatformGui() {}

void PlatformGui::show(int dif_x, int dif_y) {
    platform.copy(flip, pos_x - dif_x, pos_y - dif_y, width, height);
}
