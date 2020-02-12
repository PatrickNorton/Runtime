//
// Created by Patrick Norton on 15/1/20.
//

#ifndef RUNTIME_TYPE_H
#define RUNTIME_TYPE_H


#include <memory>
#include <unordered_map>
#include <set>
#include "Operator.h"
#include "Constant.h"

namespace Constants {
    class _Type : public _Constant {
    private:
        typedef std::shared_ptr<_Type> Type;
        std::set<Type> supers;
    public:
        bool isSubclassOf(const Type&);
        bool isTypeOf(const Variable &var) override;
        void operator() (const std::vector<Variable>&, Runtime*) final;
        virtual Variable createNew(const std::vector<Variable>&, Runtime*);
        Type getType() final;
    };

    class TypeType : public _Type {
    public:
        bool isTypeOf(const Variable &var) override;
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
    };
}

typedef std::shared_ptr<Constants::_Type> Type;

#endif //RUNTIME_TYPE_H
