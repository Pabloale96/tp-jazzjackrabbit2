#include "../../include/client_src/game_state_client.h"

#include <iostream>
#include <memory>

#include "../../common_src/msgToSent.h"

GameStateClient::GameStateClient(ClaseTexturas& texturas, bool jugando):
        texturas(texturas), jugando(jugando), tiempo(0) {}

bool GameStateClient::obtener_estado_de_la_partida() { return jugando; }

std::map<uint16_t, PersonajeGui> GameStateClient::obtener_diccionario_de_personajes() const {
    return diccionario_de_personajes;
}

std::map<uint16_t, EnemigosGui> GameStateClient::obtener_diccionario_de_enemigos() const {
    return diccionario_de_enemigos;
}
std::vector<PlatformGui>& GameStateClient::obtener_plataformas() { return plataformas; }

PersonajeGui& GameStateClient::obtener_personaje(uint16_t client_id) {
    auto it = diccionario_de_personajes.find(client_id);
    if (it != diccionario_de_personajes.end()) {
        return std::ref(it->second);
    }
    throw std::out_of_range("No se encontró el personaje en gamestate");
}

void GameStateClient::pushPlataformas(const msgPlataforma& msgplat) {
    PlatformGui platform(texturas, msgplat);
    plataformas.push_back(platform);
}

void GameStateClient::showTiempo(int h_window) {
    std::stack<uint16_t> pilaCifras;
    uint16_t tiempo_aux = tiempo;
    int offset = 0;
    if (tiempo_aux == 0) {
        Frame frame = texturas.findFrame(tiempo_aux);
        frame.copy(0, h_window / 2, 0);
    }
    // Extraer las cifras y almacenarlas en una pila.
    while (tiempo_aux > 0) {
        uint16_t cifra = tiempo_aux % 10;  // Extraer la última cifra.
        pilaCifras.push(cifra);            // Almacenar en la pila.
        tiempo_aux /= 10;                  // Eliminar la última cifra del número.
    }
    // Transferir las cifras de la pila al vector.
    while (!pilaCifras.empty()) {
        Frame frame = texturas.findFrame(pilaCifras.top());
        frame.copy(0, frame.getH() + offset + h_window / 2, 0);
        pilaCifras.pop();
        offset += frame.getH();
    }
}

void GameStateClient::pushPersonajes(msgPersonaje& msgpers) {
    std::shared_ptr<PersonajeGui> personaje;
    uint8_t tipo = msgpers.tipo_personaje;
    switch (tipo) {
        case static_cast<uint8_t>(personajes::JAZZ):
            personaje = std::make_shared<JazzGui>(texturas, msgpers);
            break;
        case static_cast<uint8_t>(personajes::SPAZZ):
            personaje = std::make_shared<SpazGui>(texturas, msgpers);
            break;
        case static_cast<uint8_t>(personajes::LORI):
            personaje = std::make_shared<LoriGui>(texturas, msgpers);
            break;
        default:
            std::cerr << "Error: Tipo de personaje no válido" << std::endl;
            return;
    }
    diccionario_de_personajes.emplace(ntohs(msgpers.personaje[POS_ID_PERSONAJE]),
                                      std::move(*personaje));
}

void GameStateClient::pushBalas(msgBalas& msg) {
    std::shared_ptr<BalasGui> bala;
    uint8_t tipo = msg.tipo_bala;
    switch (tipo) {
        case (uint8_t)balas::BALA_TIPO1:
            bala = std::make_shared<BalasGui1>(texturas, msg);
            break;
        case (uint8_t)balas::BALA_TIPO2:
            bala = std::make_shared<BalasGui2>(texturas, msg);
            break;
        default:
            std::cerr << "Error: Tipo de personaje no válido" << std::endl;
            return;
    }
    vector_balas.push_back(std::move(bala));
}

void GameStateClient::pushEnemigos(msgEnemigo& msgenem) {
    std::shared_ptr<EnemigosGui> enemigo;
    uint8_t tipo = msgenem.tipo;
    switch (tipo) {
        case static_cast<uint8_t>(TipoEnemigo::ENEMIGO1):
            enemigo = std::make_shared<EnemigoGui1>(texturas, msgenem);
            break;
        case static_cast<uint8_t>(TipoEnemigo::ENEMIGO2):
            enemigo = std::make_shared<EnemigoGui2>(texturas, msgenem);
            break;
        case static_cast<uint8_t>(TipoEnemigo::ENEMIGO3):
            enemigo = std::make_shared<EnemigoGui3>(texturas, msgenem);
            break;
        default:
            std::cerr << "Error: Tipo de enemigo no válido" << std::endl;
            return;
    }
    diccionario_de_enemigos.emplace(ntohs(msgenem.enemigo[POS_ID_ENEMIGO]), std::move(*enemigo));
}

uint16_t GameStateClient::getTiempo() const { return tiempo; }


void GameStateClient::actualizar_gamestate(GameStateClient& other) {

    this->jugando = other.getJugando();
    this->tiempo = other.getTiempo();
    this->vector_balas = other.obtener_balas();

    for (const auto& [id, personaje]: other.obtener_diccionario_de_personajes()) {
        if (!this->diccionario_de_personajes.empty()) {
            auto it = this->diccionario_de_personajes.find(id);
            if (it != diccionario_de_personajes.end()) {
                it->second.actualizar_personaje(personaje);
            } else {
                diccionario_de_personajes.emplace(id, std::move(personaje));
            }
        } else {
            this->diccionario_de_personajes = other.obtener_diccionario_de_personajes();
        }
    }

    for (auto& [id, enemigo]: other.obtener_diccionario_de_enemigos()) {
        if (!this->diccionario_de_enemigos.empty()) {
            auto it = this->diccionario_de_enemigos.find(id);
            if (it != diccionario_de_enemigos.end()) {
                it->second.actualizar_enemigo(enemigo);
            } else {
                diccionario_de_enemigos.emplace(id, std::move(enemigo));
            }
        } else {
            this->diccionario_de_enemigos = other.obtener_diccionario_de_enemigos();
        }
    }
}

GameStateClient::~GameStateClient() {}
