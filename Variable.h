//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_VARIABLE_H
#define RUNTIME_VARIABLE_H


#include <string>
#include "Operator.h"
#include "Bigint.h"

class Runtime;  // Forward declaration to make everything work out
namespace Constants {
    class _Type;
}
typedef std::shared_ptr<Constants::_Type> Type;

class _Variable : public std::enable_shared_from_this<_Variable> {
public:
    typedef std::shared_ptr<_Variable> Variable;
    virtual std::string str(Runtime *);
    virtual Bigint toInt(Runtime *);
    virtual bool toBool(Runtime*);
    virtual void operator() (const std::vector<Variable>&, Runtime*);
    virtual Variable operator[] (std::pair<std::string, Runtime*>);
    virtual Variable operator[] (std::pair<Operator, Runtime*>);

    virtual Type getType();
    virtual bool isTypeOf(const Variable&);
    virtual void set(const std::string&, const Variable&, Runtime*);

protected:
    template <typename T>
    std::shared_ptr<T> this_ptr() {
        return std::static_pointer_cast<T>(shared_from_this());
    }
};


typedef _Variable::Variable Variable;


#endif //RUNTIME_VARIABLE_H
