#include <iostream>
#include <vector>

int main(int argc, const char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    auto args = std::vector<std::string>(argv, argv + argc);
    for (auto arg : args) {

    }
    return 0;
}