#ifndef STACK_H
#define STACK_H
#include "AST.h"

// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.
struct Node{
    AST* element;
    Node* next;
    Node();
    ~Node();
};
class stack{
    Node* top;

public:
  stack();
  ~stack();
  Node* gettop();
  void push(AST* a);
  Node* pop();
  bool havetwo();
  bool haveone();
  size_t getcount();


};

#endif
