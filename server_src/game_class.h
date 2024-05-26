#ifndef _SERVER_GAME_H_
#define _SERVER_GAME_H_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "../server_src/game_enemigo.h"
#include "../server_src/game_personaje.h"
#include "../server_src/game_state.h"

#define NUMERO_INICIAL_ENEMIGOS 5

class Game {
private:
    // TODO: Clase escenario que contenga a los personajes y enemigos ?
    // TODO: unorderedmap sería más rápido
    std::vector<Personaje> personajes;
    std::vector<Enemigo> enemigos;
    // Pared? Piso?

public:
    explicit Game(uint16_t client_id);

    std::vector<Personaje> obtener_vector_de_personajes();

    Personaje& obtener_personaje(uint16_t client_id);

    bool mover(const std::string& direccion, uint16_t client_id);

    bool matar_enemigo();

    bool aumentar_iteraciones();

    void crear_nuevo_gamestate(GameState& gamestate);

    uint16_t obtener_cant_vivos();

    uint16_t obtener_cant_muertos();

    ~Game();
};

#endif
