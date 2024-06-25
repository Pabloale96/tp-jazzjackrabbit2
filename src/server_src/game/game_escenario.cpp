#include "game_escenario.h"

#include <random>

#include "protocol_utils.h"

#define CALCULO_HIPO(X, Y) (sqrt((X) * (X) + (Y) * (Y)))

GameEscenario::GameEscenario():
        plataformas(),
        plataformas_server(),
        enemigos(),
        collectibles(),
        id_enemigo(0),
        id_collectible(0) {
    std::cout << "Creando escenario" << std::endl;
    cargar_plataformas();
    cargar_enemigos();
    cargar_collectibles();
}

uint16_t GameEscenario::generar_id_enemigo() { return id_enemigo++; }

uint16_t GameEscenario::generar_id_collectible() { return id_collectible++; }

void GameEscenario::cargar_plataformas() {
    //      *** Plataformas horizontales  ***
    std::vector<float> x_horizontales = {0,  15, 22, 33, 53, 75, 81, 84, 87, 0, 16,
                                         33, 47, 65, 78, 8,  23, 27, 30, 33, 48};

    std::vector<float> y_horizontales = {0,  2,  7,  5,  15, 8,  12, 15, 18, 11, 23,
                                         27, 30, 32, 34, 45, 36, 41, 43, 46, 47};
    std::vector<float> w_horizontales = {15, 5,  10, 11, 16, 24, 13, 7, 1, 11, 17,
                                         11, 18, 11, 21, 6,  23, 18, 7, 1, 47};
    for (size_t i = 0; i < x_horizontales.size(); i++) {
        Plataforma plataforma_inicial_server(
                platform::HORIZONTAL, x_horizontales[i], y_horizontales[i], x_horizontales[i],
                y_horizontales[i] + 1, x_horizontales[i] + w_horizontales[i], y_horizontales[i],
                x_horizontales[i] + w_horizontales[i], y_horizontales[i] + 1, 0);
        plataformas_server.push_back(plataforma_inicial_server);

        Platform plataforma_inicial(x_horizontales[i], y_horizontales[i], w_horizontales[i], 1,
                                    static_cast<uint16_t>(platform::HORIZONTAL), false);
        plataformas.push_back(plataforma_inicial);
    }

    //      *** Plataformas verticales  ***
    std::vector<float> x_verticales = {3, 15, 33, 53, 33, 65};
    std::vector<float> y_verticales = {3, 2, 5, 13, 23, 30};
    std::vector<float> h_verticales = {3, 3, 2, 2, 4, 2};
    for (size_t i = 0; i < x_verticales.size(); i++) {
        Plataforma plataforma_inicial_server(
                platform::VERTICAL, x_verticales[i], y_verticales[i] - h_verticales[i],
                x_verticales[i], y_verticales[i], x_verticales[i] + 1,
                y_verticales[i] - h_verticales[i], x_verticales[i] + 1, y_verticales[i], 90);
        plataformas_server.push_back(plataforma_inicial_server);

        Platform plataforma_inicial(x_verticales[i], y_verticales[i], 1, h_verticales[i],
                                    static_cast<uint16_t>(platform::VERTICAL), false);
        plataformas.push_back(plataforma_inicial);
    }

    //      *** Plataformas diagonales  ***
    /*
    std::vector<int> x_diagonales = {3, 1, 7, 23, 19, 44, 75, 23, 16, 76, 44, 49, 41};
    std::vector<int> y_diagonales = {33, 38, 14, 36, 3, 5, 8, 26, 6, 32, 27, 33, 40};
    std::vector<int> w_diagonales = {5, 10, 13, 13, 4, 11, 10, 10, 7, 3, 4, 4, 10};
    std::vector<int> flip_diagonales = {false, true,  true,  false, true,
                                        true,  false, false, false, true};
    for (size_t i = 0; i < x_diagonales.size(); i++) {
        Platform plataforma_inicial(x_diagonales[i], y_diagonales[i], w_diagonales[i], 1,
                                        static_cast<uint16_t>(platform::DIAGONAL),
        flip_diagonales[i]); plataformas.push_back(plataforma_inicial);
    }


    std::vector<int> x_diagonales = {3, 1, 7, 23, 19, 44, 75, 23, 16, 76, 44, 49, 41};
    std::vector<int> y_diagonales = {33, 38, 14, 36, 3, 5, 8, 26, 6, 32, 27, 33, 40};
    std::vector<int> w_diagonales = {5, 10, 13, 13, 4, 11, 10, 10, 7, 3, 4, 4, 10};
    std::vector<int> angulos = {45, 135, 135, 45, 135, 135, 45, 45, 45, 135};
    for (size_t i = 0; i < x_diagonales.size(); i++) {
        Plataforma plataforma_inicial(platform::DIAGONAL, x_diagonales[i], y_diagonales[i],
                                      x_diagonales[i], y_diagonales[i], x_diagonales[i],
                                      y_diagonales[i], x_diagonales[i], y_diagonales[i],
                                      angulos[i]);
        plataformas.push_back(plataforma_inicial);
    }
    */
}

void GameEscenario::cargar_enemigos() {
    // Las coordenadas (x,y) se basan en el diseño del escenario en /docs/disenio_nivel.png
    enemigos.push_back(std::make_unique<Enemigo1>(generar_id_enemigo(), 26.0f, 8.0f));
    enemigos.push_back(std::make_unique<Enemigo1>(generar_id_enemigo(), 38.0f, 28.0f));
    enemigos.push_back(std::make_unique<Enemigo1>(generar_id_enemigo(), 70.0f, 33.0f));

    enemigos.push_back(std::make_unique<Enemigo2>(generar_id_enemigo(), 25.0f, 24.0f));
    enemigos.push_back(std::make_unique<Enemigo2>(generar_id_enemigo(), 56.0f, 31));

    enemigos.push_back(std::make_unique<Enemigo3>(generar_id_enemigo(), 59.0f, 19.0f));
    enemigos.push_back(std::make_unique<Enemigo3>(generar_id_enemigo(), 9.0f, 38.0f));
}

void GameEscenario::cargar_collectibles() {
    // Monedas
    collectibles.push_back(std::make_unique<Moneda>(generar_id_collectible(), 5, 13));
    collectibles.push_back(std::make_unique<Moneda>(generar_id_collectible(), 11, 13));
    // Monedas de la tabla larga
    for (int i = 51; i < 96; i += 4) {
        collectibles.push_back(std::make_unique<Moneda>(generar_id_collectible(), i, 49));
    }

    // Monedas de la piramide de arriba
    for (int i = 0; i < 3; i++) {
        collectibles.push_back(std::make_unique<Moneda>(generar_id_collectible(), 25 + i * 7, 37));
    }
    for (int i = 0; i < 3; i++) {
        collectibles.push_back(
                std::make_unique<Moneda>(generar_id_collectible(), 29 + i * 4, 41 + i * 7));
    }

    // Gemas
    collectibles.push_back(std::make_unique<Gema>(generar_id_collectible(), 1, 13));
    collectibles.push_back(std::make_unique<Gema>(generar_id_collectible(), 33, 45));
    collectibles.push_back(std::make_unique<Gema>(generar_id_collectible(), 87, 21));

    // Zanahorias
    collectibles.push_back(std::make_unique<Zanahoria>(generar_id_collectible(), 11, 47));
    collectibles.push_back(std::make_unique<Zanahoria>(generar_id_collectible(), 39, 7));
}

/*
void GameEscenario::crear_enemigo_aleatorio(uint16_t id_enemigo) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2);

    int tipoEnemigo = distrib(gen);
    switch (tipoEnemigo) {
        case 0:
            enemigos.push_back(std::make_unique<Enemigo1>(id_enemigo));
            return;
        case 1:
            enemigos.push_back(std::make_unique<Enemigo2>(id_enemigo));
            return;
        case 2:
            enemigos.push_back(std::make_unique<Enemigo3>(id_enemigo));
            return;
        default:
            throw std::runtime_error("Tipo de enemigo desconocido");
    }
}
*/

void GameEscenario::actualizar_escenario() {
    actualizar_enemigos();
}

void GameEscenario::actualizar_enemigos() {
    for (auto& enemigo: enemigos) {
        if (enemigo) {
            enemigo->actualizar();
        } else {
            std::cerr << "ERROR en actualizar_enemigos" << std::endl;
        }
    }
}

const VectorMonitor<std::shared_ptr<Enemigo>>& GameEscenario::obtener_enemigos() {
    return enemigos;
}

std::vector<Platform>& GameEscenario::obtener_plataformas() { return plataformas; }

const VectorMonitor<std::shared_ptr<Collectible>>& GameEscenario::obtener_collectibles() {
    return collectibles;
}

GameEscenario::~GameEscenario() = default;
