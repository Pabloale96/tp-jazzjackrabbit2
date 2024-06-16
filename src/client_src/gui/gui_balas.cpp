#include "../../include/client_src/gui/gui_balas.h"

BalasGui::BalasGui(std::shared_ptr<std::vector<Frame>> frames, int x , int y):
    frames(frames), pos_x(x), pos_y(y), it(frames->begin()){}
BalasGui::~BalasGui(){}
void BalasGui::show(){
    animacion.run(pos_x, pos_y, speed, frames, it);
}