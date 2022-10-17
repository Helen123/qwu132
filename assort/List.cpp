#include "List.h"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;


List::List(){
    head= NULL;
}

List::List(const List& other){
  if(other.head==NULL){
    head=NULL;
  }
  else{
    head=new Node{other.head->data, NULL};
    Node* tocopy=other.head->next;
    Node* curr=head;
    while(tocopy!=NULL){
      curr->next = new Node{tocopy->data, NULL};
      tocopy=tocopy->next;
      curr=curr->next;
    }
  }
    
}
  List::List(List&& other){
    head=other.head;
    other.head=NULL;
  }

  List::~List(){
    Node* curr=head;
    while(curr!=NULL){
      Node* temp =curr;
      curr=curr->next;
      delete temp;
    }
  }

 size_t List::count()const{
    if(head==NULL){
      return 0;
    }
  size_t n=0;
  Node* curr=head;
  while(curr!=NULL){
    n++;
    curr=curr->next;
  }
return n;

 }
  void List::insert(const std::string& value){
    if(head==NULL){
      head=new Node{value,NULL};
    }
    else{
      Node* curr=head;
      Node* insertnode= new Node{value,NULL};
      if(value<head->data){
        insertnode->next=head;
        head=insertnode;
      }
      else{
        while(true){
          if(curr->next==NULL||value<curr->next->data){
            insertnode->next=curr->next;
            curr->next=insertnode;
            break;
          }
          curr=curr->next;
        }
      }

    }
  }  
    string ot="";
const std::string& List::lookup(size_t index) const{
  if(head==NULL){
    throw std::out_of_range("out of range");
  }
  ot =head->data;
  Node* curr=head;
  for(size_t i= 0; i<index;i++){
    if(curr->next==NULL){
      throw std::out_of_range("out of range");
    }
    curr=curr->next;
    }
  ot=curr->data;
  return ot;
}
void List::print(bool reverse) const{
  if(head==NULL){
    cout<<"[]"<<endl;
  }
  else{if(reverse==0){
    cout<<"[";
    Node* curr=head;
    Node* nextnode=head->next;
    while(curr!=NULL){
      cout<<curr->data;
      if(nextnode==NULL){
        cout<<"]"<<endl;
        break;
      }
      else{
        cout<<", ";
      }
      curr=curr->next;
      nextnode=nextnode->next;
    }
  }
  else{
    string out="[";
    Node* curr=head;
    Node* nextnode=head->next;
    while(curr!=NULL){
      out.insert(1,curr->data);
      if(nextnode==NULL){
        out+="]";
        break;
      }
      else{
        out.insert(1,", ");
      }
      curr=curr->next;
      nextnode=nextnode->next;
    }
    cout<<out<<endl;
    
  }
  }
}
std::string List::remove(size_t index){
string out ="";
size_t n = count();
    if (index >= n){
        throw out_of_range("Out of Range");
    }
    Node* curr = head;
    if (n == 1){
        Node* temp = head;
        out= temp -> data;
        delete head;
        head = NULL;
    }
    else if (index == 0){
        out= curr -> data;
        head = curr -> next;
        delete curr;
        curr = NULL;
    }
    else if (index == n - 1){
        for (size_t i = 0; i < n - 2; i++){
            curr = curr -> next;
        }
        Node* temp = curr -> next;
        out= temp -> data;
        delete curr -> next;
        curr -> next = NULL;
    }
    else{
        for (size_t j = 0; j < index - 1; j++){
            curr = curr -> next;
        }
        Node* temp = curr -> next;
        out= temp -> data;
        curr -> next = temp -> next;
        delete temp;
        temp = NULL;
    }
    return out;
}
size_t List::remove(const std::string& value){
    size_t n = 0;
    Node* curr = head;
    while (curr != NULL){
      size_t num = count();
      curr = head;
        for (size_t i = 0; i < num; i++){
            if (curr -> data == value){
                remove(i);
                n ++;
                break;
            }
            curr = curr -> next;
        }
    }
    return n;
}