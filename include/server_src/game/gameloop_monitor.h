#ifndef _GAMELOOP_MONITOR_H
#define _GAMELOOP_MONITOR_H

#include <list>
#include <map>
#include <memory>  // shared_ptr()
#include <string>
#include <utility>  // move()

#include "game_comandos.h"
#include "gameloop_class.h"
#include "queue.h"

#define ID_GAMELOOP_INICIAL 1

class GameloopMonitor {
private:
    std::mutex m;
    uint16_t gameloop_id;
    std::map<uint16_t, GameLoop*> diccionario_de_gameloops;
    uint16_t id_cliente;

public:
    GameloopMonitor();

    uint16_t crear_nuevo_id_cliente();

    uint16_t crear_gameloop(std::string nombre_partida, uint16_t client_id, uint8_t personaje);

    void obtener_partidas_disponibles(std::map<uint16_t, std::string>& partidas_disponibles);

    void agregar_cliente_al_gameloop(uint16_t gameloop_id, uint16_t client_id);

    GameLoop* obtener_gameloop(uint16_t gameloop_id);

    Queue<std::shared_ptr<Comando>>& obtener_queue_de_client_commands(uint16_t gameloop_id);

    void borrar_cliente_de_gameloop(uint16_t gameloop_id, uint16_t client_id);

    ~GameloopMonitor();
};

#endif
