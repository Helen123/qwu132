#include "Set.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
Node* helpremove(Node*& m, const std::string& value);

Set::Set(){
    mRoot=nullptr;
}
Set::Set(const Set& other){
    if(other.mRoot!=nullptr){
    
      
      Node* newnode=new Node(*other.mRoot);
      mRoot=newnode;
    }
    else{
      mRoot = nullptr;
    }
}
Set::Set(Set&& other){
  if(other.mRoot!=nullptr){
       
      mRoot=other.mRoot;
      other.mRoot=nullptr;
    }
    else{
      mRoot=nullptr;
    }

}
  Set::~Set(){
    
      delete mRoot;
    
  }

size_t Set::clear(){
    size_t out=count();
    delete mRoot;
    mRoot = nullptr;
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
      Node* newnode=new Node();
      newnode->data=value;
      mRoot=newnode;
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
  if(mRoot==nullptr){
    cout<<"-"<<endl;
  }
  else {
    std::string out=mRoot->nodeprint();
    cout<<out<<endl;
  }
} 
size_t Set::remove(const std::string& value){
  if(mRoot==nullptr){
    return 0;
  }
  else{
    size_t old= mRoot->count;
    mRoot=helpremove(mRoot,value);
    if(mRoot==nullptr){
      return 1;
    }
    else{
    size_t change= old-(mRoot->count);
    return change;
    

  }
  return -1;
}
}
