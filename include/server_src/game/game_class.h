#ifndef _SERVER_GAME_H_
#define _SERVER_GAME_H_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "game_escenario.h"
#include "game_personaje.h"
#include "game_state.h"
#include "vector_monitor.h"

class Game {
private:
    uint16_t partida_id;
    // TODO: unorderedmap sería más rápido
    VectorMonitor<std::shared_ptr<Personaje>> personajes;
    GameEscenario escenario;
    std::mutex m;

public:
    explicit Game(uint16_t partida_id, uint16_t client_id, uint8_t personaje);

    std::vector<std::shared_ptr<Personaje>>& obtener_vector_de_personajes();

    Personaje& obtener_personaje(uint16_t client_id);

    size_t obtener_cantidad_de_personajes();

    bool mover(const std::string& direccion, uint16_t client_id);

    void accion_especial(uint16_t client_id);

    bool disparar_municion(uint16_t client_id);

    void chequear_colisiones();

    void chequear_colisiones_personaje_con_plataforma(Personaje& personaje);

    bool colision_horizontal(const Personaje& personaje, const Plataforma& plataforma);

    bool colision_vertical(const Personaje& personaje, const Plataforma& plataforma);

    bool colision_vertical_por_izquierda(const Personaje& personaje, const Plataforma& plataforma);

    bool colision_vertical_por_derecha(const Personaje& personaje, const Plataforma& plataforma);

    bool colision_diagonal(const Personaje& personaje, const Plataforma& plataforma);

    void chequear_colisiones_personaje_con_enemigo(Personaje& personaje);

    void chequear_colisiones_balas_con_enemigos(Personaje& personaje);

    void chequear_colisiones_personaje_con_collectible(Personaje& personaje);

    void actualizar(std::chrono::seconds tiempo_restante_de_partida);

    void actualizar_personajes(std::chrono::seconds tiempo_restante_de_partida);

    void actualizar_escenario();

    bool aumentar_iteraciones();

    void crear_nuevo_gamestate(GameState& gamestate);

    void agregar_personaje(uint16_t client_id, uint8_t personaje,
                           std::chrono::seconds tiempo_restante_de_partida);

    void borrar_personaje(uint16_t client_id);

    GameEscenario& obtener_escenario();

    void cheat_matar_todos_los_enemigos();

    ~Game();
};

#endif
