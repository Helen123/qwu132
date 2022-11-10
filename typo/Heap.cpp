#include "Heap.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


    Heap::Heap(size_t capacity){
        // new Heap::Entry[capacity];
        mData=new Heap::Entry[capacity];
        mCapacity=capacity;
        mCount=0;

    }
    Heap::Heap(const Heap& other){
        mData=new Heap::Entry[other.capacity()];
        mCapacity=other.capacity();
        for(size_t i=0; i<other.mCount;i++){
            mData[i]=other.mData[i];
            mCount++;
        }
        
    }

    Heap::Heap(Heap&& other){
        mData=other.mData;
        mCapacity=other.mCapacity;
        mCount=other.mCount;
        other.mData=nullptr;
        other.mCount=0;
        other.mCapacity=0;
    }
    Heap::~Heap(){
        delete [] mData;

    }

    size_t       Heap::capacity() const{
        return mCapacity;
    }
    size_t       Heap::count() const{
        return mCount;
    }
    const Heap::Entry& Heap::lookup(size_t index) const{
        if (index>=mCount){
            throw std::out_of_range("out of range");
        }
    return mData[index];
    }
        
    Heap::Entry        Heap::pop(){
        return mData[1];
    }
    Heap::Entry        Heap::pushpop(const std::string& value, float score){
         return mData[1];
    }
    void         Heap::push(const std::string& value, float score){
        
    }
    const Heap::Entry& Heap::top() const{
         return mData[1];
    }