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

namespace Constants {
    class _Type : public _Variable {
    private:
        typedef std::shared_ptr<_Type> Type;
        std::unordered_map<Operator, Callable> operators;
        std::set<Type> supers;

        inline Type this_ptr() {
            return std::static_pointer_cast<_Type>(shared_from_this());
        }
    public:
        explicit _Type(std::unordered_map<Operator, Callable>, std::set<Type> = {});
        bool isSubclassOf(const Type&);
        bool isTypeOf(const Variable &var) override;
    };
}

typedef std::shared_ptr<Constants::_Type> Type;

#endif //RUNTIME_TYPE_H
