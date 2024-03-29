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
    stack* newstack=new stack();
    istringstream my_stream(expression);
    std::string n;
    while(my_stream>>n){
        //std:: cout<<"inwhile"<<std::endl;
        if(isNumber(n)){
           // std:: cout<<"innumber"<<std::endl;
            double d1;
            std::stringstream(n) >> d1;
            num* newnumber=new num(d1);
            newstack->push(newnumber);
            newnumber=nullptr;
            }
        else if(n=="+"||n=="-"||n=="*"||n=="/"||n=="%"||n=="~"){
            if(n=="~"&&newstack->gettop()==nullptr){
                //std:: cout<<"innegawrong"<<std::endl;
                delete newstack;
                newstack=nullptr;
                throw std::runtime_error("Not enough operands.");
            }
            else if(n!="~"&&newstack->havetwo()==0){
                //std:: cout<<n<<std::endl;
                //std:: cout<<"innumberwrong"<<std::endl;
                delete newstack;
                newstack=nullptr;
                throw std::runtime_error("Not enough operands.");
            }
            else{
                if(n=="+"){
                     //std:: cout<<"inadd"<<std::endl;
                     Node* temp1=newstack->pop();
                     Node* temp2=newstack->pop();
                     plus* newplus=new plus(temp1->element,temp2->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                     newstack->push(newplus);
                     newplus =nullptr;
                }
                else if(n=="-"){
                    Node* temp1=newstack->pop();
                     Node* temp2=newstack->pop();
                      minus* newast=new minus(temp1->element,temp2->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                
                    newstack->push(newast);
                    newast=nullptr;
                 }
                 else if(n=="*"){
                    Node* temp1=newstack->pop();
                     Node* temp2=newstack->pop();
          multi* newast=new multi(temp1->element,temp2->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                    
                    newstack->push(newast);
                    newast=nullptr;
                 }
                 else if(n=="/"){
                    Node* temp1=newstack->pop();
                     Node* temp2=newstack->pop();
                divi* newast=new divi(temp1->element,temp2->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                   
                    newstack->push(newast);
                    newast=nullptr;
                 }
                 else if(n=="%"){
                    Node* temp1=newstack->pop();
                     Node* temp2=newstack->pop();
                    remai* newast=new remai(temp1->element,temp2->element);
                     delete temp1;
                     delete temp2;
                     temp1=nullptr;
                     temp2=nullptr;
                  
                    newstack->push(newast);
                    newast=nullptr;
                 }
                 else{
                     //std:: cout<<"innegate"<<std::endl;
                    Node* temp1=newstack->pop();
                     //std:: cout<<"popcorrect"<<std::endl;
                     negate* newast=new negate(temp1->element);
                     //std:: cout<<"newcorrect"<<std::endl;
                     delete temp1;
                    
                     temp1=nullptr;
            

                   
                    newstack->push(newast);
                    newast=nullptr;
                 }

            }
        }
        else{
            delete newstack;
                newstack=nullptr;
            std::string const outerror = "Invalid token: "+n;
            throw std::runtime_error(outerror);
        }
        
    }
    if(newstack->gettop()==nullptr){
        delete newstack;
                newstack=nullptr;
         throw std::runtime_error("No input.");
    }
    else if(newstack->gettop()->next!=nullptr){
        delete newstack;
                newstack=nullptr;
        throw std::runtime_error("Too many operands.");
    }
    else{
       // std:: cout<<"inlast"<<std::endl;
        if(newstack->gettop()->element!=nullptr){
           // std:: cout<<"notnullelement"<<std::endl;
        }
         //std:: cout<<newstack->gettop()->element->value()<<std::endl;
         AST* temp=newstack->gettop()->element;
         newstack->gettop()->element=nullptr;
         delete newstack;
         newstack=nullptr;
    return temp;
    }
        




}
