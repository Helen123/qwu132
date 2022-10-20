#include "Node.h"
#include <stdexcept>
#include <string>
using namespace std;

Node::Node(){
    data="";
    count=1;
    left=nullptr;
    right=nullptr;
}

    Node::Node(const Node& other){
        if(other.left==nullptr&&other.right==nullptr){
             data =other.data;
             count=1;
        }
        else if(other.left!=nullptr&&other.right==nullptr){
                this->left=new Node(*other.left);
                data =other.data;
                count=left->count+1;
        }
        else if(other.right!=nullptr&&other.left==nullptr){
                this->right=new Node(*other.right);
                data =other.data;
                count=right->count+1;
        }
        else{
            this->left=new Node(*other.left);
            this->right=new Node(*other.right);
            data =other.data;
            this->count=left->count+right->count+1;
        }
    }


    Node::~Node(){
              delete left;
              delete right;
        
      
    }
    bool Node::nodecontains(const std::string& value){
        if(value==data){
            return 1;
        }
        else if(value>data){
            if(right==nullptr){
                return 0;
            }
            else{
                return right->nodecontains(value);
            }
        }
        else {
            if(left==nullptr){
                return 0;
            }
            else{
                return left->nodecontains(value);
            }
        }
    }
    size_t Node:: nodeinsert(const std::string& value){
        if(data==value){
            return 0;
        }
        else if(value>data){
            if(right==nullptr){
                right->data=value;
                count++;
                return 1;
            }
            else{
            return right->nodeinsert(value);
            }
        }
        else {
            if(left==nullptr){
                left->data=value;
                count++;
                return 1;
            }
            else{
            return left->nodeinsert(value);
            }
        }

    }
    const std::string& Node::nodelookup(size_t n) const{
        if(left==nullptr){
            if(n==0){
                return data;
            }
            else{
                if(right==nullptr){
                    throw std::out_of_range("out of range");
                }
                else{
                    return right->nodelookup(n-1);
                }
            }
        }
        if(left->count==n){
            return data;
        }
        else if(left->count<n){
            if(right==nullptr){
                throw std::out_of_range("out of range");
            }
            else{
                return right->nodelookup(n-left->count-1);
            }
        }
        else {
            return left->nodelookup(n);
        }

    }
    std::string Node::nodeprint(){
        std::string out=data;
        if(left==nullptr&&right==nullptr){
            return out;
        }
        else{
            if(left==nullptr){
                out.insert(0,"-");
            }
            else{
                out.insert(0,left->nodeprint());
            }
            if(right==nullptr){
             out.insert(out.length(),"-");
            }
            else{
                 out.insert(out.length(),right->nodeprint());
            }
        }
        out.insert(0,"(");
        out.insert(out.length(),")");
        return out;



    }
    size_t Node::noderemove(const std::string& value){
        if(data==value){
            if(left==nullptr&&right==nullptr){
                delete this;
            }
            else if(left==nullptr){
                data=right->data;
                count=right->count;
                Node* temp=right;
                left=right->left;
                right=right->right;
                delete temp;
            }
            else if(right==nullptr){
             
                data=left->data;
                count=left->count;
                Node* temp=left;
                left=left->left;
                right=left->right;
                delete temp;
            }
            else{
                data=left->data;
                Node* prev=left;
                Node* curr=left->right;
                while(curr!=nullptr){
                    data=curr->data;
                    prev=prev->right;
                    curr=curr->right;
                }
                delete curr;
                prev->right=nullptr;

            }

        }
        else if(value>data){
            if(right==nullptr){
                return 0;
            }
            else{
                return right->noderemove(value);
            }
        }    
        else{
            if(left==nullptr){
                return 0;
            }
            else{
                return left->noderemove(value);
            }
        }
        return 0;
    }


    //Node* // Node pointer
    //*ptr  // derefernce ptr

    //Node& // Node reference
    //&node // get a pointer to node