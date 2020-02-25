//
// Created by Patrick Norton on 24/2/20.
//

#include "DictUtils.h"

#include <utility>
#include "Runtime.h"

namespace DictUtils {
    DictPair::DictPair() = default;

    DictPair::DictPair(Variable key, Variable val, size_t hash) {
        this->key = std::move(key);
        this->value = std::move(val);
        this->hash = hash;
        this->next = nullptr;
    }

    DictPair::operator bool() const {
        return key != nullptr;
    }

    void DictPair::emplace(Variable key2, Variable value2, size_t hash2, Runtime* runtime) {
        if (equals(key, key2, runtime)) {
            key = key2;
            value = value2;
            hash = hash2;
        } else if (next != nullptr) {
            next->emplace(std::move(key2), std::move(value2), hash2, runtime);
        } else {
            next = new DictPair(key2, value2, hash2);
        }
    }

    Variable DictPair::operator[](std::pair<Variable, Runtime*> pair) {
        if (equals(pair.first, key, pair.second)) {
            return value;
        } else if (next == nullptr) {
            return nullptr;
        } else {
            return (*next)[std::move(pair)];
        }
    }

    bool DictPair::equals(const Variable& a, Variable b, Runtime* runtime) {
        runtime->call(a, Operator::EQUALS, {std::move(b)});
        return runtime->pop()->toBool(runtime);
    }

    Variable DictPair::getKey() const {
        return key;
    }

    Variable DictPair::getValue() const {
        return value;
    }

    DictPair& DictPair::getNext() const {
        return *next;
    }

    bool DictPair::hasNext() const {
        return next != nullptr;
    }

}