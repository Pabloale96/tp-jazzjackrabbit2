#include "../../include/escenario.h"

Escenario::Escenario(Renderer& render): renderer(render) {}
Escenario::~Escenario() {}

void Escenario::show(int dif_x, int dif_y) {
    platform1.show(dif_x, dif_y);
    platform2.show(dif_x, dif_y);
    platform3.show(dif_x, dif_y);
    platform4.show(dif_x, dif_y);
    platform5.show(dif_x, dif_y);
    platform6.show(dif_x, dif_y);
    platform7.show(dif_x, dif_y);
    platform_1.show(dif_x, dif_y);
    platform_2.show(dif_x, dif_y);
    platform_3.show(dif_x, dif_y);
    platform_4.show(dif_x, dif_y);
    platform_5.show(dif_x, dif_y);
    platform_6.show(dif_x, dif_y);
    platform_7.show(dif_x, dif_y);
}
