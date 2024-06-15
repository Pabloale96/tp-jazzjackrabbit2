#ifndef __CLIENT_GAME_STATE_MONITOR_H__
#define __CLIENT_GAME_STATE_MONITOR_H__

#include <map>
#include <memory>
#include <vector>

#include "game_state_client.h"
#include "msgToSent.h"
#include "queue.h"

class GameStateMonitorClient {
private:
    std::mutex m;
    GameStateClient gamestate;

public:
    GameStateMonitorClient();

    std::map<uint16_t, std::shared_ptr<PersonajeGui>>& obtener_diccionario_de_personajes();

    std::map<uint16_t, EnemigosGui>& obtener_diccionario_de_enemigos();

    std::shared_ptr<PersonajeGui>& obtener_personaje(uint16_t client_id);

    void setGameState(const uint8_t& state_partida);

    void pushPersonajes(msgPersonaje&);

    void pushEnemigos(uint16_t*);

    bool getJugando();

    ~GameStateMonitorClient();
};

#endif
