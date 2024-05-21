#ifndef __MONITOR_SERVER_H__
#define __MONITOR_SERVER_H__

#include <memory>
#include <vector>

#include "../common_src/common_queue.h"
#include "../server_src/game_state.h"

class ServerMonitor {
private:
    std::mutex m;
    std::vector<Queue<std::shared_ptr<GameState>>*> vector_de_server_msg;

public:
    ServerMonitor();

    void agregar_queue(Queue<std::shared_ptr<GameState>>& queue);

    void broadcastear(const GameState& msg);

    void borrar_queue(Queue<std::shared_ptr<GameState>>& queue);

    ~ServerMonitor();
};

#endif
