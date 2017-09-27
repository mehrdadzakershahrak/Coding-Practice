#ifndef __MY_VECTOR_H
#define __MY_VECTOR_H

#include <stdexcept>
#include <iostream>

template <class T>
class List{
    private:
        struct Node {
            T data;
            Node * next;
        };

    public:
        struct iterator {
            Node * node;
            const T& operator * () {
                return node->data;
            }
            iterator & operator++ () {
                node = node->next;
                return *this;
            }
            bool operator != (const iterator & other) {
                return node != other.node;
            }
        };

        struct const_iterator {
            Node * node;
            const T& operator * () {
                return node->data;
            }
            const_iterator & operator++ () {
                node = node->next;
                return *this;
            }
            bool operator != (const const_iterator & other) {
                return node != other.node;
            }
        };

    public:
        List() : n{0}, head{nullptr}, tail{nullptr}{ }
        ~List() {
            while (head != nullptr) {
                tail = head;
                head = head->next;
                delete tail;
            }
        }
        bool empty() const {return n == 0;}
        size_t size() const { return n;}
        void push_back(const T& value) {
            Node * node = new Node { value, nullptr};
            if (tail != nullptr) {tail->next = node; }
            tail = node;
            if (head == nullptr) { head = node;}
            n++;
        }
        void push_front(const T& value) {
            Node * node = new Node { value, nullptr};
            node->next = head;
            head = node;
            if (tail == nullptr) {tail = node;}
            n++;
        }
        iterator begin() {
            return iterator {head};
        }
        const_iterator begin() const {
            return const_iterator {head};
        }
        iterator end() {
            return iterator {nullptr};
        }
        const_iterator end() const{
            return const_iterator {nullptr};
        }

    private:
        size_t n;
        Node * head;
        Node * tail;

};

#endif
