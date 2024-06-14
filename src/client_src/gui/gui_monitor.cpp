#include "../include/client_src/gui/gui_monitor.h"


GuiMonitor::GuiMonitor(bool& client_off, std::string& personaje, Queue<msgAccion>& client_commands, std::vector<msgPlataforma>& plataformas, uint16_t& client_id):
        gui(0, 0, std::ref(client_off), std::ref(personaje), std::ref(client_commands), plataformas,
            client_id){}

GuiMonitor::~GuiMonitor(){}

void GuiMonitor::run() {
        gui.run();
}
void GuiMonitor::setGameState(GameState& gameState){
        std::unique_lock<std::mutex> lock(m);
        gui.setGameState(gameState);
}
void GuiMonitor::setEscenario(ClaseTexturas& escenario){
        std::unique_lock<std::mutex> lock(m);
        gui.setEscenario(escenario);
}

void GuiMonitor::stop(){
        gui.stop();
}

void GuiMonitor::join(){
        gui.join();
}

void GuiMonitor::start(){
        gui.start();
}