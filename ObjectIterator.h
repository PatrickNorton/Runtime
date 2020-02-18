//
// Created by Patrick Norton on 18/2/20.
//

#ifndef RUNTIME_OBJECTITERATOR_H
#define RUNTIME_OBJECTITERATOR_H


#include "Variable.h"

class ObjectIterator {
private:
    Variable obj;
    Runtime* runtime;
public:
    class iterator : public std::iterator<std::forward_iterator_tag, Variable> {
    private:
        Variable result;
        ObjectIterator& super;
    public:
        iterator(Variable result, ObjectIterator& super);
        Variable operator*() const;
        ObjectIterator::iterator& operator++();
        ObjectIterator::iterator operator++(int);
        bool operator==(iterator&) const;
        bool operator!=(iterator&) const;
    };

    ObjectIterator(Variable, Runtime*);

    iterator begin();
    iterator end();
};


#endif //RUNTIME_OBJECTITERATOR_H
