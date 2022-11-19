#include "Helpers.h"

float getdv(Star& s, size_t d){
    if(d==1){
        return s.x;
    }
    if(d==2){
        return s.y;
    }
    if(d==3){
        return s.z;
    }
}
size_t next(size_t d){
    if(d==1||d==2){
        return d+1;
    }
    else return 1;
}
// void swap(Heap::entry );


    // Node::Node(Star& newstar){
    //     data=newstar;
    //     left=nullptr;
    //     right=nullptr;
    //     depth=1;
    // }
    // Node::~Node(){
    //     delete data;
    //     delete left;
    //     delete right;
    // }

    // Node* Node::nodeinsert(Star& newstar,size_t d){
    //     if(getdv(newstar,d)>=getvd(data,d)&&left==nullptr){
    //         Node n=new Node(newstar);
    //         n.depth=next(d);
    //         left=n;
    //         return this;
    //     }
    //     else if(getdv(newstar,d)<getvd(data,d)&&right==nullptr){
    //         Node n=new Node(newstar);
    //         n.depth=next(d);
    //         right=n;
    //         return this;
    //     }
    //     else if(getdv(newstar,d)<getvd(data,d)){
    //         return right->nodeinsert(newstar,next(d));
    //     }
    //     else if(getdv(newstar,d)>=getvd(data,d)){
    //         return left->nodeinsert(newstar,next(d));
    //     }
        
    // }
// float Point::getpv(size_t d){
//     if(d==1){
//         return x;
//     }
//     else if(d==2){
//         return y;
//     }
//     else if(d==3){
//         return z;
//     }
//     else{
//         throw std::underflow_error("wrong dimension");
//     }
// }
// Node* Node::findnearest(Point target, size_t depth, size_t n){
//     vector<Star> out;
//     Heap closeset=Heap(n);
//     Node* next,other;
//     if(target.getpv(depth)<getdv(data,depth)&&left==nullptr){
//         Node* temp=new temp()
//     }
//     if(target.getpv(depth)>=getdv(data,depth)&&right==nullptr){
//         return nullptr;
//     }
//     if(target.getpv(depth)<getdv(data,depth)){
//         next=left;
//         other=right;
//     }
    
//     else{
//         next=right;
//         other=left;
//     }
//     auto temp=next->findnearest(target,depth+1,)

    

// }

Heap::Heap(size_t capacity){
    mData=new Heap::Entry[capacity];
    mCapacity=capacity;
    mCount=0;
}
Heap::~Heap(){
    delete []mData->value;
    delete [] mData;
}
size_t       Heap::capacity() const{
    return mCapacity;
}
size_t       Heap::count() const{
    return mCount;
}
Entry       Heap::get(size_t i){
    return mData[i];
}
void   Heap::eSwap(size_t a, size_t b){
    auto temp=mData[a].value;
    mData[a].value=mData[b].value;
    mData[b].value=temp;
    temp=nullptr;
    swap(mData[a].dist,mData[b].dist);

}
void  Heap::pushpop(Star& s, float d){
    if (mCount==0){
            throw std::underflow_error("underflow_error");
        }
        mData[0].value=s;
        mData[0].dist=d;
        size_t i=0;
        size_t left=i * 2 + 1;
        size_t right=i * 2 + 2;
        while(left<mCount){
            if(right==mCount){
                if(mData[left].dist>mData[i].dist){
                     eSwap(left, i);
                    i=i * 2 + 1;
                    left=i * 2 + 1;
                    right=i * 2 + 2;
                }
                else{
                    break;
                }

            }
            else if (right<mCount){
                if(mData[left].dist>=mData[right].dist&&mData[left].dist>mData[i].dist){
                    eSwap(left, i);
                    i=i * 2 + 1;
                    left=i * 2 + 1;
                    right=i * 2 + 2;

                }
                else if(mData[left].dist<mData[right].dist&&mData[right].dist>mData[i].dist){
                     eSwap(right, i);
                 i=i * 2 + 2;
                 left=i * 2 + 1;
                 right=i * 2 + 2;
                }
                else{
                    break;
                }

            }
        }

}
void         Heap::push(Star& s, float d){
    if(mCount==mCapacity){
             throw std::overflow_error("overflow_error");
        }
        mData[mCount]=Heap::Entry{s,d};
        mCount++;
        size_t i=mCount-1;
        while(i!=0&&mData[(i - 1) / 2].dist<mData[i].dist){
            eSwap((i - 1) / 2,i);
            i=(i - 1) / 2;
        } 
}
void  Heap::closest(Star& s, float d){
    if(mCount==mCapacity&&d<mData[0].dist){
        pushpop(s,d);
    }
    if(mCount<mCapacity){
        push(s,d);
    }
    else{
        throw std::overflow_error("overflow_error");
    }
}

// Space to implement helper class member functions.
