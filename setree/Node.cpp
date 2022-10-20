#include "Node.h"
#include <stdexcept>

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
       if(left!=nullptr&&right!=nullptr){
              delete left;
              delete right;
        }
        else{
        
    
        delete this;
        
        
        } 
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
        else if(value<data){
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
            if(n=0){
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

    //Node* // Node pointer
    //*ptr  // derefernce ptr

    //Node& // Node reference
    //&node // get a pointer to node