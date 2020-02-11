//
// Created by Patrick Norton on 1/2/20.
//

#ifndef RUNTIME_EXIT_H
#define RUNTIME_EXIT_H


#include <exception>
#include <utility>

class Exit final : public std::exception {

};

class ThrownExc final : public std::exception {
private:
    Type type;
    std::string value;
public:
    ThrownExc(Type type, std::string msg) : type(std::move(type)), value(std::move(msg)) {
    }

    Type getType() {
        return type;
    }

    std::string getMessage() {
        return value;
    }
};


#endif //RUNTIME_EXIT_H
