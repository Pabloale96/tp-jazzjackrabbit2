#ifndef _GAMELOOP_MONITOR_H
#define _GAMELOOP_MONITOR_H

#include <mutex>

class GameloopMonitor {
private:
    std::mutex m;
public:
    GameloopMonitor(/* args */);
    ~GameloopMonitor();
};

GameloopMonitor::GameloopMonitor(/* args */)
{
}

GameloopMonitor::~GameloopMonitor()
{
}

#endif
