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
        for(size_t i=0; i<other.count();i++){
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
        
    Heap::Entry Heap::pop(){
        if (mCount==0){
            throw std::underflow_error("underflow_error");
        }
        Heap::Entry out=mData[0];
        mData[0]=mData[mCount];
        mCount--;
        size_t i=0;
        while((mData[i].score<mData[i * 2 + 1].score||mData[i].score<mData[i * 2 + 2].score)&&i<mCount){
            if(mData[i * 2 + 1].score>mData[i * 2 + 2].score){
                std::swap(mData[i],mData[i * 2 + 2]);
                i=i * 2 + 2;
            }
            else{
                std::swap(mData[i],mData[i * 2 +1]);
                i=i * 2 + 1;
            }

        }

        return out;
    }
    Heap::Entry        Heap::pushpop(const std::string& value, float score){
        if (mCount==0){
            throw std::underflow_error("underflow_error");
        }
        Heap::Entry out=mData[0];
        mData[0]={value,score};
        size_t i=0;
        while((mData[i].score<mData[i * 2 + 1].score||mData[i].score<mData[i * 2 + 2].score)&&i<mCount){
            if(mData[i * 2 + 1].score>mData[i * 2 + 2].score){
                std::swap(mData[i],mData[i * 2 + 2]);
                i=i * 2 + 2;
            }
            else{
                std::swap(mData[i],mData[i * 2 +1]);
                i=i * 2 + 1;
            }

        }

        return out;

    }
    void         Heap::push(const std::string& value, float score){
        if(mCount==mCapacity){
             throw std::overflow_error("overflow_error");
        }
        mData[mCount]=Heap::Entry{value,score};
        mCount++;
        size_t i=mCount-1;
        while(i!=0&&mData[(i - 1) / 2].score>mData[i].score){
            swap(mData[(i - 1) / 2],mData[i]);
            i=(i - 1) / 2;
        } 
    }
    const Heap::Entry& Heap::top() const{
        if (mCount==0){
            throw std::underflow_error("underflow_error");
        }
        return mData[0];
    }