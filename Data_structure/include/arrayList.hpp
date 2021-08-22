#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include "linearList.hpp"
#include <algorithm>

template<class T>
class arrayList:public linearList<T> {
    public:
        // initial
        arrayList(int capability = 10);
        arrayList(const arrayList<T>&);
        ~arrayList() {delete [] _element;}

        // ADT
        bool empty() const {return _length == 0;}
        int size() const {return _length;}
        T& get(int Index) const;
        int indexOf(const T& Element) const;
        void erase(int Index);
        void insert(int Index, const T& Element);
        friend std::ostream& operator<<(std::ostream& out, const arrayList& x) {out << 1 << std::endl; return out;};

        // Other methods
        int capability() {return _capability;}

    protected:
        T* _element;
        int _length;
        int _capability;
};

template <class T>
arrayList<T>::arrayList(int capability) {
    if (capability < 1) {
        throw std::invalid_argument("capability illegal");
    }
    _capability = capability;
    _element = new T[_capability];
    _length = 0;
}

template <class T>
arrayList<T>::arrayList(const arrayList<T>& copy){
    _capability = copy._capability;
    _length = copy._length;
    _element = new T[_capability];
    std::copy(copy._element, copy._element + _length, _element);
}

template <class T>
T& arrayList<T>::get(int Index) const{
    if (Index < 0 || Index > _length-1) {
        throw std::invalid_argument("index illegal, current length: " + std::to_string(_length));
    }
    return _element[Index];
}

template <class T>
int arrayList<T>::indexOf(const T& Element) const {
    int theIndex = (int) (std::find(_element, _element+_length, Element) - _element);
    if (theIndex == _length) {
        return -1;
    }
    else return theIndex;
}

template <class T>
void arrayList<T>::erase(int Index) {
    if (Index < 0 || Index > _length-1) {
        throw std::invalid_argument("capability illegal");
    }
    std::copy(_element+Index+1, _element+_length, _element+Index);
    _element[_length-1].~T();
    _length--;
}

template <class T>
void arrayList<T>::insert(int Index, const T& Element) {
    if (Index < 0 || Index > _capability) {
        throw std::invalid_argument("capability illegal");
    }
    if (_length == _capability) {
        T* temp = new T[_capability+1];
        std::copy(temp, temp+_capability, _element);
        delete [] _element;
        _element = temp;
    }
    std::copy_backward(_element+Index, _element+_length, _element+Index+1);
    _element[Index] = Element;
    _length ++;
}

#endif
