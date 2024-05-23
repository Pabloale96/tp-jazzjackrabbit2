#ifndef _GAMELOOP_MONITOR_H
#define _GAMELOOP_MONITOR_H

#include <list>
#include <map>
#include <memory>  // shared_ptr()
#include <string>
#include <utility>  // move()

#include "../common_src/common_queue.h"
#include "../server_src/game_comandos.h"
#include "../server_src/gameloop_class.h"

#define ID_INICIAL 0

class GameloopMonitor {
private:
    std::mutex m;
    std::map<uint16_t, GameLoop*> diccionario_de_gameloops;
    uint16_t gameloop_id;
    std::list<uint16_t> clients_ids;

public:
    GameloopMonitor();

    uint16_t agregar_gameloop();

    void agregar_cliente_al_gameloop(uint16_t gameloop_id, uint16_t client_id);

    GameLoop* obtener_gameloop(uint16_t gameloop_id);

    Queue<std::shared_ptr<Comando>>& obtener_queue_de_client_commands(uint16_t gameloop_id);

    ~GameloopMonitor();
};

#endif
