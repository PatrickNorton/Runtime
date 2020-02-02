#include <vector>
#include "FileParsing.h"
#include "Exit.h"

int main(int argc, const char* argv[]) {
    auto args = std::vector<std::string>(argv + 1, argv + argc);
    try {
        for (const auto& arg : args) {
            parseFile(arg).execute();
        }
    } catch (const Exit&) {
        return EXIT_FAILURE;
    }
    return 0;
}