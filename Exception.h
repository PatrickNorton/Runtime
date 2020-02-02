//
// Created by Patrick Norton on 31/1/20.
//

#ifndef RUNTIME_EXCEPTION_H
#define RUNTIME_EXCEPTION_H


#include "Variable.h"

namespace Constants {
    class Exception : public _Variable {
    private:
        std::string message;
    public:
        explicit Exception(std::string);
        std::string getMessage();
    };
}


#endif //RUNTIME_EXCEPTION_H
