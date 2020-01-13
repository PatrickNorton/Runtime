//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_CONSTANT_H
#define RUNTIME_CONSTANT_H


#include "Variable.h"

namespace Constants {
    class _Constant : public _Variable {
    };

    class String : public _Constant {
    private:
        std::string value;
    public:
        explicit String(std::string value);
        std::string str() override;
        Variable callOperator(Operator o, std::vector<Variable> args) override;
    };

    class Function : public _Constant {
    private:
        void (*function)(const std::vector<Variable>&);
    public:
        explicit Function(void (*caller)(const std::vector<Variable>&));
        std::string str() override;
        Variable callOperator(Operator o, std::vector<Variable> args) override;
    };


    typedef std::shared_ptr<_Constant> Constant;
}


#endif //RUNTIME_CONSTANT_H
