#include "AST.h"
#include "Nodes.h"
#include "Stack.h"
#include <sstream>
#include <string>
#include <ctype.h>
using std::istringstream;
using std::string;

bool isNumber(string& str)
{
    bool havedot=0;
    for (size_t i=0;i<str.length();i++) {
       char c =str[i];
       if(i==0){
            if (std::isdigit(c) == 0&&c!='+'&&c!='-')
            return false;
       }
       else{
        
        if (std::isdigit(c) == 0){
            if(c=='.'&&havedot==0){
                havedot=1;
            }
            else{
                return false;
            }
        }
         
       }
    }
    return true;
}

AST* AST::parse(const std::string& expression) {
    stack newstack;
    istringstream my_stream(expression);
    std::string n;
    while(my_stream){
        my_stream>>n;
        if(isNumber(n)){
            double d1;
            std::stringstream(n) >> d1;
            num* newnumber=new num(d1);
            newstack.push(newnumber);
            }
        else if(n=="+"||n=="-"||n=="*"||n=="/"||n=="%"||n=="~"){
            if(n=="~"&&newstack.haveone()==0){
                throw std::runtime_error("Not enough operands.");
            }
            else if(newstack.havetwo()==0){
                throw std::runtime_error("Not enough operands.");
            }
            else{
                if(n=="+"){
                    plus* newplus=new plus(newstack.pop()->element,newstack.pop()->element);
                    newstack.push(newplus);
                }
                else if(n=="-"){
                    minus* newast=new minus(newstack.pop()->element,newstack.pop()->element);
                    newstack.push(newast);
                 }
                 else if(n=="*"){
                    multi* newast=new multi(newstack.pop()->element,newstack.pop()->element);
                    newstack.push(newast);
                 }
                 else if(n=="/"){
                    divi* newast=new divi(newstack.pop()->element,newstack.pop()->element);
                    newstack.push(newast);
                 }
                 else if(n=="%"){
                    remai* newast=new remai(newstack.pop()->element,newstack.pop()->element);
                    newstack.push(newast);
                 }
                 else{

                    negate* newast=new negate(newstack.pop()->element);
                    newstack.push(newast);
                 }

            }
        }
        else{
            std::string const outerror = "Invalid token: "+n;
            throw std::runtime_error(outerror);
        }
        
    }
    if(newstack.gettop()==nullptr){
         throw std::runtime_error("No input.");
    }
    else if(newstack.gettop()->next!=nullptr){
        throw std::runtime_error("Too many operands.");
    }
    else{
    return newstack.gettop()->element;
    }
        




}
