#include <gtest/gtest.h>

#include "../include/client_src/client_protocol.h"
#include "../include/common_src/catedra/sockets.h"

ProtocolClient crearProtocoloCliente() {
    std::string hostname = "localhost";
    std::string servicio = "8080";
    return ProtocolClient(hostname, servicio);
}

// Test cases
TEST(ProtocolClientTest, TestRecibirIdJugador) {
    ProtocolClient protocolClient = crearProtocoloCliente();
    uint16_t id_jugador = protocolClient.recibir_id_jugador();
    ASSERT_EQ(id_jugador, 12345);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    //return 0;
}
