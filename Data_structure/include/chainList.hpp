#ifndef CHAIN_LIST
#define CHAIN_LIST

#include "linearList.hpp"

template <class T>
struct chainNode
{
    T _element;
    chainNode<T>* next;

    chainNode(){};
    chainNode(const T& element){
        this->_element = element;
    }
    chainNode(const T& element, chainNode<T>* next){
        this->_element = element;
        this->next = next;
    }
};



#endif