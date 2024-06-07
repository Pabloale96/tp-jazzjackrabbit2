#ifndef _SERVER_GAME_H_
#define _SERVER_GAME_H_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "game_enemigo.h"
#include "game_personaje.h"
#include "game_platform.h"
#include "game_state.h"

#define NUMERO_INICIAL_ENEMIGOS 5

#define XMAX 200
#define YMAX 200

class Game {
private:
    uint16_t partida_id;
    // TODO: Clase escenario que contenga a los personajes y enemigos ?
    // TODO: unorderedmap sería más rápido
    std::vector<std::unique_ptr<Personaje>> personajes;
    std::vector<std::unique_ptr<Enemigo>> enemigos;
    std::vector<Platform> plataformas;
    // Pared? Piso?

public:
    explicit Game(uint16_t partida_id, uint16_t client_id, const std::string& personaje);

    std::vector<std::unique_ptr<Personaje>>& obtener_vector_de_personajes();

    std::unique_ptr<Enemigo> crear_enemigo_aleatorio();

    Personaje& obtener_personaje(uint16_t client_id);

    bool mover(const std::string& direccion, uint16_t client_id);

    void accion_especial(uint16_t client_id);

    bool atacar_enemigo(uint16_t client_id);

    void actualizar_posiciones();

    void actualizar_personajes();

    void actualizar_enemigos();

    bool aumentar_iteraciones();

    void crear_nuevo_gamestate(GameState& gamestate);

    void agregar_personaje(uint16_t client_id, const std::string& personaje);

    void borrar_personaje(uint16_t client_id);

    std::vector<Platform> obtener_plataformas();

    ~Game();
};

#endif
