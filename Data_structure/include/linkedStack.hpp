#ifndef LINKED
#define LINKED

#include "stack.hpp"
#include "chainList.hpp"

template <class T>
class linkedStack : public stack<T> {
    public:
        linkedStack(int capability) {
            stackTop = NULL;
            _length = ;
        }
        ~linkedStack();
        T& top() {
            
        }
    
    private:
        chainNode<T>* stackTop;
        int _length;
};


#endif