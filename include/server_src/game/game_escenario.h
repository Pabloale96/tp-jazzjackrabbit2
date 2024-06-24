#ifndef _SERVER_GAME_ESCENARIO_H_
#define _SERVER_GAME_ESCENARIO_H_

#include <memory>
#include <vector>

#include "game_collectible.h"
#include "game_enemigo.h"
#include "game_platform.h"
#include "vector_monitor.h"

class GameEscenario {
private:
    std::vector<Platform> plataformas;
    std::vector<Plataforma> plataformas_server;
    VectorMonitor<std::shared_ptr<Enemigo>> enemigos;
    VectorMonitor<std::shared_ptr<Collectible>> collectibles;
    uint16_t id_enemigo;
    uint16_t id_collectible;

public:
    GameEscenario();

    uint16_t generar_id_enemigo();

    uint16_t generar_id_collectible();

    void cargar_plataformas();

    void cargar_enemigos();

    void cargar_collectibles();

    void crear_enemigo_aleatorio(uint16_t id_enemigo);

    void actualizar_escenario();

    void actualizar_enemigos();

    bool aumentar_iteraciones();

    void actualizar_collectibles();

    const VectorMonitor<std::shared_ptr<Enemigo>>& obtener_enemigos();

    std::vector<Platform>& obtener_plataformas();

    std::vector<Plataforma>& obtener_plataformas_server() { return plataformas_server; }

    const VectorMonitor<std::shared_ptr<Collectible>>& obtener_collectibles();

    ~GameEscenario();
};

#endif
