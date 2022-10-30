#include "Stack.h"

// Implement your Stack member functions here.
Node::Node(){
  element=nullptr;
  next=nullptr;
}
Node::~Node(){
  delete element;
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
    Node* newnode=new Node();
    newnode->element=a;
    a=nullptr;
    newnode->next=top;
    top=newnode;
    newnode=nullptr;
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
    temp=nullptr;
    return 1;

  }
    bool stack::haveone(){
    if(top!=nullptr){
      return 1;
    }
    return 0;
    }
size_t stack::getcount(){
  Node* temp= top;
  size_t count=0;
  while(temp!=nullptr){
    count++;
    temp=temp->next;
  }
  temp=nullptr;
  return count;
}