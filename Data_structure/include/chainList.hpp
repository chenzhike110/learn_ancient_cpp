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

template <class T>
class chain : public linearList<T> {
    public:
        chain(int capability=10) : firstNode(NULL), _length(0){}
        chain(const chain<T>&);
        ~chain();

        bool empty() const {return _length == 0;}
        int size() const {return _length;}
        T& get(int Index) const;
        int indexOf(const T& Element) const;
        void erase(int Index);
        void insert(int Index, const T& Element);
        friend std::ostream& operator<< (std::ostream& output, const chain& x) {
            for(auto current=x.firstNode; current!=NULL; current=current->next) {
                output << current->_element << " ";
            }
            return output;
        }
    
    protected:
        int _length;
        chainNode<T>* firstNode;
};

template <class T>
chain<T>::chain(const chain<T>& copyList) {
    _length = copyList._length;
    if (_length == 0){
        firstNode = NULL;
        return;
    }
    chainNode<T>* sourceNode = copyList.firstNode;
    this->firstNode = new chainNode<T>(sourceNode->_element);

    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstNode;

    while(sourceNode != NULL) {
        targetNode->next = new chainNode<T>(sourceNode->_element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}

template <class T>
chain<T>::~chain() {
    while (firstNode != NULL){
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}  

template <class T>
T& chain<T>::get(int Index) const {
    chainNode<T>* current = firstNode;
    if (Index >= _length) {
        throw std::invalid_argument("index error");
    }
    else {
        for(u_int16_t i=0; i<Index; i++){
            current = current->next;
        }
    }
    return current->_element;
}

template <class T>
int chain<T>::indexOf(const T& Element) const {
    chainNode<T>* current = firstNode;
    int index = 0;
    while(current != NULL && current->_element != Element){
        current = current->next;
        index ++;
    }
    if(current == NULL){
        return -1;
    }
    else{
        return index;
    }
}

template <class T>
void chain<T>::erase(int Index) {
    if (Index >= _length || Index < 0) {
        throw std::invalid_argument("erase Index error");
    }
    if (Index == 0) {
        chainNode<T>* current = firstNode;
        firstNode = firstNode->next;
        delete current;
    }
    else {
        chainNode<T>* last = firstNode;
        chainNode<T>* current = firstNode->next;
        for(int i=1; i<Index; i++){
            last = current;
            current = current->next;
        }
        last->next = current->next;
        delete current;
    }
    _length --;
}

template <class T>
void chain<T>::insert(int Index, const T& Element) {
    if (Index > _length || Index < 0) {
        throw std::invalid_argument("insert Index error");
    }
    chainNode<T>* newNode = new chainNode<T>(Element);
    if (Index == 0) {
        newNode->next = firstNode;
        std::cout << "debug" << (firstNode == NULL) << std::endl;
        firstNode = newNode;
    }
    else {
        chainNode<T>* current = firstNode;
        for(u_int32_t i=1; i<Index; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    _length ++;
}

#endif