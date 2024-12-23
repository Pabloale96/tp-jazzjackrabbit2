#include "../../include/client_src/client.h"

#include <cctype>  // std::tolower()
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define MAX_TAM_COLA 100000
#define CLIENT_ID_NULO 0


Client::Client(const std::string& hostname, const std::string& servicio):
        hostname(hostname),
        servicio(servicio),
        protocolo_client(hostname.c_str(), servicio.c_str()),
        client_commands(MAX_TAM_COLA),
        sender(protocolo_client, client_commands),
        server_msg(MAX_TAM_COLA),
        receiver(protocolo_client, client_id, server_msg, texturas),
        client_id(CLIENT_ID_NULO),
        //mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 4, 4096)
        //sonidos(Mixer)
        window(Window("Jazz JackRabbit 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                      screenHeight, screenWidth, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN)),
        renderer(Renderer(window, -1, SDL_RENDERER_ACCELERATED)),
        texturas(renderer),
        gamestate(texturas, true),
        gui(client_commands, jugador, gamestate, gamestate.obtener_plataformas()) {}

void Client::imprimir_portada() {
    std::ifstream file("../docs/portada.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo 'portada.txt'" << std::endl;
    }
}

void Client::imprimir_bienvenida() {
    imprimir_portada();
    std::cout << "Bienvenido al juego!" << std::endl;
    client_id = protocolo_client.recibir_id_jugador();
    std::cout << "Su numero de jugador es: " << client_id << std::endl;
}

void Client::crear_personaje() {
    std::string personaje;
    std::cout << "Ingrese el nombre del personaje que desea utilizar" << std::endl;
    std::cout << "  - Jazz (j)" << std::endl;
    std::cout << "  - Spazz (s)" << std::endl;
    std::cout << "  - Lori (l)" << std::endl;
    std::cin >> personaje;
    personaje = toLowercase(personaje);
    while (personaje != "j" && personaje != "s" && personaje != "l") {
        std::cout << "Error: Personaje no válido. Intente nuevamente" << std::endl;
        std::cin >> personaje;
        personaje = toLowercase(personaje);
    }
    if (protocolo_client.enviar_personaje(personaje) == false) {
        std::cout << "Error: No se pudo crear el personaje" << std::endl;
        return;
    }
    if (personaje == "j") {
        jugador = std::make_shared<JazzGui>(
                texturas, renderer.GetOutputWidth() / 2, renderer.GetOutputHeight() / 2,
                (uint8_t)personajes::JAZZ, 4,
                texturas.findFrame(std::string(JAZZ_STAND)));  // 4 ponerlo como define
    } else if (personaje == "s") {
        jugador = std::make_shared<SpazGui>(
                texturas, renderer.GetOutputWidth() / 2, renderer.GetOutputHeight() / 2,
                (uint8_t)personajes::SPAZZ, 4, texturas.findFrame(std::string(SPAZ_STAND)));
    } else if (personaje == "l") {
        jugador = std::make_shared<LoriGui>(
                texturas, renderer.GetOutputWidth() / 2, renderer.GetOutputHeight() / 2,
                (uint8_t)personajes::LORI, 4, texturas.findFrame(std::string(LORI_STAND)));
    }
}

void Client::crear_partida() {
    std::cout << "Ingrese el nombre de la partida que desea crear" << std::endl;
    std::string nombre_partida;
    std::cin.ignore();
    std::getline(std::cin, nombre_partida);
    if (protocolo_client.enviar_codigo_de_crear_partida() == false) {
        std::cout << "Error: No se pudo enviar el código de crear partida" << std::endl;
        return;
    } else if (protocolo_client.crear_partida(nombre_partida) == false) {
        std::cout << "Error: No se pudo crear la partida" << std::endl;
        return;
    }
}

void Client::unirse_a_partida() {
    if (protocolo_client.unirse_a_partida() == false) {
        std::cout << "Error: No se pudo joinear a la partida" << std::endl;
        return;
    }
    std::cout << "Espere un momento mientras buscamos las partidas disponibles para unirse..."
              << std::endl;
    std::map<uint16_t, std::string> partidas_disponibles;
    protocolo_client.recibir_partidas_disponibles(partidas_disponibles);
    if (partidas_disponibles.empty()) {
        std::cout << "No hay partidas disponibles para unirse" << std::endl;
        std::cout << "Creando una nueva partida..." << std::endl;
        crear_partida();
        return;
    } else {
        std::cout << "Estas son las partidas disponibles para unirse: " << std::endl;
        for (const auto& pair: partidas_disponibles) {
            std::cout << "   - ID: " << pair.first << " - Nombre: " << pair.second << std::endl;
        }
        std::cout << "Ingrese el ID de la partida a la que desea unirse" << std::endl;
        uint16_t id_partida;
        while (std::cin >> id_partida) {
            if (partidas_disponibles.find(id_partida) == partidas_disponibles.end()) {
                std::cout << "Error: ID de partida no válido. Intente nuevamente" << std::endl;
                continue;
            }
            std::cout << "id partida: " << static_cast<int>(id_partida) << std::endl;
            protocolo_client.enviar_id_partida(id_partida);
            return;
        }
    }
}

void Client::establecer_partida() {
    std::cout << "¿Desea crear una partida o ver las partidas disponibles para unirse?"
              << std::endl;
    std::cout << "Ingrese 'c' para crear una partida o 'j' para unirse a una partida" << std::endl;
    std::string accion_actual;
    while (std::cin >> accion_actual) {
        accion_actual = toLowercase(accion_actual);
        if (accion_actual == "c") {
            crear_partida();
            return;
        } else if (accion_actual == "j") {
            unirse_a_partida();
            return;
        } else {
            std::cout << "Error: Acción no reconocida" << std::endl;
        }
    }
}

std::string Client::toLowercase(const std::string& str) {
    std::string minusculas;
    for (char c: str) {
        minusculas += std::tolower(c);
    }
    return minusculas;
}

void Client::iniciar_hilos() {
    receiver.start();
    sender.start();
}

void Client::crear_escenario() {
    if (protocolo_client.recibir_escenario(gamestate) == false) {
        std::cout << "Error: No se pudo recibir el escenario" << std::endl;
        return;
    }
}

bool Client::cerrar_lobby() {
    if (protocolo_client.confirmar_fin_lobby() == false) {
        std::cout << "Error: No se pudo completar correctamente el inicio del juego. Por favor "
                     "cierre y vuelva a intentarlo. "
                  << std::endl;
        return false;
    }
    return true;
}

void Client::jugar() {

    // ***************** LOBBY *****************
    SDL sdl(SDL_INIT_VIDEO);
    SDLTTF ttf;
    const nanoseconds rate_ns(static_cast<int>(1e9 / RATE));
    imprimir_bienvenida();
    establecer_partida();
    crear_personaje();
    std::cout << "Aguarda unos minutos mientras se completa el escenario..." << std::endl;
    crear_escenario();
    if (cerrar_lobby() == false) {
        return;
    }

    // ***************** JUEGO *****************
    std::cout << "Comienza la partida!" << std::endl;
    iniciar_hilos();
    window.Show();
    //sonidos.findAudio(AMBIENTE_CASTLE).run();
    bool client_off = false;
    std::shared_ptr<GameStateClient> gamestate_new;
    while (!client_off) {
        while (server_msg.try_pop(gamestate_new)) {}
        if (gamestate_new) {
            auto frame_start = steady_clock::now();

            gamestate.actualizar_gamestate(*gamestate_new);
            renderer.Clear();
            PersonajeGui jugador_actual =
                    gamestate.obtener_diccionario_de_personajes().find(client_id)->second;

            bool flip = gui.setPosicionJugador(jugador_actual.obtener_posicion_x(),
                                               jugador_actual.obtener_posicion_y());
            jugador->setAnimacion(jugador_actual, flip);
            gamestate.obtener_diccionario_de_personajes().erase(client_id);
            client_off = gui.run(screenHeight, screenWidth, client_id);
            if (client_off) {
                return;
            }
            renderer.Present();

            auto frame_end = steady_clock::now();
            auto rest = rate_ns - (frame_end - frame_start);

            if (rest.count() < 0) {
                auto behind = -rest;
                auto lost = behind - behind % rate_ns;
                frame_start += lost;
            }
            std::this_thread::sleep_for(rest);
            frame_start += rate_ns;

            if (gamestate.getJugando() == false) {
                std::cout << "La partida ha finalizado" << std::endl;
                mostrar_estadisticas(gamestate);
                return;
            }
        }
    }
}

void Client::mostrar_estadisticas(const GameStateClient& respuestas) const {
    // TODO: Habria q dejarla mas linda y que imprima en orden de puntos
    std::cout << "Estadísticas de la partida:" << std::endl;
    std::cout << "   PERSONAJE   |   PUNTOS" << std::endl;
    std::vector<int> top_puntos;
    std::vector<uint16_t> id_personajes;
    for (const auto& [id, personaje]: respuestas.obtener_diccionario_de_personajes()) {
        if (top_puntos.empty() || top_puntos.size() < 3) {
            top_puntos.push_back(personaje.getPuntos());
            id_personajes.push_back(id);
            continue;
        } else {
            for (size_t i = 0; i < top_puntos.size(); i++) {
                if (personaje.getPuntos() > top_puntos[i]) {
                    top_puntos[i] = personaje.getPuntos();
                    id_personajes[i] = id;
                }
            }
        }
    }
    // ordeno vectores:
    for (size_t i = 0; i < top_puntos.size()-1; i++) {
        if (top_puntos[i+1] > top_puntos[i]) {
            int top_punto_i = top_puntos[i];
            int id_i = id_personajes[i];
            top_puntos[i] = top_puntos[i+1];
            id_personajes[i] = id_personajes[i+1];
            top_puntos[i+1] = top_punto_i;
            id_personajes[i+1] = id_i;
        }
    } 
    if (top_puntos[1] > top_puntos[0]) {
        int top_punto_i = top_puntos[0];
        int id_i = id_personajes[0];
        top_puntos[0] = top_puntos[1];
        id_personajes[0] = id_personajes[1];
        top_puntos[1] = top_punto_i;
        id_personajes[1] = id_i;
    }

    for (size_t i = 0; i < top_puntos.size(); i++) {
        std::cout << "   " << (unsigned)id_personajes[i] << "   |   " << top_puntos[i] << std::endl;
    }
}

void Client::stop_hilos() {}

Client::~Client() {
    client_commands.close();
    server_msg.close();
    protocolo_client.cerrar_socket();

    sender.stop();
    receiver.stop();

    sender.join();
    receiver.join();
}
