#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include "queue.hpp"
#include "arrayList.hpp"

template <class T> 
class arrayQueue : public queue<T>, public arrayList<T> {
    public:
        arrayQueue(int capability) : arrayList<T>(capability) {};
        bool empty() const { return arrayList<T>.empty(); }
        int size() const { return arrayList<T>.size(); }
        T& back() {
            if(empty()) {
                throw std::invalid_argument("empty");
            }
            else {
                return get(arrayList<T>.size()-1);
            }
        }
        T& front() {
            if(empty()) {
                throw std::invalid_argument("empty");
            }
            else {
                return get(0);
            }
        }
        void pop() {
            if (empty()) {
                throw std::invalid_argument("empty");
            }
            else {
                erase(0);
            }
        }
        void push(const T& Element) {
            insert(arrayList<T>.size(), Element);
        }
};

#endif