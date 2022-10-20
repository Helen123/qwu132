#include "Set.h"
#include <stdexcept>
#include <iostream>
#include <string>

Set::Set(){
    mRoot=nullptr;
}
Set::Set(const Set& other){
    if(other.mRoot!=nullptr){
    
      
      Node* newnode=new Node(*other.mRoot);
      mRoot=newnode;
    }
}
Set::Set(Set&& other){
  if(other.mRoot!=nullptr){
       
      mRoot=other.mRoot;
      other.mRoot=nullptr;
    }
}
  Set::~Set(){
    
      delete mRoot;
    
  }

size_t Set::clear(){
    size_t out=count();
    delete this;
    return out;
  }

bool Set::contains(const std::string& value) const{
  if(mRoot==nullptr){
    return 0;
  }
  else{
   return mRoot->nodecontains(value);
  }

}
size_t Set::count() const{
  if(mRoot==nullptr){
    return 0;
  }
  else{
   return mRoot->count;
  }
}
void Set::debug(){

  }
size_t Set::insert(const std::string& value){
    if(mRoot==nullptr){
      mRoot->data=value;
      mRoot->count++;
      return 1;
    }
    else{
      return mRoot->nodeinsert(value);
    }
  
  }


const std::string& Set::lookup(size_t n) const{
  if(mRoot==nullptr){
      throw std::out_of_range("out of range");
    }
    else{
      return mRoot->nodelookup(n);
    }
  
}
void Set::print() const{
  
} 
size_t Set::remove(const std::string& value){
  return 1;
}