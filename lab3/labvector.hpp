#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <functional>
#include <cstring>
#include <assert.h>

template<typename T>
class labvector {
    private:
    void * mem;
    u_int len = 0;
    u_int maxLen = 1;
    u_int resizeFactor = 2;

    public:
    labvector() {
        this->mem = malloc(this->maxLen*sizeof(T));
    }

    void kill() {
        free(this->mem);
    }

    void push_back(T v) {
        this->len += 1;
        if (this->len > this->maxLen) {
            this->maxLen *= this->resizeFactor;
            this->mem = realloc(this->mem, this->maxLen*sizeof(T));
        }
        this->set(this->len-1, v);
    }

    void insert(u_int i, T v) {
        assert(i <= this->len && "Out of range");
        this->len += 1;
        if (this->len > this->maxLen) {
            this->maxLen *= this->resizeFactor;
            this->mem = realloc(this->mem, this->maxLen*sizeof(T));
        }
        memcpy(this->mem+(i+1)*sizeof(T), this->mem+i*sizeof(T), (this->len-i)*sizeof(T));
        this->set(i, v);
    }

    void remove(u_int i) {
        assert(i < this->len && "Out of range");
        memcpy(this->mem+i*sizeof(T), this->mem+(i+1)*sizeof(T), (this->len-i-1)*sizeof(T));

        this->len -= 1;
        if (this->len < this->maxLen/resizeFactor) {
            this->maxLen /= this->resizeFactor;
            this->mem = realloc(this->mem, this->maxLen*sizeof(T));
        }
    }

    void clear() {
        free(this->mem);
        this->len = 0;
        this->maxLen = 1;
        this->mem = malloc(this->maxLen*sizeof(T));
    }

    u_int getSize() {
        return this->len;
    }

    T get(u_int i) {
        assert(i < this->len && "Out of range");
        return *((T*)(this->mem+sizeof(T)*i));
    }

    void set(u_int i, T v) {
        assert(i < this->len && "Out of range");
        memcpy(this->mem+sizeof(T)*i, &v, sizeof(T));
    }
};