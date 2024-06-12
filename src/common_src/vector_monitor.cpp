#include "../../include/common_src/vector_monitor.h"

#include "../../include/server_src/game/game_personaje.h"
#include "../../include/server_src/game/game_enemigo.h"
#include "../../include/server_src/game/game_collectible.h"

template <typename T>
VectorMonitor<T>::VectorMonitor(size_t initial_size) : vector_comun(initial_size) {}

template <typename T>
void VectorMonitor<T>::push_back(const T& value) {
    std::unique_lock<std::mutex> lock(m);
    vector_comun.push_back(value);
}

template <typename T>
T VectorMonitor<T>::at(size_t index) const {
    std::unique_lock<std::mutex> lock(m);
    if (index >= vector_comun.size()) {
        throw std::out_of_range("Index out of range");
    }
    return vector_comun.at(index);
}

template <typename T>
void VectorMonitor<T>::clear() {
    std::unique_lock<std::mutex> lock(m);
    vector_comun.clear();
}

template <typename T>
size_t VectorMonitor<T>::size() const {
    std::unique_lock<std::mutex> lock(m);
    return vector_comun.size();
}

template <typename T>
bool VectorMonitor<T>::empty() const {
    std::unique_lock<std::mutex> lock(m);
    return vector_comun.empty();
}

template <typename T>
T VectorMonitor<T>::operator[](size_t index) const {
    std::unique_lock<std::mutex> lock(m);
    if (index >= vector_comun.size()) {
        throw std::out_of_range("Index out of range");
    }
    return vector_comun[index];
}

template <typename T>
void VectorMonitor<T>::remove(size_t index) {
    std::unique_lock<std::mutex> lock(m);
    if (index >= vector_comun.size()) {
        throw std::out_of_range("Index out of range");
    }
    vector_comun.erase(vector_comun.begin() + index);
}

template <typename T>
std::vector<T>& VectorMonitor<T>::get_vector() {
    std::unique_lock<std::mutex> lock(m);
    return vector_comun;
}

template <typename T>
typename std::vector<T>::iterator VectorMonitor<T>::begin() {
    std::unique_lock<std::mutex> lock(m);
    return vector_comun.begin();
}

template <typename T>
typename std::vector<T>::iterator VectorMonitor<T>::end() {
    std::unique_lock<std::mutex> lock(m);
    return vector_comun.end();
}

template <typename T>
typename std::vector<T>::const_iterator VectorMonitor<T>::begin() const {
    std::unique_lock<std::mutex> lock(m);
    return vector_comun.begin();
}

template <typename T>
typename std::vector<T>::const_iterator VectorMonitor<T>::end() const {
    std::unique_lock<std::mutex> lock(m);
    return vector_comun.end();
}

template <typename T>
typename std::vector<T>::iterator VectorMonitor<T>::erase(typename std::vector<T>::iterator pos) {
    std::unique_lock<std::mutex> lock(m);
    return vector_comun.erase(pos);
}

template class VectorMonitor<std::shared_ptr<Personaje>>;
template class VectorMonitor<std::shared_ptr<Enemigo>>;
template class VectorMonitor<std::shared_ptr<Collectible>>;
