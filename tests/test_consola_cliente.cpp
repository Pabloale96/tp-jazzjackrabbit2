#include <gtest/gtest.h>

#include "../include/client_src/client_protocol.h"
#include "../include/common_src/catedra/sockets.h"

ProtocolClient crearProtocoloCliente(const std::string& hostname, const std::string& servicio) {
    return ProtocolClient(hostname, servicio);
}

// Test cases

/*
TEST(ProtocolClientTest, TestRecibirIdJugador) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.1", "8080");
    uint16_t id_jugador = protocolClient.recibir_id_jugador();
    ASSERT_EQ(id_jugador, 12345);
}


TEST(ProtocolClientTest, TestEnviarPersonajeJazz) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.2", "8081");
    bool se_envio_personaje = protocolClient.enviar_personaje("j");
    ASSERT_EQ(se_envio_personaje, true);
}


TEST(ProtocolClientTest, TestEnviarPersonajeSpazz) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.3", "8082");
    bool se_envio_personaje = protocolClient.enviar_personaje("s");
    ASSERT_EQ(se_envio_personaje, true);
}

TEST(ProtocolClientTest, TestEnviarPersonajeLori) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.4", "8083");
    bool se_envio_personaje = protocolClient.enviar_personaje("l");
    ASSERT_EQ(se_envio_personaje, true);
}


TEST(ProtocolClientTest, TestEnviarCodigoCrearPartida) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.5", "8084");
    bool se_envio_codigo = protocolClient.enviar_codigo_de_crear_partida();
    ASSERT_EQ(se_envio_codigo, true);
}


TEST(ProtocolClientTest, TestCrearPartida) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.6", "8085");
    std::string nombre_partida = "partida1";
    bool se_envio_nombre = protocolClient.crear_partida(nombre_partida);
    ASSERT_EQ(se_envio_nombre, true);
}

TEST(ProtocolClientTest, TestRecibirPlataformaHorizontal) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.7", "8086");
    // Como necesito textura par el gamestate, creo una dummy (y todo lo que necesita)
    SDL2pp::Window window("Dummy Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
480, SDL_WINDOW_HIDDEN); SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
    ClaseTexturas dummyTexturas(renderer);
    GameStateClient gamestate_test(dummyTexturas);
    bool se_recibio_escenario = protocolClient.recibir_escenario(gamestate_test);
    ASSERT_EQ(se_recibio_escenario, true);
    ASSERT_EQ(gamestate_test.obtener_plataformas().size(), 1);
    ASSERT_EQ(gamestate_test.obtener_plataformas().at(0).getX(), 0);
    ASSERT_EQ(gamestate_test.obtener_plataformas().at(0).getY(), 0);
    ASSERT_EQ(gamestate_test.obtener_plataformas().at(0).getW(), 15);
    ASSERT_EQ(gamestate_test.obtener_plataformas().at(0).getH(), 1);
}

TEST(ProtocolClientTest, TestRecibirPlataformaVertical) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.8", "8087");
    // Como necesito textura par el gamestate, creo una dummy (y todo lo que necesita)
    SDL2pp::Window window("Dummy Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
480, SDL_WINDOW_HIDDEN); SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
    ClaseTexturas dummyTexturas(renderer);
    GameStateClient gamestate_test(dummyTexturas);
    bool se_recibio_escenario = protocolClient.recibir_escenario(gamestate_test);
    ASSERT_EQ(se_recibio_escenario, true);
    ASSERT_EQ(gamestate_test.obtener_plataformas().size(), 1);
    ASSERT_EQ(gamestate_test.obtener_plataformas().at(0).getX(), 3);
    ASSERT_EQ(gamestate_test.obtener_plataformas().at(0).getY(), 3);
    ASSERT_EQ(gamestate_test.obtener_plataformas().at(0).getW(), 1);
    ASSERT_EQ(gamestate_test.obtener_plataformas().at(0).getH(), 3);
}

TEST(ProtocolClientTest, TestConfirmarFinLobby) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.9", "8088");
    bool confirmacion = protocolClient.confirmar_fin_lobby();
    ASSERT_EQ(confirmacion, true);
}

TEST(ProtocolClientTest, TestUnirseAPartida) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.9", "8089");
    bool se_unio_a_partida = protocolClient.unirse_a_partida();
    ASSERT_EQ(se_unio_a_partida, true);
}

TEST(ProtocolClientTest, TestRecibirPartidasDisponiblesVacio) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.9", "8089");
    std::map<uint16_t, std::string> partidas_disponibles;
    protocolClient.recibir_partidas_disponibles(partidas_disponibles);
    ASSERT_EQ(partidas_disponibles.size(), 0);
}

TEST(ProtocolClientTest, TestRecibirPartidasDisponibles) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.9", "8089");
    std::map<uint16_t, std::string> partidas_disponibles;
    protocolClient.recibir_partidas_disponibles(partidas_disponibles);
    ASSERT_EQ(partidas_disponibles.size(), 1);
    ASSERT_NE(partidas_disponibles.find(1), partidas_disponibles.end()) << "No se encontró el ID 1
en partidas_disponibles"; ASSERT_EQ(partidas_disponibles[1], "partida1");
}
*/

TEST(ProtocolClientTest, TestRecibirMuchasPartidasDisponibles) {
    ProtocolClient protocolClient = crearProtocoloCliente("127.0.0.9", "8089");
    std::map<uint16_t, std::string> partidas_disponibles;
    protocolClient.recibir_partidas_disponibles(partidas_disponibles);
    ASSERT_EQ(partidas_disponibles.size(), 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
