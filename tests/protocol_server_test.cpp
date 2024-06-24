#include <gtest/gtest.h>

#include "../include/common_src/catedra/sockets.h"
#include "../include/server_src/server_protocol.h"

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


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    // return 0;
}
