#ifndef NODES_H
#define NODES_H

#include "AST.h"

// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.
class num: public AST{
    public:
        double number;

        num(double n);

        std::string prefix()  const;
        std::string postfix() const;
        double      value()   const;
};

class plus: public AST{
    public:
        AST*             left;
        AST*             right;
        std::string self="plus";

        plus(AST*& r, AST*& l);
        ~plus();

        std::string prefix()  const;
        std::string postfix() const;
        double      value()   const;
};

class minus: public AST{
    public:
        AST*             left;
        AST*             right;
        std::string self="minus";

        minus(AST*& r, AST*& l);
        ~minus();

        std::string prefix()  const;
        std::string postfix() const;
        double      value()   const;
    


};
class multi: public AST{
    public:
        AST*             left;
        AST*             right;
        std::string self="multi";

        multi(AST*& r, AST*& l);
        ~multi();

        std::string prefix()  const;
        std::string postfix() const;
        double      value()   const;

};
class divi: public AST{
    public:
        AST*             left;
        AST*             right;
        std::string self="divi";

        divi(AST*& r, AST*& l);
        ~divi();

        std::string prefix()  const;
        std::string postfix() const;
        double      value()   const;

};
class remai: public AST{
    public:
        AST*             left;
        AST*             right;
        std::string self="remai";

        remai(AST*& l, AST*& r);
        ~remai();

        std::string prefix()  const;
        std::string postfix() const;
        double      value()   const;


};
class negate: public AST{
    public:
        AST*             left;
        std::string self="negate";

        negate(AST*& l);
        ~negate();

        std::string prefix()  const;
        std::string postfix() const;
        double      value()   const;


};

#endif
