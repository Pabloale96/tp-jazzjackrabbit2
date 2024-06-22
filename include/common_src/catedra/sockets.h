#ifndef SOCKET_H
#define SOCKET_H

#include <stdexcept>

class Socket {
private:
    int skt;
    bool closed;

    void chk_skt_or_fail() const;

public:
    explicit Socket(int skt);
    Socket(const char* hostname, const char* servname);
    explicit Socket(const char* servname);

    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;

    Socket(Socket&&);
    Socket& operator=(Socket&&);

    virtual int sendsome(const void* data, unsigned int sz, bool* was_closed);
    virtual int recvsome(void* data, unsigned int sz, bool* was_closed);
    virtual int sendall(const void* data, unsigned int sz, bool* was_closed);
    virtual int recvall(void* data, unsigned int sz, bool* was_closed);
    virtual Socket accept();
    virtual void shutdown(int how);
    virtual int close();

    virtual ~Socket();
};
#endif
