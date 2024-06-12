#ifndef _VECTOR_MONITOR_H_
#define _VECTOR_MONITOR_H_

#include <iostream>
#include <vector>
#include <mutex>
#include <memory>
 
template <typename T>
class VectorMonitor {
private:
    mutable std::mutex m; // Si no pongo mutable no puedo usar lock en metodos const
    std::vector<T> vector_comun;
 
public:
    VectorMonitor() = default;

    explicit VectorMonitor(size_t initial_size);
 
    void push_back(const T& value);
 
    T at(size_t index) const;
 
    void clear();
 
    size_t size() const;
 
    bool empty() const;
 
    T operator[](size_t index) const;

    void remove(size_t index);

    std::vector<T>& get_vector();

    // MNeotodos para poder iterar sobre el vector
    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    typename std::vector<T>::const_iterator begin() const;
    typename std::vector<T>::const_iterator end() const;
    typename std::vector<T>::iterator erase(typename std::vector<T>::iterator pos);
};

#endif
