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
                Node* temp =new Node(*other.left);
                left=temp;
                temp=nullptr;
                right=nullptr;
                data =other.data;
                count=left->count+1;
        }
        else if(other.right!=nullptr&&other.left==nullptr){
                Node* temp=new Node(*other.right);
                right=temp;
                temp=nullptr;
                left=nullptr;
                data =other.data;
                count=right->count+1;
        }
        else{
            Node* temp =new Node(*other.left);
            Node* tempt=new Node(*other.right);
            left=temp;
            temp=nullptr;
            right=tempt;
            tempt=nullptr;
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
                count++;
                newnode=nullptr;
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
    Node* lagestNode(Node* m){
        if(m==nullptr){
            return m;
        }
        else if(m->right==nullptr){
            return m;
        }
        else{
            return lagestNode(m->right);
        }
        

    }
    Node* helpremove(Node*& m, const std::string& value){
        if(m==nullptr){
            return m;
        }
        if(m->data==value){
            if(m->left==nullptr&&m->right==nullptr){
                delete m;

                
                m=nullptr;
                return m;

            }
            else if(m->left==nullptr){
                
                Node* temp=m->right;
                m->right=nullptr;
                delete m;
                m=nullptr;
                return temp;
            }
            else if(m->right==nullptr){
             
                Node* temp=m->left;
                m->left=nullptr;
                delete m;
                m=nullptr;
                return temp;
            }
            else{
                Node* temp=lagestNode(m->left);
                m->data=temp->data;
                m->left=helpremove(m->left,temp->data);
                if(m->left==nullptr){
                   m->count=m->right->count+1; 
                }
                else{
                m->count=m->left->count+m->right->count+1;}

                return m;
               

            }

        }
        else if(value>m->data){
            if(m->right==nullptr){
                return m;
            }
            else{
                m->right=helpremove(m->right,value);
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
                return m;
            }
        }    
        else{
            if(m->left==nullptr){
                return m;
            }
            else{
                m->left=helpremove(m->left,value);
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
                return m;
            }
        }
        return m;
    }


    //Node* // Node pointer
    //*ptr  // derefernce ptr

    //Node& // Node reference
    //&node // get a pointer to node