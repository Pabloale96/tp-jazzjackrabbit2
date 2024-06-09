#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "game_enemigo.h"
#include "game_personaje.h"


struct msgPersonaje;

class GameState {
private:
    uint16_t partida_id;
    bool jugando;
    std::map<uint16_t, std::shared_ptr<Personaje>> diccionario_de_personajes;
    std::map<uint16_t, Enemigo> diccionario_de_enemigos;


public:
    explicit GameState(uint16_t partida_id, bool jugando);

    bool obtener_estado_de_la_partida();

    std::map<uint16_t, std::shared_ptr<Personaje>>& obtener_diccionario_de_personajes();

    std::map<uint16_t, Enemigo>& obtener_diccionario_de_enemigos();

    std::shared_ptr<Personaje>& obtener_personaje(uint16_t client_id);

    bool getJugando() { return jugando; }

    int getSizePersonajes() { return diccionario_de_personajes.size(); }

    int get_cantidad_de_enemigos() { return diccionario_de_enemigos.size(); }

    void setGameState(const uint8_t& state_partida) { jugando = (state_partida == 0x01); }

    void pushPersonajes(msgPersonaje& msgpers);

    void pushEnemigos(uint16_t* msgenem) {
        Enemigo enemigo(msgenem);
        diccionario_de_enemigos.emplace(enemigo.get_id_enemigo(), enemigo);
    }

    void imprimir_mensaje();

    ~GameState();
};

#endif
