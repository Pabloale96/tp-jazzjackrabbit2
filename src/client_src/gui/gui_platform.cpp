#include "../../include/client_src/gui/gui_platform.h"


PlatformGui::PlatformGui(ClaseTexturas& texturas, int pos_x, int pos_y,
            int rotate, bool flip, int type, int height, int width):
        texturas(texturas),
        pos_x(pos_x),
        pos_y(pos_y),
        rotate(rotate),
        flip(flip),
        type(type),
        height(height),
        width(width)  {}

PlatformGui::PlatformGui(ClaseTexturas& texturas, const msgPlataforma & msg):
        texturas(texturas),
        pos_x(msg.plataforma[POS_POSX_PLATAFORMA]),
        pos_y(msg.plataforma[POS_POSY_PLATAFORMA]),
        rotate(msg.plataforma[POS_ROTATE_PLATAFORM]),
        flip(msg.plataforma[POS_POSX_PLATAFORMA]),
        type(msg.plataforma[POS_TIPO_PLATAFORMA]),
        height(msg.plataforma[POS_HEIGHT_PLATAFORM]),
        width(msg.plataforma[POS_WIDTH_PLATAFORMA]) {}

PlatformGui::~PlatformGui() {}

void PlatformGui::show(int dif_x, int dif_y) {
    pos_x += dif_x;
    pos_y += dif_y;
    //platform.copy(flip, pos_x, pos_y, 500, 30);
}
