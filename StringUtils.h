//
// Created by Patrick Norton on 16/1/20.
//

#ifndef RUNTIME_STRINGUTILS_H
#define RUNTIME_STRINGUTILS_H

#include <map>

#include "Constant.h"
#include "Type.h"
#include "Method.h"

namespace Constants {
    class String;

    typedef std::shared_ptr<String> StringPtr;
    
    class StringType : public _Type {
    private:
        static void strAdd(const StringPtr& self, const std::vector<Variable>& args, Runtime* runtime);
        static void strMul(const StringPtr& self, const std::vector<Variable>& args, Runtime* runtime);
        static void strBool(const StringPtr& self, const std::vector<Variable>& args, Runtime* runtime);
        static void pushSelf(const StringPtr& self, const std::vector<Variable>& args, Runtime* runtime);

    public:
        StringType();
        static GenericMethod<String> strMethod(Operator o);
    };

    class String : public _Constant {
    private:
        friend class StringType;
        std::string value;
        std::map<Operator, std::shared_ptr<GenericM<String>>> methods;
    public:
        explicit String(std::string value);
        std::string str(Runtime* ) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };

    Constant fromNative(const std::string& val);
    Constant fromNative(const std::string& val, bool intern);
}

#endif //RUNTIME_STRINGUTILS_H
