#ifndef _GUI_MONITOR_H
#define _GUI_MONITOR_H

#include <list>
#include <map>
#include <memory>  // shared_ptr()
#include <string>
#include <utility>  // move()

#include "gui.h"

class GuiMonitor {
private:
    std::mutex m;
    Gui gui;

public:
    GuiMonitor(bool&, std::string&, Queue<msgAccion>&, std::vector<msgPlataforma>&, uint16_t&);
    ~GuiMonitor();
    void run();
    void setGameState(GameState&);
    void setEscenario(ClaseTexturas&);
    void stop();

    void join();

    void start();
};

#endif
