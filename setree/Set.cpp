#include "Set.h"
#include <stdexcept>

Set::Set(){
    mRoot=NULL;
}
Set::Set(const Set& other){
    if(other.mRoot==NULL){
        mRoot==NULL;
    }
    else{
      
      Node* newnode=new Node(*other.mRoot);
      mRoot=newnode;
    }
}
Set::Set(Set&& other){
  if(other.mRoot==NULL){
        mRoot==NULL;
    }
    else{
      
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
    if(mRoot==NULL){
      mRoot->data=value;
      mRoot->count++;
      return 1;
    }
    else{
      return mRoot->nodeinsert(value);
    }
  
  }
const std::string& Set::lookup(size_t n) const{
  return "";
}
void Set::print() const{

} 
size_t Set::remove(const std::string& value){
  return 1;
}