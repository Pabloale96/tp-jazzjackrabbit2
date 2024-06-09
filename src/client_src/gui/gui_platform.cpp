#include "../../include/client_src/gui/gui_platform.h"

PlatformGui::PlatformGui(ClaseTexturas& texturas, const msgPlataforma& msg):
        texturas(texturas),
        pos_x(msg.plataforma[POS_POSX_PLATAFORMA]),
        pos_y(msg.plataforma[POS_POSY_PLATAFORMA]),
        rotate(msg.plataforma[POS_ROTATE_PLATAFORM]),
        flip(msg.plataforma[POS_POSX_PLATAFORMA]),
        type(msg.plataforma[POS_TIPO_PLATAFORMA]),
        height(msg.plataforma[POS_HEIGHT_PLATAFORM]),
        width(msg.plataforma[POS_WIDTH_PLATAFORMA]),
        platform(texturas.findFrame(PLATFORM_BEACH_TYPE_1)[0]) {}

PlatformGui::~PlatformGui() {}

void PlatformGui::show() { platform.copy(flip, pos_x, pos_y, width, height); }
