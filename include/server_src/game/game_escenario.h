#ifndef _SERVER_GAME_ESCENARIO_H_
#define _SERVER_GAME_ESCENARIO_H_

#include <memory>
#include <vector>

#include "game_collectible.h"
#include "game_enemigo.h"
#include "game_platform.h"
#include "vector_monitor.h"

#define NUMERO_INICIAL_ENEMIGOS 5
#define MONEDAS_PRIMERA_PLATAFORMA 5

class GameEscenario {
private:
    VectorMonitor<std::shared_ptr<Enemigo>> enemigos;
    std::vector<Platform> plataformas;
    VectorMonitor<std::shared_ptr<Collectible>> collectibles;

public:
    GameEscenario();

    void cargar_plataformas();

    void cargar_enemigos();

    void cargar_collectibles();

    void crear_enemigo_aleatorio(uint16_t id_enemigo);

    void actualizar_escenario();

    void actualizar_enemigos();

    bool aumentar_iteraciones();

    void actualizar_collectibles();

    std::vector<std::shared_ptr<Enemigo>>& obtener_enemigos();

    std::vector<Platform>& obtener_plataformas();

    std::vector<std::shared_ptr<Collectible>>& obtener_collectibles();

    ~GameEscenario();
};

#endif
