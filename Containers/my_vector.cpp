#include <iostream>

using namespace std;

// Generic
// const availability
// constructors, default, parameterized
// copy ctr, Copy assignment, destructor 
// Capacity, Reallocation
// push, pop, insert size, empty, clear, empty
// front, back, Element Access [], 

template <typename T>
class Vector {

    T *data;
    int sz;
    int cap;

    // Reallocate memory if completly filled
    void reallocate(int new_cap) {
        T *new_data = new T[new_cap];

        for (int i = 0; i < sz; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        
        data = new_data;
        cap = new_cap;
    }

public:

    // Constructors 
    // Default Constructor
    Vector() : data(nullptr), sz(0), cap(0) {}

    // Allocate memory
    Vector(int n) : data(new T[n]), sz(n), cap(n) {
        for (int i = 0; i < n; i++) {
            data[i] = T();
        }
    }
    // Default value
    Vector(int n, const T &val) : data(new T[n]), sz(n), 
        cap(n) {
        
        for (int i = 0; i < sz; i++) {
            data[i] = T(val);
        }
    }
    
    // Copy Constructor
    Vector(const Vector &other) : data(new T[other.cap]), 
        sz(other.sz), cap(other.cap) {
        
        for (int i = 0; i < sz; i++) {
            data[i] = other[i];
        }
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Assignment Operator
    Vector& operator= (const Vector &other) {
        
        if (this != &other) {
            delete[] data;

            sz = other.sz;
            cap = other.cap;
            data = new T[cap];

            for (int i = 0; i < sz; i++) {
                data[i] = other[i];
            }
        }

        return *this;
    }

    // Element Access
    T& operator[] (const int index) {
        return data[index];
    }

    const T& operator[] (const int index) const {
        return data[index];
    }

    const T& front() const {
        return data[0];
    }
    T& front() {
        return data[0];
    }

    const T& back() const {
        return data[sz - 1];
    }

    T& back() {
        return data[sz - 1];
    }

    void push_back(const T &val) {
        if (sz == cap) {
            int new_cap = (cap == 0) ? 1 : 2 * cap;
            reallocate(new_cap);
        }
        data[sz++] = val;     // val is copied
    }

    void pop_back() {
        if (sz > 0) sz--;
    }

    void insert(int index, const T &val) {
        
        if (index > sz || index < 0) return;

        if (sz == cap) {
            int new_cap = (cap == 0) ? 1 : 2 * cap;
            reallocate(new_cap);
        }

        sz++;
        for (int i = sz - 1; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = val;
    }

    void erase(int index) {
        for (int i = index; i < sz - 1; i++) {
            data[i] = data[i + 1];
        }

        sz--;
    }

    void clear() {
        sz = 0;
    }

    void reserve(int new_cap) {
        if (new_cap > cap) {
            reallocate(new_cap);
        }
    }

    int size() const {
        return sz;
    }

    int capacity() const {
        return cap;
    }

    bool empty() const {
        return sz == 0;
    }

    // Iterator
    T* begin() {
        return data;
    }
    const T* begin() const {
        return data;
    }

    T* end() {
        return data + sz;
    }
    
    const T* end() const {
        return data + sz;
    }
};