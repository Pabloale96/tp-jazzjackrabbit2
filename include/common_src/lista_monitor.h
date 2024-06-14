#ifndef _LISTA_MONITOR_H_
#define _LISTA_MONITOR_H_

#include <iostream>
#include <list>
#include <mutex>
#include <stdexcept>

template <typename T>
class ListaMonitor {
private:
    mutable std::mutex m;  // Si no pongo mutable no puedo usar lock en metodos const
    std::list<T> lista_comun;

public:
    ListaMonitor() = default;

    void push_back(const T& value) {
        std::lock_guard<std::mutex> lock(m);
        lista_comun.push_back(value);
    }

    T pop_front() {
        std::lock_guard<std::mutex> lock(m);
        if (lista_comun.empty()) {
            throw std::out_of_range("List is empty");
        }
        T value = lista_comun.front();
        lista_comun.pop_front();
        return value;
    }

    T at(size_t index) const {
        std::lock_guard<std::mutex> lock(m);
        if (index >= lista_comun.size()) {
            throw std::out_of_range("Index out of range");
        }
        auto it = lista_comun.begin();
        std::advance(it, index);
        return *it;
    }

    void clear() {
        std::lock_guard<std::mutex> lock(m);
        lista_comun.clear();
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(m);
        return lista_comun.size();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return lista_comun.empty();
    }

    void remove(size_t index) {
        std::lock_guard<std::mutex> lock(m);
        if (index >= lista_comun.size()) {
            throw std::out_of_range("Index out of range");
        }
        auto it = lista_comun.begin();
        std::advance(it, index);
        lista_comun.erase(it);
    }
};

#endif
