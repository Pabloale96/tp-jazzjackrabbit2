#ifndef __DIC_MONITOR_H__
#define __DIC_MONITOR_H__

#include <map>
#include <memory>
#include <vector>
#include <atomic>

#include "msgToSent.h"
#include "queue.h"

template <typename T>
class DictMonitor {
private:
    std::mutex m;
    std::map<uint16_t, T> dict;

public:
    DictMonitor();

    std::map<uint16_t, T>& obtener_diccionario();

    int size();

    typename std::map<uint16_t, T>::iterator find(uint16_t client_id);

    void emplace(uint16_t id, T value);

    typename std::map<uint16_t, T>::iterator end();

    typename std::map<uint16_t, T>::iterator begin();

    void erase(uint16_t client_id);

    void setDict(DictMonitor<T>& other);

    DictMonitor(const DictMonitor&) = delete;
    DictMonitor& operator=(const DictMonitor&) = delete;

    DictMonitor(DictMonitor&& other) noexcept {
        std::lock_guard<std::mutex> lock(other.m); // Lock this mutex
        dict = std::move(other.dict);
    }

    DictMonitor& operator=(DictMonitor&& other) noexcept {
        if (this != &other) {
            std::lock_guard<std::mutex> lock(m); // Lock this mutex
            std::lock_guard<std::mutex> other_lock(other.m); 
            dict = std::move(other.dict);
        }
        return *this;
    }

    ~DictMonitor();
};

#endif
