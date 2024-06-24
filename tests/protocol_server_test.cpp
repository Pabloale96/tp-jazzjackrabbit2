#include <gtest/gtest.h>

#include "../include/common_src/catedra/sockets.h"
#include "../include/server_src/server_protocol.h"

// Test cases
/*
TEST(ProtocolServerTest, TestEnvioIdCliente) {
    Socket server("8080");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    uint16_t id_cliente = 12345;

    protocolServer.enviar_id_jugador(id_cliente, was_closed);
    ASSERT_EQ(was_closed, false);
}


TEST(ProtocolServerTest, TestRecibirPersonajeJazz) {
    Socket server("8081");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;

    uint8_t buffer = protocolServer.recibir_personaje(was_closed);
    ASSERT_EQ((uint8_t)personajes::JAZZ, buffer);
}


TEST(ProtocolServerTest, TestRecibirPersonajeSpazz) {
    Socket server("8082");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;

    uint8_t buffer = protocolServer.recibir_personaje(was_closed);
    ASSERT_EQ((uint8_t)personajes::SPAZZ, buffer);
}

TEST(ProtocolServerTest, TestRecibirPersonajeLori) {
    Socket server("8083");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;

    uint8_t buffer = protocolServer.recibir_personaje(was_closed);
    ASSERT_EQ((uint8_t)personajes::LORI, buffer);
}


TEST(ProtocolServerTest, TestRecibirCodigoCrearPartida) {
    Socket server("8084");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    uint8_t buffer = protocolServer.crear_partida(was_closed);
    ASSERT_EQ(CREAR_PARTIDA, buffer);
}


TEST(ProtocolServerTest, TestRecibirNombrePartida) {
    Socket server("8085");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    std::string nombre_recibido;
    protocolServer.recibir_nombre_partida(nombre_recibido, was_closed);
    ASSERT_EQ(nombre_recibido, "partida1");
}

TEST(ProtocolServerTest, TestEnviarPlataformaHorizontal) {
    Socket server("8086");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    uint16_t x = 0;
    uint16_t y = 0;
    uint16_t w = 15;
    uint16_t h = 1;
    platform type = platform::HORIZONTAL;
    bool flip = false;
    Platform plataforma_horizontal(x, y, w, h, (uint16_t) type, flip);
    std::vector<Platform> escenario;
    escenario.push_back(plataforma_horizontal);
    protocolServer.enviar_escenario(escenario, was_closed);
    ASSERT_EQ(was_closed, false);
}

TEST(ProtocolServerTest, TestEnviarPlataformaVertical) {
    Socket server("8087");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    uint16_t x = 3;
    uint16_t y = 3;
    uint16_t w = 1;
    uint16_t h = 3;
    platform type = platform::VERTICAL;
    bool flip = false;
    Platform plataforma_horizontal(x, y, w, h, (uint16_t) type, flip);
    std::vector<Platform> escenario;
    escenario.push_back(plataforma_horizontal);
    protocolServer.enviar_escenario(escenario, was_closed);
    ASSERT_EQ(was_closed, false);
}

TEST(ProtocolServerTest, TestConfirmarFinLobby) {
    Socket server("8088");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    bool confirmacion = protocolServer.confirmar_fin_lobby(was_closed);
    ASSERT_EQ(confirmacion, true);
}

TEST(ProtocolServerTest, TestUnirseAPartida) {
    Socket server("8089");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    uint8_t buffer = protocolServer.crear_partida(was_closed);
    ASSERT_EQ(buffer, UNIRSE_A_PARTIDA);
}

TEST(ProtocolServerTest, TestEnviarPartidasDisponiblesVacioLlamaACrearPartida) {
    Socket server("8089");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    GameloopMonitor gameloop_monitor;
    uint8_t buffer = protocolServer.enviar_partidas_disponibles(gameloop_monitor, was_closed);
    ASSERT_EQ(buffer, CREAR_PARTIDA);
}

TEST(ProtocolServerTest, TestEnviarPartidasDisponibles) {
    Socket server("8089");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    GameloopMonitor gameloop_monitor;
    gameloop_monitor.crear_gameloop("partida1", 1, (uint8_t)personajes::JAZZ);
    uint8_t buffer = protocolServer.enviar_partidas_disponibles(gameloop_monitor, was_closed);
    ASSERT_EQ(buffer, UNIRSE_A_PARTIDA);
}
*/

TEST(ProtocolServerTest, TestEnviarMuchasPartidasDisponibles) {
    Socket server("8089");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    GameloopMonitor gameloop_monitor;
    gameloop_monitor.crear_gameloop("partida1", 1, (uint8_t)personajes::JAZZ);
    gameloop_monitor.crear_gameloop("partida2", 2, (uint8_t)personajes::SPAZZ);
    gameloop_monitor.crear_gameloop("partida3", 3, (uint8_t)personajes::LORI);
    uint8_t buffer = protocolServer.enviar_partidas_disponibles(gameloop_monitor, was_closed);
    ASSERT_EQ(buffer, UNIRSE_A_PARTIDA);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
