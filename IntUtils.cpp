//
// Created by Patrick Norton on 16/1/20.
//

#include <unordered_map>
#include "IntUtils.h"

std::unordered_map<Bigint, Constants::Constant> __loadInterned() {
    static const Bigint MAX {0xff};
    std::unordered_map<Bigint, Constants::Constant> interns {};
    for (Bigint i = Bigint(0); i < MAX; ++i) {
        interns[i] = std::make_shared<Constants::IntConstant>(Constants::IntConstant(i));
    }
    return interns;
}

Constants::Constant Constants::fromNative(const Bigint& val) {
    static std::unordered_map<Bigint, Constant> interns = __loadInterned();
    if (interns.count(val)) {
        return interns[val];
    } else {
        return std::make_shared<IntConstant>(Constants::IntConstant(val));
    }
}
