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
    for (char const &c : str) {
       
        // using the std::isdigit() function
        if (std::isdigit(c) == 0)
          return false;
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
            num* newnumber=new num(stod(n));
            newstack.push(&newnumber);
            }
        else if(n=="+"||n=="-"||n=="*"||n=="/"||n=="%"||n=="~"){
            if(newstack.havetwo()==0){
                throw std::runtime_error("Not enough operands.");
            }
            if(n=="+"){
            plus* newplus=new plus(newstack.pop()->element,newstack.pop()->element);
            newstack.push(newplus);
            }
            else if(n=="-"){
            plus* newplus=new plus(newstack.pop()->element,newstack.pop()->element);
            newstack.push(newplus);
            }
                

        }
        else{
            std::string const outerror = "Invalid token: "+n;
            throw std::runtime_error(outerror);
        }
               else if(n=="+"){

            plus* newplus=new plus(newstack.pop()->element,newstack.pop()->element);
            newstack.push(&newplus);
        }
        else if(n=="-")

        
    }
        




}
