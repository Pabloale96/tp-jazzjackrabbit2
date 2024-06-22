#ifndef __GAMESTATE_CLIENT_H__
#define __GAMESTATE_CLIENT_H__

#include <map>
#include <memory>
#include <utility>
#include <vector>

#include "gui/gui_enemigos.h"
#include "gui/gui_personaje.h"
#include "gui/gui_platform.h"

#include "dict_monitor.h"
#include "msgToSent.h"
#include "queue.h"

class GameStateClient {
private:
    bool jugando;

    std::shared_ptr<ClaseTexturas> texturas;
    std::map<uint16_t, PersonajeGui> diccionario_de_personajes;
    std::map<uint16_t, EnemigosGui> diccionario_de_enemigos;
    std::vector<PlatformGui>& vec_plataforma;


public:
    explicit GameStateClient(std::shared_ptr<ClaseTexturas> texturas, std::vector<PlatformGui>& vec_plataforma,bool jugando);
    GameStateClient(std::shared_ptr<ClaseTexturas> texturas,bool jugando);

    bool obtener_estado_de_la_partida();

    std::map<uint16_t, PersonajeGui>& obtener_diccionario_de_personajes();

    std::map<uint16_t, EnemigosGui>& obtener_diccionario_de_enemigos();

    std::vector<PlatformGui> & obtener_vector_plataforma();

    PersonajeGui& obtener_personaje(uint16_t client_id);

    bool getJugando() { return jugando; }

    int getSizePersonajes() { return diccionario_de_personajes.size(); }

    int get_cantidad_de_enemigos() { return diccionario_de_enemigos.size(); }

    void setGameState(const uint8_t& state_partida) { jugando = ((unsigned)state_partida == 0x01); }

    void pushPersonajes(msgPersonaje& msgpers);

    void pushEnemigos(msgEnemigo& msgenem) {
        EnemigosGui enemigo(msgenem);
        diccionario_de_enemigos.emplace(enemigo.get_id_enemigo(), enemigo);
    }

    void pushPlataforma(const msgPlataforma& plataforma) {
        PlatformGui platform(*texturas,plataforma);
        vec_plataforma.push_back(platform);
    }

    void imprimir_cliente() {
         std::cout << "  Personajes Size: "<< diccionario_de_personajes.size() << std::endl;
        for (const auto& pair: diccionario_de_personajes) {
            std::cout << " >> Personaje " << std::endl;
            std::cout << "     - Posición: (" << pair.second.obtener_posicion_x() << ", "
                      << pair.second.obtener_posicion_y() << ")." << std::endl;
            std::cout << "     - Estado: " << (unsigned)pair.second.obtener_estado_actual()
                      << std::endl;
            std::cout << "     - Tipo: " << (unsigned)pair.second.obtener_tipo_personaje()
                      << std::endl;
        }
        
        /*for (size_t i =0; i<vec_plataforma.size(); i++) {
            std::cout << " >> Plataforma " << std::endl;
            std::cout << "     - Posición: (" << vec_plataforma[i].getX() << ", "<<vec_plataforma[i].getY() << ")." << std::endl;
            std::cout << "     - Width: " << (unsigned)vec_plataforma[i].getW()
                      << std::endl;
            std::cout << "     - Height: " << (unsigned)vec_plataforma[i].getH()
                      << std::endl;
        }*/
    }

    ~GameStateClient();
};

#endif
