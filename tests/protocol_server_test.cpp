#include <gtest/gtest.h>

#include "../include/server_src/server_protocol.h"
#include "../include/common_src/catedra/sockets.h"

// Test cases
TEST(ProtocolServerTest, TestEnvioIdCliente) {
    Socket server("8080");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;
    uint16_t id_cliente = 12345;

    protocolServer.enviar_id_jugador(id_cliente, was_closed);
    ASSERT_EQ(false, false);
}


TEST(ProtocolServerTest, TestRecibirPersonajeJazz) {
    Socket server("8081");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;

    uint8_t buffer = protocolServer.recibir_personaje(was_closed);
    ASSERT_EQ((uint8_t) personajes::JAZZ, buffer);
}


TEST(ProtocolServerTest, TestRecibirPersonajeSpazz) {
    Socket server("8082");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;

    uint8_t buffer = protocolServer.recibir_personaje(was_closed);
    ASSERT_EQ((uint8_t) personajes::SPAZZ, buffer);
}

TEST(ProtocolServerTest, TestRecibirPersonajeLori) {
    Socket server("8083");
    Socket cliente = server.accept();
    ProtocolServer protocolServer(std::move(cliente));
    bool was_closed = false;

    uint8_t buffer = protocolServer.recibir_personaje(was_closed);
    ASSERT_EQ((uint8_t) personajes::LORI, buffer);
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

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
