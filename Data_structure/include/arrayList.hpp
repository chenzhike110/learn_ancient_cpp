#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include "linearList.hpp"

template<class T>
class arrayList {
    public:
        // initial
        arrayList(int capability = 10);
        arrayList(const arrayList<T>&);
        ~arrayList() {delete [] _element;}

        // ADT
        bool empty() {return _length == 0;}
        int size() {return _length;}
        T& get(int Index) const;
        int indexOf(const T& Element) const;
        void erase(int Index);
        void insert(int Index, const T& Element);
        void output(std::ostream& out) const;

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
        throw "capability illegal";
    }
    _capability = capability;
    _element = new T[_length];
    _length = 0;
}

template <class T>
arrayList<T>::arrayList(const arrayList<T>& copy){
    _capability = copy._capability;
    _length = copy._length;
    std::copy(copy._element, copy._element + _length, _element);
}

template <class T>
T& arrayList<T>::get(int Index) const{
    if (Index < 0 || Index > _length) {
        throw "index illegal";
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
void arrayList<T>::output(std::ostream& out) const {
    std::copy(_element, _element+_length, std::ostreambuf_iterator<T>(out, " "));
}

#endif
