#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
class myvector {
private:
    T* data {nullptr};
    int size {0};
    int capacity {0};

    // TODO: double_cap

    // TODO: halve_cap

    std::string str() const {
        std::ostringstream os;
        os << "[";
        if (size != 0) {
            os << data[0];
            for (int i=1; i<size; i++) {
                os << " " << data[i];
            }
        }
        os << "] size: " << size << " capacity: " << capacity;
        return os.str();
    }

public:
    myvector() = default;

    myvector(const myvector<T>& other) {
        *this = other;
    }

    ~myvector() {delete [] data;}

    int get_size() const {return size;}

    // TODO: pop_back

    // TODO: push_back

    // TODO: operator=

    // TODO: pre-increment operator++

    // TODO: post-increment operator++

    // TODO: member operator*

    // TODO: RW operator[]

    // TODO: operator==

    // TODO: operator<<

    // TODO: non-member operator*
};


#endif //VECTOR_H
