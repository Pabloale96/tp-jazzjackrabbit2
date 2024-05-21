#ifndef __GAME_STATE_MONITOR_H__
#define __GAME_STATE_MONITOR_H__

#include <memory>
#include <vector>

#include "../common_src/common_queue.h"
#include "../server_src/game_state.h"

class GameStateMonitor {
private:
    std::mutex m;
    std::vector<Queue<std::shared_ptr<GameState>>*> vector_de_server_msg;

public:
    GameStateMonitor();

    void agregar_queue(Queue<std::shared_ptr<GameState>>& queue);

    void broadcastear(const GameState& msg);

    void borrar_queue(Queue<std::shared_ptr<GameState>>& queue);

    ~GameStateMonitor();
};

#endif
