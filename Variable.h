//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_VARIABLE_H
#define RUNTIME_VARIABLE_H


#include <string>

class _Variable {
public:
    std::string str();
};

typedef std::shared_ptr<_Variable> Variable;


#endif //RUNTIME_VARIABLE_H
