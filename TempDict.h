//
// Created by Patrick Norton on 24/2/20.
//

#ifndef RUNTIME_TEMPDICT_H
#define RUNTIME_TEMPDICT_H


#include <unordered_map>
#include "Variable.h"
#include "DictUtils.h"
#include "Type.h"

namespace Constants {class DictType;}

class TempDict : public _Variable {
private:
    friend class Constants::DictType;
    std::vector<DictUtils::DictPair> internal;
    static size_t hash(const Variable&, Runtime*);
    static size_t highestOneBit(size_t);

public:
    TempDict();
    TempDict(const std::vector<Variable>&, const std::vector<Variable>&, Runtime*);
    Variable operator[] (std::pair<std::string, Runtime*>) override;
    Variable operator[] (std::pair<Operator, Runtime*>) override;
    Variable operator[] (const std::pair<Variable, Runtime*>&);
};

typedef std::shared_ptr<TempDict> DictPtr;

namespace Constants {
    class DictType : public _Type {
    private:
        static void dictStr(const DictPtr&, const std::vector<Variable>&, Runtime*);
        static void dictGet(const DictPtr&, const std::vector<Variable>&, Runtime*);
        static void dictSet(const DictPtr&, const std::vector<Variable>&, Runtime*);
        static void dictClear(const DictPtr&, const std::vector<Variable>&, Runtime*);

    public:
        static GenericMethod<TempDict> methodOf(Operator);
        static GenericMethod<TempDict> methodOf(const std::string&);
    };
}


#endif //RUNTIME_TEMPDICT_H
