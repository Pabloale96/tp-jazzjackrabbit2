#include <gtest/gtest.h>

#include "../include/client_src/client_protocol.h"
#include "../include/common_src/catedra/sockets.h"

ProtocolClient crearProtocoloCliente(const std::string& hostname, const std::string& servicio) {
    return ProtocolClient(hostname, servicio);
}

// Test cases
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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
