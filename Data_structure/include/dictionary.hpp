#ifndef DICTIONARY
#define DICTIONARY

template<class A, class B>
class dictionary {
    public:
        virtual ~dictionary() = 0;
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual pair<const A, B>* find(const A& key) = 0;
        virtual void insert(const pair<const A, B>&) = 0;
        virtual void erase(const A& key) = 0;
};

#endif