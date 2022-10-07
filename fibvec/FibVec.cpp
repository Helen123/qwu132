#include "FibVec.h"
#include <stdexcept>
#include <iostream>

using namespace std;

size_t f(size_t n){
  if(n==1){
    return 1;
  }
  else if(n==2){
    return 1;
  }
  else{
    size_t i =f(n-1)+f(n-2);
    return i;
  }
};
size_t nextFeb(size_t feb){
  size_t n =1;
  if(feb==1){
    return 2;
  }
  while (feb!=f(n)){
    n++;
  }
  return f(n+1);

};

size_t lastFeb(size_t feb){
  size_t n =1;
  if(feb==1){
    return 1;
  }
  while (feb!=f(n)){
    n++;
  }
  return f(n-1);
}

FibVec::FibVec(){
    mCount=0;
    mCapacity=1;
};

FibVec::~FibVec(){
    delete [] data;
};

size_t FibVec::capacity() const{
 return mCapacity;
};

size_t FibVec::count() const{
  return mCount;
};

void FibVec::insert(int value, size_t index){
 if (index>mCount){
    throw std::out_of_range("out of range");
 }
 else{
    if(mCount==mCapacity){
        mCapacity=nextFeb(mCapacity);
        mCount++;
        int* temp= new int[mCapacity];
        for (size_t i=0; i<index;i++){
          *(temp+i)= *(data+i);
        }
        *(temp+index)= value;
        for(size_t i = index+1; i<mCount;i++){
          *(temp+i)= *(data+i-1);
        }
        delete [] data;
        data=temp;
      }
    else{
      mCount++;
      for(size_t i = (mCount-1); i>index;i--){
          *(data+i)= *(data+i-1);
        }
      *(data+index)= value;
    }
 }
};
int FibVec::lookup(size_t index) const{
  if (index>mCount){
    throw std::out_of_range("out of range");
 }
  int i =*(data+index);
  return i;
};
int FibVec::pop(){
  if(mCount==0){
    throw underflow_error("underflow");
  }
  else{
    int i =remove(mCount-1);
    return i;
  }
}
void FibVec::push(int lastValue){
    insert(lastValue, mCount);
}
FibVec FibVec::slice(size_t index, size_t count) const{
  FibVec small;
  for(size_t i=0; i<count;i++){
    small.push(*(data+index+i));
  }
  return small;

}
int FibVec::remove(size_t index){
  if(index>mCount-1){
    throw std::out_of_range("out of range");
   }
  else{
    int re= *(data+index);
    if((mCount-1)==lastFeb(lastFeb(mCapacity))){
        mCapacity=lastFeb(mCapacity);
        mCount--;
        int* temp= new int[mCapacity];
        for (size_t i=0; i<index;i++){
          *(temp+i)= *(data+i);
        }
        for(size_t i = index; i<mCount;i++){
          *(temp+i)= *(data+i+1);
        }
        delete [] data;
        data=temp;
    }
    else{
       mCount--;
       for(size_t i =index; i<mCount;i++){
        *(data+index)=*(data+index+1);
       }
      }
  return re;
  }

}




