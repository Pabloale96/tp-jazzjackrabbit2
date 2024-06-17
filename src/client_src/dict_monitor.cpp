#include "../../include/client_src/dict_monitor.h"

#include "../../include/client_src/gui/gui_enemigos.h"
#include "../../include/client_src/gui/gui_personaje.h"

template <typename T>
DictMonitor<T>::DictMonitor() {}

template <typename T>
std::map<uint16_t, T>& DictMonitor<T>::obtener_diccionario() {
    std::unique_lock<std::mutex> lock(m);
    return dict;
}

template <typename T>
int DictMonitor<T>::size() {
    std::unique_lock<std::mutex> lock(m);
    return dict.size();
}

template <typename T>
typename std::map<uint16_t, T>::iterator DictMonitor<T>::find(uint16_t client_id) {
    std::unique_lock<std::mutex> lock(m);
    return dict.find(client_id);
}

template <typename T>
void DictMonitor<T>::emplace(uint16_t id, T value) {
    std::unique_lock<std::mutex> lock(m);
    dict.emplace(id, value);
}

template <typename T>
DictMonitor<T>::~DictMonitor() {}

template <typename T>
typename std::map<uint16_t, T>::iterator DictMonitor<T>::end() {
    std::unique_lock<std::mutex> lock(m);
    return dict.end();
}

template <typename T>
typename std::map<uint16_t, T>::iterator DictMonitor<T>::begin() {
    std::unique_lock<std::mutex> lock(m);
    return dict.begin();
}

template <typename T>
void DictMonitor<T>::erase(uint16_t client_id) {
    std::unique_lock<std::mutex> lock(m);
    dict.erase(client_id);
}

template class DictMonitor<std::shared_ptr<PersonajeGui>>;
template class DictMonitor<EnemigosGui>;
