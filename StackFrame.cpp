//
// Created by Patrick Norton on 26/1/20.
//

#include "StackFrame.h"

StackFrame::StackFrame(size_t varCount, uint16_t functionNumber)
    : variables(varCount), location(0), functionNumber(functionNumber), native(false), parent(nullptr), newFile(false) {
}

StackFrame::StackFrame() : native(true), newFile(false), parent(nullptr), functionNumber(0), location(0) {
}

StackFrame::StackFrame(size_t varCount, uint16_t functionNumber, bool)
        : variables(varCount), functionNumber(functionNumber), native(false), location(0), newFile(true), parent(nullptr) {
}

StackFrame::StackFrame(size_t varCount, uint16_t functionNumber, FramePtr parent)
    : variables(varCount), location(0), functionNumber(functionNumber), native(false), parent(std::move(parent)), newFile(false) {
}

StackFrame::StackFrame(size_t varCount, uint16_t functionNumber, FramePtr parent, bool)
        : variables(varCount), location(0), functionNumber(functionNumber), native(false), parent(std::move(parent)), newFile(true) {
}

uint32_t StackFrame::currentPos() const {
    return location;
}

void StackFrame::advance(uint32_t value) {
    location += value;
}

uint16_t StackFrame::getFnNumber() const {
    return functionNumber;
}

void StackFrame::resetVars(size_t varCount) {
    variables = std::vector<Variable>(varCount);
}

void StackFrame::jump(uint32_t pos) {
    location = pos;
}

void StackFrame::loadArgs(const std::vector<Variable>& vars) {
    variables.assign(vars.begin(), vars.end());
}

void StackFrame::store(uint32_t index, Variable variable) {
    if (variables.size() <= index) {
        variables.resize(index + 1);
    }
    variables[index] = std::move(variable);
}

Variable StackFrame::operator[](size_t index) const {
    size_t parentSize = parent == nullptr ? 0 : parent->size();
    return parentSize <= index ? variables[index - parentSize] : (*parent)[index];
}

void StackFrame::addExceptionHandler(const Variable& var) {
    exceptionHandlers.insert(var);
}

void StackFrame::removeExceptionHandler(const Variable& var) {
    exceptionHandlers.erase(var);
}

const std::set<Variable>& StackFrame::getExceptions() const {
    return exceptionHandlers;
}

bool StackFrame::isNative() const {
    return native;
}

bool StackFrame::isNewFile() const {
    return newFile;
}

size_t StackFrame::size() const {
    return parent == nullptr ? variables.size() : parent->size() + variables.size();
}
