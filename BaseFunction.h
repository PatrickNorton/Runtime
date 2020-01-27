//
// Created by Patrick Norton on 27/1/20.
//

#ifndef RUNTIME_BASEFUNCTION_H
#define RUNTIME_BASEFUNCTION_H


#include <cstdint>
#include <vector>
#include <string>

class BaseFunction {
private:
    std::string name;
    uint16_t localCount;
    std::vector<uint8_t> bytes;
public:
    BaseFunction();
    BaseFunction(std::string, uint16_t, std::vector<uint8_t>);
    const std::string& getName();
    const uint16_t& getLocalCount();
    const std::vector<uint8_t>& getBytes();

    uint8_t operator[] (size_t index);

    static BaseFunction parse(const std::vector<uint8_t>&, size_t&);
};


#endif //RUNTIME_BASEFUNCTION_H
