#ifndef __GAMESTATE_CLIENT_H__
#define __GAMESTATE_CLIENT_H__

#include <map>
#include <memory>
#include <utility>
#include <vector>

#include "gui/gui_balas.h"
#include "gui/gui_coleccionables.h"
#include "gui/gui_enemigos.h"
#include "gui/gui_personaje.h"
#include "gui/gui_platform.h"

#include "msgToSent.h"
#include "queue.h"

class GameStateClient {
private:
    ClaseTexturas& texturas;
    bool jugando;
    std::vector<PlatformGui> plataformas;

    std::map<uint16_t, PersonajeGui> diccionario_de_personajes;
    std::map<uint16_t, EnemigosGui> diccionario_de_enemigos;
    std::vector<ColecionablesGui> vector_coleccionables;
    std::vector<std::shared_ptr<BalasGui>> vector_balas;

    uint16_t tiempo;


public:
    explicit GameStateClient(ClaseTexturas&, bool jugando);

    bool obtener_estado_de_la_partida();

    std::map<uint16_t, PersonajeGui> obtener_diccionario_de_personajes() const;

    std::map<uint16_t, EnemigosGui> obtener_diccionario_de_enemigos() const;

    std::vector<PlatformGui>& obtener_plataformas();

    void showTiempo(int h_window);

    uint16_t getTiempo() const;

    PersonajeGui& obtener_personaje(uint16_t client_id);

    bool getJugando() const { return jugando; }

    int getSizePersonajes() { return diccionario_de_personajes.size(); }

    int get_cantidad_de_enemigos() { return diccionario_de_enemigos.size(); }

    std::vector<std::shared_ptr<BalasGui>> obtener_balas() { return vector_balas; }

    void setGameState(const msgGameState& msg) {
        jugando = ((unsigned)msg.state_partida == 0x01);
        tiempo = ntohs(msg.tiempo);
    }

    void pushPersonajes(msgPersonaje& msgpers);

    void pushEnemigos(msgEnemigo& msgenem);

    void pushPlataformas(const msgPlataforma& msgplat);

    void pushColeccionables(msgColecionables& msgcol);

    void pushBalas(msgBalas& msgbal);

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

    void actualizar_gamestate( GameStateClient&);

    ~GameStateClient();

    // *** Funciones para tests
    GameStateClient(ClaseTexturas& tex) : texturas(tex), jugando(false), tiempo(0) {}

};

#endif
