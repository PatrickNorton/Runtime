//
// Created by Patrick Norton on 11/1/20.
//

#include <vector>
#include <iostream>
#include "Builtins.h"


void Builtins::print(std::vector<Variable> args) {
    for (auto arg : args) {
        std::cout << arg.str();
    }
}
