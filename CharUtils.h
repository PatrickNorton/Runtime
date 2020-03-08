//
// Created by Patrick Norton on 8/3/20.
//

#ifndef RUNTIME_CHARUTILS_H
#define RUNTIME_CHARUTILS_H


#include "Variable.h"
#include "Type.h"
#include "Method.h"

namespace Constants {
    class CharConstant;

    typedef std::shared_ptr<CharConstant> CharPtr;

    class CharType : public _Type {
    private:
        static void charStr(const CharPtr&, const std::vector<Variable>&, Runtime*);
        static void charPlus(const CharPtr&, const std::vector<Variable>&, Runtime*);
        static void charMinus(const CharPtr&, const std::vector<Variable>&, Runtime*);
        static void charInt(const CharPtr&, const std::vector<Variable>&, Runtime*);


    public:
        static GenericMethod<CharConstant> charMethod(Operator);
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
    };

    class CharConstant : public _Constant {
    private:
        friend class CharType;
        char16_t value;
        std::unordered_map<Operator, std::shared_ptr<GenericM<CharConstant>>> methods;

    public:
        explicit CharConstant(char16_t value);
        Type getType() override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };

    Constant fromNative(char16_t val);
}


#endif //RUNTIME_CHARUTILS_H
