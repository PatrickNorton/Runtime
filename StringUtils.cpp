//
// Created by Patrick Norton on 16/1/20.
//

#include "StringUtils.h"

#include <unordered_set>
#include <unordered_map>

Constants::Constant Constants::fromNative(const std::string& val) {
    return fromNative(val, false);
}

Constants::Constant Constants::fromNative(const std::string& val, bool intern) {
    if (intern) {
        static std::unordered_map<std::string, Constant> interns{};
        if (!interns.count(val)) {
            interns[val] = std::make_shared<String>(String(val));
        }
        return interns[val];
    } else {
        return std::make_shared<String>(String(val));
    }
}
