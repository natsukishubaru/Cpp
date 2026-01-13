#include <iostream>
using namespace std;

// v, v(), v(5), v(5, 2), v = {}, v = {0}, v = {1, 2};
// push_back(), back(), pop_back(), v[5], size(), clear()

class vector {

    int* p;
    int v_size = 0;

public:
    
    
    vector() : p(nullptr) {}

    vector(int n) : v_size(n) {
        p = new int[v_size];
        
        for (int i = 0; i < v_size; i++) (*this)[i] = 0;
    }

    vector(int n, int x) : v_size(n) {
        p = new int[v_size];
        
        for (int i = 0; i < v_size; i++) (*this)[i] = x;
    }

    vector(const vector &v) {
        
        v_size = v.size();
        p = new int[v_size];

        for (int i = 0; i < v_size; i++) {
            (*this)[i] = v[i];
        }
    }

    ~vector() {
        delete[] p;
    }

    int& operator[](int x) const{
        return *(p + x);
    }

    vector& operator=(const vector &v) {
        delete[] p;

        v_size = v.size();
        int *p = new int[v_size];

        for (int i = 0; i < v_size; i++) {
            p[i] = v[i];
        }
        return *this;
    }

    void clear() {
        delete[] p;
        *this = vector();
    }

    int size() const {return v_size;}

    void push_back(int x) {
        vector v(this -> v_size + 1);

        for (int i = 0; i < v_size; i++) {
            v[i] = (*this)[i];
        }
        
        v[v_size] = x;
        
        this -> clear();
        *this = vector(v);
    }
    
    void pop_back() {
        if (v_size == 0) return;
        
        v_size--;
    }

    int back() const {
        return (*this)[v_size - 1];
    }
};
