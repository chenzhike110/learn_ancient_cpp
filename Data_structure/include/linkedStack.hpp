#ifndef LINKED
#define LINKED

#include "stack.hpp"
#include "chainList.hpp"

template <class T>
class linkedStack : public stack<T> {
    public:
        linkedStack(int capability) {
            stackTop = NULL;
            _length = 0;
        }
        ~linkedStack() {
            while (stackTop!=NULL) {
                chainNode<T>* node = stackTop;
                stackTop = stackTop->next;
                delete node;
            }
        }
        T& top() {
            chainNode<T>* node = new chainNode<T>(stackTop->_element);
            return node;
        }
        void pop() {
            if (_length == 0) {
                throw std::invalid_argument("empty!");
            }
            chainNode<T>* node = stackTop;
            stackTop = stackTop->next;
            delete node;
            _length --;
        }
        void push(const T& Element) {
            stackTop = new chainNode<T>(Element, stackTop);
        }
    
    private:
        chainNode<T>* stackTop;
        int _length;
};


#endif