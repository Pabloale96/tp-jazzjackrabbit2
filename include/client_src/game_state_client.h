#ifndef __GAMESTATE_CLIENT_H__
#define __GAMESTATE_CLIENT_H__

#include <map>
#include <memory>
#include <utility>
#include <vector>

#include "gui/gui_enemigos.h"
#include "gui/gui_personaje.h"
#include "gui/gui_coleccionables.h"
#include "gui/gui_platform.h"

#include "msgToSent.h"
#include "queue.h"

class GameStateClient {
private:
    bool jugando;

    std::shared_ptr<ClaseTexturas>& texturas;

    std::vector<PlatformGui> plataformas;

    std::map<uint16_t, PersonajeGui> diccionario_de_personajes;
    std::map<uint16_t, EnemigosGui> diccionario_de_enemigos;
    std::map<uint16_t, ColecionablesGui> diccionario_de_collecionables;


public:
    explicit GameStateClient(std::shared_ptr<ClaseTexturas>&,bool jugando);

    bool obtener_estado_de_la_partida();

    std::map<uint16_t, PersonajeGui> obtener_diccionario_de_personajes()const;

    std::map<uint16_t, EnemigosGui> obtener_diccionario_de_enemigos()const;

    std::vector<PlatformGui> & obtener_plataformas();

    PersonajeGui& obtener_personaje(uint16_t client_id);

    bool getJugando() const { return jugando; }

    int getSizePersonajes() { return diccionario_de_personajes.size(); }

    int get_cantidad_de_enemigos() { return diccionario_de_enemigos.size(); }

    void setGameState(const uint8_t& state_partida) { jugando = ((unsigned)state_partida == 0x01); }

    void pushPersonajes(msgPersonaje& msgpers);

    void pushEnemigos(msgEnemigo& msgenem);

    void pushPlataformas(msgPlataforma& msgplat);

    void imprimir_cliente() {
        for (const auto& pair: diccionario_de_personajes) {
            std::cout << " >> Personaje " << std::endl;
            std::cout << "     - Posición: (" << pair.second.obtener_posicion_x() << ", "
                      << pair.second.obtener_posicion_y() << ")." << std::endl;
            std::cout << "     - Estado: " << (unsigned)pair.second.obtener_estado_actual()
                      << std::endl;
            std::cout << "     - Tipo: " << (unsigned)pair.second.obtener_tipo_personaje()
                      << std::endl;
        }
    }

    void actualizar_gamestate(const GameStateClient&);

    ~GameStateClient();
};

#endif
