#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include<iostream>

template <class T>
class linearList{
    public:
        virtual ~linearList() {};
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual T& get(int Index) const = 0;
        virtual int indexOf(const T& Element) const = 0;
        virtual void erase(int Index) = 0;
        virtual void insert(int Index, const T& Element) = 0;
        virtual void output(std::ostream& out) const = 0;
};

#endif

