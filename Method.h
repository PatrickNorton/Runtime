//
// Created by Patrick Norton on 23/1/20.
//

#ifndef RUNTIME_METHOD_H
#define RUNTIME_METHOD_H


#include "Constant.h"
#include "FileInfo.h"

namespace Constants {
    template <typename T>
    class Method : public _Constant {
    private:
        typedef std::shared_ptr<T> self_t;
        FileInfo* info;
        uint32_t index;
        self_t self;
    public:
        Method(self_t, FileInfo*, uint32_t);
        Method(self_t, uint32_t);
        void operator() (const std::vector<Variable>& , Runtime*) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };

    template <typename T>
    class GenericM : public _Constant {
    private:
        GenericMethod<T> value;
        std::shared_ptr<T> self;
    public:
        GenericM(std::shared_ptr<T>, GenericMethod<T>);
        void operator() (const std::vector<Variable>& , Runtime*) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };
}

#include "Method.inl"


#endif //RUNTIME_METHOD_H
