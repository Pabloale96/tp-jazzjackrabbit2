#ifndef _GAMELOOP_H_
#define _GAMELOOP_H_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "../common_src/common_queue.h"
#include "../common_src/common_thread.h"
#include "../server_src/game_comandos.h"
#include "../server_src/game_class.h"
#include "../server_src/game_state_monitor.h"

class GameLoop: public Thread {
private:
    Queue<std::shared_ptr<Comando>> client_commands;
    GameStateMonitor monitor_lista_de_queues_server_msg;
    Game game;
    // una lista de personajes por client id ?

public:
    // Constructor
    // Crea una cola de comandos de clientes y un vector de 5 enemigos
    GameLoop();

    // Devuelve la cola de comandos de clientes
    Queue<std::shared_ptr<Comando>>& obtener_queue_de_client_commands();

    // Agrega una cola de mensajes del servidor de un cliente aceptado al vector
    // de colas
    void agregar_queue_server_msg_de_cliente_aceptado(
            Queue<std::shared_ptr<GameState>>& nueva_queue);

    // Popea un comando de la cola de comandos de clientes y lo procesa
    void run() override;

    // Broadcastea un mensaje a todos los clientes
    void broadcastear();

    // Duerme el hilo por 200 segundos
    void dormir();

    void borrar_queue_server_msg_de_cliente_aceptado(
            Queue<std::shared_ptr<GameState>>& queue);

    // Cierra la cola de comandos de clientes
    // Cierra las colas de mensajes de los clientes
    void stop() override;

    // Destructor
    ~GameLoop();
};

#endif
