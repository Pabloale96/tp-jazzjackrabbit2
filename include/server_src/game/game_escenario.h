#ifndef _SERVER_GAME_ESCENARIO_H_
#define _SERVER_GAME_ESCENARIO_H_

#include <memory>
#include <vector>

#include "game_collectible.h"
#include "game_enemigo.h"
#include "game_platform.h"

#define NUMERO_INICIAL_ENEMIGOS 5
#define MONEDAS_PRIMERA_PLATAFORMA 5

class GameEscenario {
private:
    std::vector<std::unique_ptr<Enemigo>> enemigos;
    std::vector<Platform> plataformas;
    std::vector<std::unique_ptr<Collectible>> collectibles;

public:
    GameEscenario();

    std::unique_ptr<Enemigo> crear_enemigo_aleatorio();

    void actualizar_escenario();

    void actualizar_enemigos();

    bool aumentar_iteraciones();

    void actualizar_collectibles();

    std::vector<std::unique_ptr<Enemigo>>& obtener_enemigos();

    std::vector<Platform>& obtener_plataformas();

    std::vector<std::unique_ptr<Collectible>>& obtener_collectibles();

    ~GameEscenario();
};

#endif
