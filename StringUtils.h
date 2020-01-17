//
// Created by Patrick Norton on 16/1/20.
//

#ifndef RUNTIME_STRINGUTILS_H
#define RUNTIME_STRINGUTILS_H

#include "Constant.h"

namespace Constants {

    class String : public _Constant {
    private:
        std::string value;
    public:
        explicit String(std::string value);
        std::string str() override;
        Variable callOperator(Operator o, std::vector<Variable> args) override;
    };

    Constant fromNative(const std::string& val);
    Constant fromNative(const std::string& val, bool intern);
}

#endif //RUNTIME_STRINGUTILS_H
