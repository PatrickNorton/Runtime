#include <iostream>
#include <vector>
#include "FileParsing.h"

int main(int argc, const char* argv[]) {
    auto args = std::vector<std::string>(argv + 1, argv + argc);
    for (const auto& arg : args) {
        parseFile(arg);
    }
    return 0;
}