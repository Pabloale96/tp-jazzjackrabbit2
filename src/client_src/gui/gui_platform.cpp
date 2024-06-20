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

void PlatformGui::setFrame(std::shared_ptr<Frame>& frame_plat, int width_window,
                           int height_window) {
    platform = frame_plat;
    w_window = width_window;
    h_window = height_window;
}

bool PlatformGui::checkIsInWindow(int pos_camara_x, int pos_camara_y) {
    // Escalar las posiciones y dimensiones
    int pos_x_sc = static_cast<int>(pos_x * SCALING_VALUE_PIXEL_X);
    int pos_y_sc = static_cast<int>(pos_y * SCALING_VALUE_PIXEL_Y);
    int width_sc = static_cast<int>(width * SCALING_VALUE_PIXEL_X);
    int height_sc = static_cast<int>(height * SCALING_VALUE_PIXEL_Y);

    // Calcular los límites de la ventana en coordenadas del mundo
    int cam_left = pos_camara_x - (h_window / 2);
    int cam_right = pos_camara_x + (h_window / 2);
    int cam_top = pos_camara_y - (w_window / 2);
    int cam_bottom = pos_camara_y + (w_window / 2);

    // Verificar si cualquier parte de la plataforma está dentro de los límites de la ventana
    bool in_window =
            ((pos_x_sc + width_sc >=
              cam_left) &&               // La plataforma no está completamente a la izquierda
             (pos_x_sc <= cam_right) &&  // La plataforma no está completamente a la derecha
             (pos_y_sc + height_sc >= cam_top) &&  // La plataforma no está completamente arriba
             (pos_y_sc <= cam_bottom));            // La plataforma no está completamente abajo

    return in_window;
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

    if (flip) {
        rot = 135;
    }
    // rot += 180;
    return rot;
}

void PlatformGui::show(int dif_x, int dif_y, int i) {

    float rotate = this->rotateToFloat();

    // Escalar las dimensiones de la plataforma
    int width_sc = static_cast<int>(width * SCALING_VALUE_PIXEL_X);
    int height_sc = static_cast<int>(height * SCALING_VALUE_PIXEL_Y);

    // Calcular la posición de la plataforma en relación a la cámara
    int posicion_x = static_cast<int>((pos_x - dif_x) * SCALING_VALUE_PIXEL_X) + h_window / 2;
    int posicion_y = static_cast<int>((pos_y - dif_y) * SCALING_VALUE_PIXEL_Y) + w_window / 2;

    // Invertir la coordenada Y si la ventana usa un origen en la esquina superior izquierda
    int posicion_y_invertida = w_window - posicion_y;

    // Comprobar si la plataforma está dentro de la ventana
    if (this->checkIsInWindow(dif_x * SCALING_VALUE_PIXEL_X, dif_y * SCALING_VALUE_PIXEL_Y)) {
        std::cout << "Se imprime la plataforma " << i << " con posicion:" << std::endl;
        std::cout << "(pos_x, pos_y, width, height)"
                  << "(" << pos_x << " , " << pos_y << " , " << width << " , " << height << ")"
                  << std::endl;
        std::cout << "(porsicion_x, posicion_y, width_sc, height_sc)"
                  << "(" << posicion_x << " , " << posicion_y_invertida << " , " << width_sc
                  << " , " << height_sc << ")" << std::endl;
        if (rotate == 0) {
            platform->copy(rotate, posicion_x, posicion_y_invertida, width_sc, height_sc);
        } else if (rotate == 90) {
            platform->copy(rotate, posicion_x - height_sc / 2, posicion_y_invertida + width_sc / 2,
                           height_sc, width_sc);
        } else {
            // Calcular la nueva posición después de la rotación
            std::cout << "Se imprime la plataforma " << i << " con posicion:" << std::endl;
            std::cout << "rotacion:" << rotate << std::endl;
            double rad = rotate * M_PI / 180.0;
            double offsetX = width * (1 - cos(rad));
            double offsetY =
                    width * sin(rad);  // Ajustar la posición para que la plataforma parezca estar
                                       // en la misma posición después de la rotación
            int newX = (rotate == 135) ? (posicion_x - offsetX) :
                                         (posicion_x - h_window / 2 - offsetX);
            int newY = (rotate == 135) ? (posicion_y_invertida - w_window / 2 - offsetY) :
                                         (posicion_y_invertida - offsetY);
            platform->copy(rotate, newX, newY, width_sc, height_sc);
        }
    }
}
