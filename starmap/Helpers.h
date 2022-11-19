#ifndef HELPERS_H
#define HELPERS_H

#include "Star.h"
#include <climits>
using namespace std;

// struct Point{
//     float x,y,z;
// public:
//     float getpv(size_t d);
// };  
// // A structure to represent node of kd tree
// struct Node{
//     Star* data; 
//     Node *left, *right;
//     size_t depth;
// public:
//     Node(Star& newstar);
//     ~Node();
//     Node* nodeinsert(Star& newstar, size_t d);
//     Node* findnearest(Point target, size_t depth);
// };




class Heap {
public:
    struct Entry {
        Star*       value;
        float       dist;
    };

private:
    Entry* mData;
    size_t mCapacity;
    size_t mCount;
    
public:
    Heap(size_t capacity);
    ~Heap();
    size_t       capacity() const;
    size_t       count() const;
    Entry       get(size_t i);
    void        eSwap(size_t a, size_t b);
    void        pushpop(Star& s, float d);
    void         push(Star& s, float d);
    void        closest(Star& s, float d);

};

  

// If you want to add any helper classes,
// here's some space to do it in.

#endif
