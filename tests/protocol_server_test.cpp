/*
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/server_src/server_protocol.h"

// Definir una clase de socket mockeada que derive de Socket
class MockSocket {
public:
    MOCK_METHOD3(sendall, void(const void*, size_t, bool*));
    MOCK_METHOD3(recvall, void(void*, size_t, bool*));
    MOCK_METHOD1(shutdown, void(int));
    MOCK_METHOD0(close, void());
};

// Test fixture for ProtocolServer tests
class ProtocolServerTest : public ::testing::Test {
protected:
    MockSocket mockSocket;
    ProtocolServer* protocolServer;  // Pointer to ProtocolServer

    void SetUp() override {
        protocolServer = new ProtocolServer(std::move(mockSocket));
    }

    void TearDown() override {
        delete protocolServer;
    }
};

// Test cases
TEST_F(ProtocolServerTest, TestEnviarIdJugador) {
    bool was_closed = false;
    uint16_t id_cliente = 12345;

    EXPECT_CALL(mockSocket, sendall(::testing::_, sizeof(uint16_t), &was_closed))
        .WillOnce(::testing::Return());

    protocolServer->enviar_id_jugador(id_cliente, was_closed);

    // Additional assertions if needed
}

TEST_F(ProtocolServerTest, TestRecibirNombrePartida) {
    bool was_closed = false;
    std::string nombre_partida_received;

    // Mocking behavior for recvall
    uint8_t nombre_partida_len = 5;
    std::string expected_nombre_partida = "Test1";

    EXPECT_CALL(mockSocket, recvall(::testing::_, sizeof(uint8_t), &was_closed))
        .WillOnce(::testing::DoAll(::testing::SetArgPointee<0>(nombre_partida_len), ::testing::Return()));

    EXPECT_CALL(mockSocket, recvall(::testing::_, nombre_partida_len * sizeof(uint8_t), &was_closed))
        .WillOnce(::testing::DoAll(::testing::SetArrayArgument<0>(expected_nombre_partida.begin(), expected_nombre_partida.end()), ::testing::Return()));

    protocolServer->recibir_nombre_partida(nombre_partida_received, was_closed);

    // Additional assertions
    ASSERT_EQ(nombre_partida_received, expected_nombre_partida);
}
*/

int main(int argc, char** argv) {
    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
    return 0;
}
