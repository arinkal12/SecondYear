#include <cstdint>
#include <cstring>
#include <iostream>
template<typename T>
class ArrayHandler {
private:
    size_t _size;
    T* _array;
    T _max;
    T _min;
    long long int _count;
public:
    ArrayHandler(size_t size = 10) {
        //
        _size = size;
        _array = new T[_size];
        _max = std::numeric_limits<T>::min();
        _min = std::numeric_limits<T>::max();
        _count = 0;
    }

    void AppendElem(T elem) {
        if (_count == _size) {
            _size += 10;
            T* new_arr = new T[_size];
            std::memcpy(new_arr, _array, _count * sizeof(T));
            delete[] _array;
            _array = new_arr;
        }
        _array[_count] = elem;
        _count++;
        if (elem > _max) {
            _max = elem;
        }
        if (elem < _min) {
            _min = elem;
        }
    }

    bool IsContains(T elem) {
        int l = 0, r = _count - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (_array[mid] == elem) {
                return mid;
            } else if (_array[mid] < elem) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
        
    }

    T GetMax() {
        return _max;// cibk
    }

    T GetMin() {
        return _min;
    }

    ~ArrayHandler() {
        delete[] _array;
    }
};
