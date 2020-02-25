//
// Created by Patrick Norton on 24/2/20.
//

#ifndef RUNTIME_DICTUTILS_H
#define RUNTIME_DICTUTILS_H

#include "Variable.h"

namespace DictUtils {
    class DictPair {
    private:
        Variable key;
        Variable value;
        size_t hash;
        DictPair* next;

        static bool equals(const Variable&, Variable, Runtime*);
    public:
        DictPair();
        DictPair(Variable, Variable, size_t);
        explicit operator bool() const;
        bool emplace(Variable, Variable, size_t, Runtime*);
        bool emplace(DictPair, Runtime*);
        Variable operator[](std::pair<Variable, Runtime*>);
        Variable getKey() const;
        Variable getValue() const;
        DictPair& getNext() const;
        size_t getHash() const;
        bool hasNext() const;
    };
}

#endif //RUNTIME_DICTUTILS_H
