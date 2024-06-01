#include "../../include/escenario.h"

Escenario::Escenario(Renderer& render): renderer(render) {}
Escenario::~Escenario() {}

void Escenario::show(int dif_x,int dif_y){
    platform1.show(dif_x,dif_y);
}
