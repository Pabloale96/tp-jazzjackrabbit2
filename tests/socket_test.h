#ifndef _SOCKET_TEST_H
#define _SOCKET_TEST_H

#include <gmock/gmock.h>
#include "../../include/common_src/catedra/sockets.h"

class SocketTest : public Socket {
public:
    SocketTest() : Socket(0) {}

    MOCK_METHOD(int, sendsome, (const void* data, unsigned int sz, bool* was_closed), (override));
    MOCK_METHOD(int, recvsome, (void* data, unsigned int sz, bool* was_closed), (override));
    MOCK_METHOD(int, sendall, (const void* data, unsigned int sz, bool* was_closed), (override));
    MOCK_METHOD(int, recvall, (void* data, unsigned int sz, bool* was_closed), (override));
    MOCK_METHOD(Socket, accept, (), (override));
    MOCK_METHOD(void, shutdown, (int how), (override));
    MOCK_METHOD(int, close, (), (override));
};

#endif
