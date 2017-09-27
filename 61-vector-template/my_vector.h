#ifndef __MY_VECTOR_H
#define __MY_VECTOR_H

#include <stdexcept>
#include <iostream>

template <class T>
class Vector{
    public:
        Vector() : Vector(0) {}
        explicit Vector(size_t initSize) : n{initSize} {
            n = initSize;
            c = initSize;
            arr = nullptr;
            if (n > 0) {
                arr = new T[n];
            }
         }
         Vector(size_t initSize, const T& value) : Vector(initSize){
             for (size_t i = 0; i < n; i++) {
                 arr[i] = value;
             }
         }
        ~Vector() {
            delete[] arr;
            //std::cout << "I'm Going out! BYE!" << '\n';
         }
        bool empty() const {return n == 0;}
        size_t size() const { return n;}
        size_t capacity() const { return c;}
        void push_back(const T& value) {
            ensureEmptySlot();
            arr[n] = value;
            n++;
         }
        void insert(const T& value, size_t index) {
            if (index > n) {
                throw std::out_of_range("invalid index!");
            }
            ensureEmptySlot();
            for (size_t i = n; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = value;
            n++;
         }
        T& at(size_t index) {
            if (index >= n) {
                throw std::out_of_range("invalid index!");
            }
            return arr[index];
        }
        T& operator [] (size_t index) {
            return arr[index];
        }
        const T& operator [] (size_t index) const {
            return arr[index];
        }

    private:
        size_t n;
        size_t c;
        T* arr;
        void ensureEmptySlot() {
            if (n == c) {
                c = c * 2;
                if (c == 0) c++;
                T* copy = new T[c];
                for (size_t i = 0; i < n; i++) {
                    copy[i] = arr[i];
                }
                delete[] arr;
                arr = copy;
            }
        }
};

#endif
