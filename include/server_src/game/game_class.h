#ifndef _SERVER_GAME_H_
#define _SERVER_GAME_H_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "game_escenario.h"
#include "game_personaje.h"
#include "game_state.h"

class Game {
private:
    uint16_t partida_id;
    // TODO: unorderedmap sería más rápido
    std::vector<std::shared_ptr<Personaje>> personajes;
    GameEscenario escenario;

public:
    explicit Game(uint16_t partida_id, uint16_t client_id, uint8_t personaje);

    std::vector<std::shared_ptr<Personaje>>& obtener_vector_de_personajes();

    Personaje& obtener_personaje(uint16_t client_id);

    bool mover(const std::string& direccion, uint16_t client_id);

    void accion_especial(uint16_t client_id);

    bool atacar_enemigo(uint16_t client_id, uint16_t id_enemigo);

    void actualizar();

    void actualizar_personajes();

    void actualizar_escenario();

    bool aumentar_iteraciones();

    void crear_nuevo_gamestate(GameState& gamestate);

    void agregar_personaje(uint16_t client_id, uint8_t personaje);

    void borrar_personaje(uint16_t client_id);

    GameEscenario& obtener_escenario();

    ~Game();
};

#endif
