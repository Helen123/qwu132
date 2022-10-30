#include "Stack.h"

// Implement your Stack member functions here.
Node::~Node(){
delete next;
}
stack::stack(){
    top=nullptr;
}
  stack::~stack(){
     delete top;  
  }

  Node* stack::gettop(){
    return top;
  }
    

  void stack::push(AST* a){
    Node* newnode;
    newnode->element=a;
    a=nullptr;
    newnode->next=top;
    top=newnode;
  }
  Node* stack::pop(){
    Node* temp=top;
    if(top!=nullptr){
      top=top->next;
    }
    temp->next=nullptr;
    return temp;
  }
  bool stack::havetwo(){
    Node* temp=top;
    for(int i =0;i<2;i++){
      if(temp==nullptr){
        return 0;
      }
      temp=temp->next;
    }
    return 1;

  }
