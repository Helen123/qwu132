#include "Nodes.h"
#include "string"
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <iostream>
using std::istringstream;
using std::string;

// Implement your AST subclasses' member functions here.


// To format a double for output:
//   std::ostringstream stream;
//   stream << value;
//   return stream.str();

//helper:


//num:
num::num(double n){
    number=n;
}
std::string num::prefix()  const{
    std::ostringstream stream;
    stream << number;
    return stream.str();
}
std::string num::postfix() const{
    std::ostringstream stream;
    stream << number;
    return stream.str();
}
double num::value() const{
    return number;
}





//plus:
plus::plus(AST*& r, AST*& l){
    if(l!=nullptr&&r!=nullptr){
        left=l;
        l=nullptr;
        right=r;
        r=nullptr;
    }
    else{
        throw std::runtime_error("Not enough operands.");
    }
}    
plus::~plus(){
    delete left;
    left=nullptr;
    delete right;
    right=nullptr;
}
std::string plus::prefix()  const{
    std::string out="+";
    std:: string first=" ";
    first+=left->prefix();
    std:: string second=" ";
    second+=right->prefix();
    out.insert(out.length(),first);
    out.insert(out.length(),second);
    return out;
}
std::string plus::postfix() const{
    std::string out="+";
    std:: string first=right->postfix();
    first+=" ";
    std:: string second=left->postfix();
    second+=" ";
    out.insert(0,first);
    out.insert(0,second);
    return out;
}
double plus::value() const{
    double out=left->value()+right->value();
    return out;
}

//minus:
minus::minus(AST*& r, AST*& l){
    if(l!=nullptr&&r!=nullptr){
        left=l;
        l=nullptr;
        right=r;
        r=nullptr;
    }
    else{
        throw std::runtime_error("Not enough operands.");
    }
}    
minus::~minus(){
    delete left;
    left=nullptr;
    delete right;
    right=nullptr;
}
std::string minus::prefix()  const{
    std::string out="-";
    std:: string first=" ";
    first+=left->prefix();
    std:: string second=" ";
    second+=right->prefix();
    out.insert(out.length(),first);
    out.insert(out.length(),second);
    return out;
}
std::string minus::postfix() const{
    std::string out="-";
    std:: string first=right->postfix();
    first+=" ";
    std:: string second=left->postfix();
    second+=" ";
    out.insert(0,first);
    out.insert(0,second);
    return out;
}
double minus::value() const{
    double out=left->value()-right->value();
    return out;
}

//multi:
multi::multi(AST*& r, AST*& l){
    if(l!=nullptr&&r!=nullptr){
        left=l;
        l=nullptr;
        right=r;
        r=nullptr;
    }
    else{
        throw std::runtime_error("Not enough operands.");
    }
}    
multi::~multi(){
    delete left;
    left=nullptr;
    delete right;
    right=nullptr;
}
std::string multi::prefix()  const{
    std::string out="*";
    std:: string first=" ";
    first+=left->prefix();
    std:: string second=" ";
    second+=right->prefix();
    out.insert(out.length(),first);
    out.insert(out.length(),second);
    return out;
}
std::string multi::postfix() const{
    std::string out="*";
    std:: string first=right->postfix();
    first+=" ";
    std:: string second=left->postfix();
    second+=" ";
    out.insert(0,first);
    out.insert(0,second);
    return out;
}
double multi::value() const{
    double out=left->value()*right->value();
    return out;
}

//divi:
divi::divi(AST*& r, AST*& l){
    if(l!=nullptr&&r!=nullptr){
        left=l;
        l=nullptr;
        right=r;
        r=nullptr;
    }
    else{
        throw std::runtime_error("Not enough operands.");
    }
}    
divi::~divi(){
    delete left;
    left=nullptr;
    delete right;
    right=nullptr;
}
std::string divi::prefix()  const{
    std::string out="/";
    std:: string first=" ";
    first+=left->prefix();
    std:: string second=" ";
    second+=right->prefix();
    out.insert(out.length(),first);
    out.insert(out.length(),second);
    return out;
}
std::string divi::postfix() const{
    std::string out="/";
    std:: string first=right->postfix();
    first+=" ";
    std:: string second=left->postfix();
    second+=" ";
    out.insert(0,first);
    out.insert(0,second);
    return out;
}
double divi::value() const{
    if(right->value()==0){
        throw std::runtime_error("Division by zero.");
    }
    double out=left->value()/right->value();
    return out;
}

//remai:
remai::remai(AST*& r, AST*& l){
    if(l!=nullptr&&r!=nullptr){
        left=l;
        l=nullptr;
        right=r;
        r=nullptr;
    }
    else{
        throw std::runtime_error("Not enough operands.");
    }
}    
remai::~remai(){
    delete left;
    left=nullptr;
    delete right;
    right=nullptr;
}
std::string remai::prefix()  const{
    std::string out="%";
    std:: string first=" ";
    first+=left->prefix();
    std:: string second=" ";
    second+=right->prefix();
    out.insert(out.length(),first);
    out.insert(out.length(),second);
    return out;
}
std::string remai::postfix() const{
    std::string out="%";
    std:: string first=right->postfix();
    first+=" ";
    std:: string second=left->postfix();
    second+=" ";
    out.insert(0,first);
    out.insert(0,second);
    return out;
}
double remai::value() const{
    if(right->value()==0){
        throw std::runtime_error("Division by zero.");
    }
    double out=remainder(left->value() , right->value());
    return out;
}


//negate:
negate::negate(AST*& l){
    if(l==nullptr){
        throw std::runtime_error("Not enough operands.");
    }
    else{
       // std:: cout<<"newnegatecorrect"<<std::endl;
        left=l;
        l=nullptr;
        //std:: cout<<"newnegatecorrect"<<std::endl;
    }
}   
negate::~negate(){
    delete left;
    left=nullptr;
}
std::string negate::prefix()  const{
    std::string out="~";
    std:: string first=" ";
    first+=left->prefix();
    out.insert(out.length(),first);
    return out;
}
std::string negate::postfix() const{
    std::string out="~";
    std:: string second=left->postfix();
    second+=" ";
    out.insert(0,second);
    return out;
}
double negate::value() const{
    double out;
    out =0-left->value();
    return out;
}

