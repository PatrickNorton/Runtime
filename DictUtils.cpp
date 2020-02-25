//
// Created by Patrick Norton on 24/2/20.
//

#include "DictUtils.h"

#include <utility>
#include "Runtime.h"

namespace DictUtils {
    DictPair::DictPair() : key(nullptr), value(nullptr), hash(0), next(nullptr) {}

    DictPair::DictPair(Variable key, Variable val, size_t hash) {
        this->key = std::move(key);
        this->value = std::move(val);
        this->hash = hash;
        this->next = nullptr;
    }

    DictPair::operator bool() const {
        return key != nullptr;
    }

    bool DictPair::emplace(Variable key2, Variable value2, size_t hash2, Runtime* runtime) {
        if (key == nullptr || equals(key, key2, runtime)) {
            bool ret = key == nullptr;
            key = key2;
            value = value2;
            hash = hash2;
            return ret;
        } else if (next != nullptr) {
            return next->emplace(std::move(key2), std::move(value2), hash2, runtime);
        } else {
            next = new DictPair(key2, value2, hash2);
            return true;
        }
    }

    bool DictPair::emplace(DictPair pair, Runtime* runtime) {
        if (key == nullptr || equals(key, pair.key, runtime)) {
            bool ret = key == nullptr;
            *this = std::move(pair);
            return ret;
        } else if (next != nullptr) {
            return next->emplace(std::move(pair), runtime);
        } else {
            next = new DictPair(pair);
            return true;
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
        if (a == nullptr)
            return b == nullptr;
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

    size_t DictPair::getHash() const {
        return hash;
    }
}