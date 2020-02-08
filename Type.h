//
// Created by Patrick Norton on 15/1/20.
//

#ifndef RUNTIME_TYPE_H
#define RUNTIME_TYPE_H


#include <memory>
#include <unordered_map>
#include <set>
#include "Operator.h"
#include "Callable.h"
#include "Constant.h"

namespace Constants {
    class _Type : public _Constant {
    private:
        typedef std::shared_ptr<_Type> Type;
        std::unordered_map<Operator, Callable> operators;
        std::set<Type> supers;
    public:
        explicit _Type(std::unordered_map<Operator, Callable>, std::set<Type> = {});
        bool isSubclassOf(const Type&);
        bool isTypeOf(const Variable &var) override;
        void operator() (const std::vector<Variable>&, Runtime*) final;
        virtual Variable createNew(const std::vector<Variable>&, Runtime*);
    };
}

typedef std::shared_ptr<Constants::_Type> Type;

#endif //RUNTIME_TYPE_H
