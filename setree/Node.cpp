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
        if(left!=nullptr){
              delete left;}
              if(right!=nullptr){
              delete right;}
        
      
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
                newnode=nullptr;
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
                newnode=nullptr;
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
    // size_t Node::noderemove(const std::string& value){
    //     if(data==value){
    //         if(left==nullptr&&right==nullptr){
    //             count--;
                
    //             delete this;

    //         }
    //         else if(left==nullptr){
    //             data=right->data;
    //             count=right->count;
    //             Node* temp=right;
    //             left=right->left;
    //             right=right->right;
    //             count--;
    //             delete temp;
    //         }
    //         else if(right==nullptr){
             
    //             data=left->data;
    //             count=left->count;
    //             Node* temp=left;
    //             left=left->left;
    //             right=left->right;
    //             count--;
    //             delete temp;
    //         }
    //         else{
    //             data=left->data;
    //             Node* prevprev=this;
    //             Node* prev=left;
    //             Node* curr=left->right;
    //             int a=0;
    //             while(curr!=nullptr){
    //                 if(a<1){
    //                     data=curr->data;
    //                     prevprev=prevprev->left;
    //                     prev=prev->right;
    //                     curr=curr->right;
                        
    //                 }
    //                 else{
    //                     data=curr->data;
    //                     prevprev=prevprev->right;
    //                     prev=prev->right;
    //                     curr=curr->right;
    //                 }
    //                 a++;
    //             }
    //             count--;
    //             delete prev;
    //             prevprev->right=nullptr;
                

    //         }

    //     }
    //     else if(value>data){
    //         if(right==nullptr){
    //             return 0;
    //         }
    //         else{
    //             size_t temp=right->noderemove(value);
    //             count-=temp;
    //             return temp;
    //         }
    //     }    
    //     else{
    //         if(left==nullptr){
    //             return 0;
    //         }
    //         else{
    //             size_t temp=left->noderemove(value);
    //             count-=temp;
    //             return temp;
    //         }
    //     }
    //     return 0;
    // }
    Node* helpremove(Node*& m, const std::string& value){
        if(m->data==value){
            if(m->left==nullptr&&m->right==nullptr){
                delete m;

                
                m=nullptr;
                return m;

            }
            else if(m->left==nullptr){
                m->data=m->right->data;
                m->count=m->right->count;
                Node* temp=m->right;
                m->left=m->right->left;
                m->right=temp->right;
                temp->left=nullptr;
                temp->right=nullptr;
                temp=nullptr;
                return m;
            }
            else if(m->right==nullptr){
             
                m->data=m->left->data;
                m->count=m->left->count;
                Node* temp=m->left;
                m->left=m->left->left;
                m->right=temp->right;
                temp->left=nullptr;
                temp->right=nullptr;
                temp=nullptr;
                return m;
            }
            else{
                m->data=m->left->data;
                //Node* prevprev=m;
                Node* prev=m->left;
                Node* curr=m->left->right;
                int a=0;
                while(curr!=nullptr){
                    if(a<1){
                        m->data=curr->data;
                        prev->count--;
                        //prevprev=prevprev->left;
                        prev=prev->right;
                        curr=curr->right;
                        
                    }
                    else{
                        m->data=curr->data;
                        prev->count--;
                        //prevprev=prevprev->right;
                        prev=prev->right;
                        curr=curr->right;
                    }
                    a++;
                }
                m->count--;
                delete prev;
                prev=nullptr;
                return m;

            }

        }
        else if(value>m->data){
            if(m->right==nullptr){
                return m;
            }
            else{
                Node* temp=m->right;
                m->right=nullptr;
                m->right=helpremove(temp,value);
                  if(m->right!=nullptr&&m->left!=nullptr){
                m->count=m->right->count+m->left->count+1;}
                else if(m->right==nullptr&&m->left!=nullptr){
                    m->count=m->left->count+1;
                }
                else if(m->right!=nullptr&&m->left==nullptr){
                    m->count=m->right->count+1;
                }
                else{
                    m->count=1;
                }
                temp=nullptr;
                return m;
            }
        }    
        else{
            if(m->left==nullptr){
                return m;
            }
            else{
                Node* temp=m->left;
                m->left=nullptr;
                m->left=helpremove(temp,value);
                if(m->right!=nullptr&&m->left!=nullptr){
                m->count=m->right->count+m->left->count+1;}
                else if(m->right==nullptr&&m->left!=nullptr){
                    m->count=m->left->count+1;
                }
                else if(m->right!=nullptr&&m->left==nullptr){
                    m->count=m->right->count+1;
                }
                else{
                    m->count=1;
                }
                temp=nullptr;
                return m;
            }
        }
        return m;
    }


    //Node* // Node pointer
    //*ptr  // derefernce ptr

    //Node& // Node reference
    //&node // get a pointer to node