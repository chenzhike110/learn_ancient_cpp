#ifndef DERIVED
#define DERIVED

#include "stack.hpp"
#include "arrayList.hpp"

template <class T>
class derivedArrayStack : public stack<T>, public arrayList<T> {
    public:
        derivedArrayStack(int capability) : arrayList<T>(capability) {}
        bool empty() const {return arrayList<T>.empty();}
        int size() const {return arrayList<T>.size();}
        T& top() {
            if (empty()) {
                throw std::invalid_argument("empty!");
            }
            else {
                return get(arrayList<T>.size()-1);
            }
        }
        void pop() {
            if (empty()) {
                throw std::invalid_argument("empty!");
            }
            else {
                arrayList<T>.erase(arrayList<T>.size()-1);
            }
        }
        void push(const T& Element) {
            insert(size(), Element);
        }
};

#endif