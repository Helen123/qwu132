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
             left=nullptr;
             right=nullptr;
        }
        else if(other.left!=nullptr&&other.right==nullptr){
                this->left=new Node(*other.left);
                right=nullptr;
                data =other.data;
                count=left->count+1;
        }
        else if(other.right!=nullptr&&other.left==nullptr){
                this->right=new Node(*other.right);
                left=nullptr;
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
                Node* newnode=new Node();
                newnode->data=value;
                right=newnode;
                count++;
                return 1;
            }
            else{
            size_t temp= right->nodeinsert(value);
            count+=temp;
            return temp;
    
            }
        }
        else {
            if(left==nullptr){
                Node* newnode=new Node();
                newnode->data=value;
                left=newnode;
                count++;
                return 1;
            }
            else{
            size_t temp= left->nodeinsert(value);
            count+=temp;
            return temp;
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
                out.insert(0,"- ");
            }
            else{
                std::string temp=left->nodeprint();
                temp+=" ";
                out.insert(0,temp);
            }
            if(right==nullptr){
             out.insert(out.length()," -");
            }
            else{
                std::string temp=" ";
                temp+=right->nodeprint();
                 out.insert(out.length(),temp);
            }
        }
        out.insert(0,"(");
        out.insert(out.length(),")");
        return out;



    }
    size_t Node::noderemove(const std::string& value){
        if(data==value){
            if(left==nullptr&&right==nullptr){
                count--;
                
                delete this;

            }
            else if(left==nullptr){
                data=right->data;
                count=right->count;
                Node* temp=right;
                left=right->left;
                right=right->right;
                count--;
                delete temp;
            }
            else if(right==nullptr){
             
                data=left->data;
                count=left->count;
                Node* temp=left;
                left=left->left;
                right=left->right;
                count--;
                delete temp;
            }
            else{
                data=left->data;
                Node* prevprev=this;
                Node* prev=left;
                Node* curr=left->right;
                int a=0;
                while(curr!=nullptr){
                    if(a<1){
                        data=curr->data;
                        prevprev=prevprev->left;
                        prev=prev->right;
                        curr=curr->right;
                        
                    }
                    else{
                        data=curr->data;
                        prevprev=prevprev->right;
                        prev=prev->right;
                        curr=curr->right;
                    }
                    a++;
                }
                count--;
                delete prev;
                prevprev->right=nullptr;
                

            }

        }
        else if(value>data){
            if(right==nullptr){
                return 0;
            }
            else{
                size_t temp=right->noderemove(value);
                count-=temp;
                return temp;
            }
        }    
        else{
            if(left==nullptr){
                return 0;
            }
            else{
                size_t temp=left->noderemove(value);
                count-=temp;
                return temp;
            }
        }
        return 0;
    }


    //Node* // Node pointer
    //*ptr  // derefernce ptr

    //Node& // Node reference
    //&node // get a pointer to node