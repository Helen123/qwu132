#include "AST.h"
#include "Nodes.h"
#include "Stack.h"
#include <sstream>
#include <iostream>
#include <string>
#include <ctype.h>
using std::istringstream;
using std::string;
//using namespace std;

bool isNumber(string& str)
{
    bool havedot=0;
    if(str=="+"||str=="-"){
        return 0;
    }
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
    while(my_stream>>n){
        //std:: cout<<"inwhile"<<std::endl;
        if(isNumber(n)){
           // std:: cout<<"innumber"<<std::endl;
            double d1;
            std::stringstream(n) >> d1;
            num* newnumber=new num(d1);
            newstack.push(newnumber);
            }
        else if(n=="+"||n=="-"||n=="*"||n=="/"||n=="%"||n=="~"){
            if(n=="~"&&newstack.gettop()==nullptr){
                throw std::runtime_error("Not enough operands.");
            }
            else if(newstack.havetwo()==0){
                throw std::runtime_error("Not enough operands.");
            }
            else{
                if(n=="+"){
                     //std:: cout<<"inadd"<<std::endl;
                     Node* temp1=newstack.pop();
                     Node* temp2=newstack.pop();
                     plus* newplus=new plus(temp1->element,temp2->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                     newstack.push(newplus);
                }
                else if(n=="-"){
                    Node* temp1=newstack.pop();
                     Node* temp2=newstack.pop();
                      minus* newast=new minus(newstack.pop()->element,newstack.pop()->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                
                    newstack.push(newast);
                 }
                 else if(n=="*"){
                    Node* temp1=newstack.pop();
                     Node* temp2=newstack.pop();
          multi* newast=new multi(newstack.pop()->element,newstack.pop()->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                    
                    newstack.push(newast);
                 }
                 else if(n=="/"){
                    Node* temp1=newstack.pop();
                     Node* temp2=newstack.pop();
                divi* newast=new divi(newstack.pop()->element,newstack.pop()->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                   
                    newstack.push(newast);
                 }
                 else if(n=="%"){
                    Node* temp1=newstack.pop();
                     Node* temp2=newstack.pop();
                    remai* newast=new remai(newstack.pop()->element,newstack.pop()->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                  
                    newstack.push(newast);
                 }
                 else{
                    Node* temp1=newstack.pop();
                     
                     negate* newast=new negate(newstack.pop()->element);
                     delete temp1;
                    
                     temp1=nullptr;
            

                   
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
