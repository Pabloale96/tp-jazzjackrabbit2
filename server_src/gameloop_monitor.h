#ifndef _GAMELOOP_MONITOR_H
#define _GAMELOOP_MONITOR_H

#include <map>
#include <string>
#include <utility>  // move()
#include <memory>  // shared_ptr()

#include "../server_src/gameloop_class.h"
#include "../common_src/common_queue.h"
#include "../server_src/game_comandos.h"

#define ID_INICIAL 0

class GameloopMonitor {
private:
    std::mutex m;
    std::map<uint16_t, GameLoop*> diccionario_de_gameloops;
    uint16_t gameloop_id;

public:
    GameloopMonitor();

    uint16_t agregar_gameloop();

    GameLoop* obtener_gameloop(uint16_t gameloop_id);

    Queue<std::shared_ptr<Comando>>& obtener_queue_de_client_commands(uint16_t gameloop_id);

    ~GameloopMonitor();
};

#endif
