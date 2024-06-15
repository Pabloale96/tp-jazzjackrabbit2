#ifndef __GAMESTATE_CLIENT_H__
#define __GAMESTATE_CLIENT_H__

#include <memory>
#include <vector>

#include "gui/gui_personaje.h"
#include "gui/gui_enemigos.h"
#include "queue.h"
#include "msgToSent.h"

class GameStateClient {
private:
    uint16_t partida_id;
    bool jugando;
    std::map<uint16_t, std::shared_ptr<PersonajeGui>> diccionario_de_personajes;
    std::map<uint16_t, EnemigosGui> diccionario_de_enemigos;


public:
    explicit GameStateClient(uint16_t partida_id, bool jugando);

    bool obtener_estado_de_la_partida();

    std::map<uint16_t, std::shared_ptr<PersonajeGui>>& obtener_diccionario_de_personajes();

    std::map<uint16_t, EnemigosGui>& obtener_diccionario_de_enemigos();

    std::shared_ptr<PersonajeGui>& obtener_personaje(uint16_t client_id);

    bool getJugando() { return jugando; }

    int getSizePersonajes() { return diccionario_de_personajes.size(); }

    int get_cantidad_de_enemigos() { return diccionario_de_enemigos.size(); }

    void setGameState(const uint8_t& state_partida) { jugando = (state_partida == 0x01); }

    void pushPersonajes(msgPersonaje& msgpers);

    void pushEnemigos(uint16_t* msgenem) {
        EnemigosGui enemigo(msgenem);
        diccionario_de_enemigos.emplace(enemigo.get_id_enemigo(), enemigo);
    }

    ~GameStateClient();
};

#endif
