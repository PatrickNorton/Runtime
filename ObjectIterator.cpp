//
// Created by Patrick Norton on 18/2/20.
//

#include "ObjectIterator.h"

#include <utility>
#include "Runtime.h"
#include "StringUtils.h"
#include "Exit.h"
#include "Builtins.h"

ObjectIterator::iterator& ObjectIterator::iterator::operator++() {
    try {
        super.runtime->call(super.obj, "next", {});
    } catch (NativeExc& exc) {
        assert(exc.getType()->isSubclassOf(Builtins::stopIteration()));
        result = super.runtime->pop();
        return *this;
    }
    result = nullptr;
    return *this;
}

Variable ObjectIterator::iterator::operator*() const {
    return result;
}

ObjectIterator::iterator::iterator(Variable result, ObjectIterator& super) : result(std::move(result)), super(super) {
}

ObjectIterator::iterator ObjectIterator::iterator::operator++(int) {
    iterator temp(result, super);
    super.runtime->call(super.obj, "next", {});
    result = super.runtime->pop();
    return temp;
}

bool ObjectIterator::iterator::operator==(iterator& other) const {
    return result == other.result;
}

bool ObjectIterator::iterator::operator!=(iterator& other) const {
    return result != other.result;
}

ObjectIterator::iterator ObjectIterator::begin() {
    return ++iterator(nullptr, *this);
}

ObjectIterator::iterator ObjectIterator::end() {
    return iterator(nullptr, *this);
}

ObjectIterator::ObjectIterator(Variable val, Runtime* runtime) : obj(std::move(val)), runtime(runtime) {
}
