#ifndef __GAMESTATE_CLIENT_H__
#define __GAMESTATE_CLIENT_H__

#include <map>
#include <memory>
#include <utility>
#include <vector>

#include "gui/gui_enemigos.h"
#include "gui/gui_personaje.h"

#include "dict_monitor.h"
#include "msgToSent.h"
#include "queue.h"

class GameStateClient {
private:
    bool jugando;

    // TODO: monitor dict.
    DictMonitor<std::shared_ptr<PersonajeGui>> diccionario_de_personajes;
    DictMonitor<EnemigosGui> diccionario_de_enemigos;


public:
    explicit GameStateClient(bool jugando);
    GameStateClient();

    bool obtener_estado_de_la_partida();

    std::map<uint16_t, std::shared_ptr<PersonajeGui>>& obtener_diccionario_de_personajes();

    std::map<uint16_t, EnemigosGui>& obtener_diccionario_de_enemigos();

    std::shared_ptr<PersonajeGui>& obtener_personaje(uint16_t client_id);

    bool getJugando() { return jugando; }

    int getSizePersonajes() { return diccionario_de_personajes.size(); }

    int get_cantidad_de_enemigos() { return diccionario_de_enemigos.size(); }

    void setGameState(const uint8_t& state_partida) {
        if (state_partida == 0x01) {
            jugando = true;
        } else {
            jugando = false;
        }
        // jugando = ((unsigned) state_partida == 0x01);
    }

    void pushPersonajes(msgPersonaje& msgpers);

    void pushEnemigos(msgEnemigo& msgenem) {
        EnemigosGui enemigo(msgenem);
        diccionario_de_enemigos.emplace(enemigo.get_id_enemigo(), enemigo);
    }

    // Prohibir la copia
    GameStateClient(const GameStateClient&) = delete;
    GameStateClient& operator=(const GameStateClient&) = delete;

    // Permitir el movimiento
    GameStateClient(GameStateClient&& other) noexcept:
            jugando(other.jugando),
            diccionario_de_personajes(std::move(other.diccionario_de_personajes)),
            diccionario_de_enemigos(std::move(other.diccionario_de_enemigos)) {}

    GameStateClient& operator=(GameStateClient&& other) noexcept {
        if (this != &other) {
            jugando = other.jugando;
            diccionario_de_personajes = std::move(other.diccionario_de_personajes);
            diccionario_de_enemigos = std::move(other.diccionario_de_enemigos);
        }
        return *this;
    }

    void imprimir_cliente() {
        for (const auto& pair: diccionario_de_personajes) {
            const std::shared_ptr<PersonajeGui>& personaje = pair.second;
            std::cout << " >> Personaje " << std::endl;
            std::cout << "     - Posición: (" << personaje->obtener_posicion_x() << ", "
                      << personaje->obtener_posicion_y() << ")." << std::endl;
            std::cout << "     - Estado: " << (unsigned)personaje->obtener_estado_actual()
                      << std::endl;
            std::cout << "     - Tipo: " << (unsigned)personaje->obtener_tipo_personaje()
                      << std::endl;
        }
    }

    ~GameStateClient();
};

#endif
