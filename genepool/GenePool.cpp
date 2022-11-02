#include "GenePool.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// GenePool Member Functions
  GenePool::GenePool(std::istream& stream){
    count=0;
    std::string line;
    while (std::getline(stream, line )){
      if(line[0]!='#'&&line.length()!=0){
        stringstream ss(line);
        count++;
        std::string token;
        Person* p=new Person("???",Gender::ANY);
        size_t c=0;
        while(std::getline(ss, token,'\t' )){
          c++;
          if(c==1){
            p->name1=token;
            pool[token]=p;
          }
          else if(c==2){
            if(token=="male"){
              p->gender1=Gender::MALE;
              }
            else{
              p->gender1=Gender::FEMALE;
            }
          }
          else if(c==3){
            if(token!="???"){
              Person* m=find(token);
              p->mother1=m;
              m->children1.insert(m->children1.end(),m);
              
            }
          }
          else{
            if(token!="???"){
              Person* f=find(token);
              p->father1=f;
              f->children1.insert(f->children1.end(),f);
            }
          }
        }

  
        
      
    }
  }}


  GenePool::~GenePool(){
    pool.erase(pool.begin(),pool.end());
  }

  Person* GenePool::find(const std::string& name) const{
    auto it = pool.find(name);  
     
    if ( it == pool.end() ) {   
     return nullptr; 
    }   
    else { 
        return it->second;
    } 

  }