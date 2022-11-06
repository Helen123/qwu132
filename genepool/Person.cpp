#include "Person.h"
#include <algorithm>
#include <iostream>

// Person Member Functions
  Person::Person(const std::string n, Gender g){
    name1=n;
    gender1=g;
    father1=nullptr;
    mother1=nullptr;
  }
  Person::~Person(){
    return;}
  const std::string& Person::name()   const{
    return name1;
  }
  Gender             Person::gender() const{
    return gender1;
  }
  Person*            Person::mother(){
    return mother1;
  }
  Person*            Person::father(){
    return father1;
  }

  std::set<Person*> Person::ancestors(PMod pmod){
    return children1;

  }
  std::set<Person*> Person::aunts(PMod pmod, SMod smod ){
    return children1;
  }
  std::set<Person*> Person::brothers(PMod pmod, SMod smod ){
     return children1;
  }
  std::set<Person*> Person::children(){
    return children1;
  }
  std::set<Person*> Person::cousins(PMod pmod, SMod smod ){
    return children1;
  }
  std::set<Person*> Person::daughters(){
    std::set<Person*> dau;
    for(auto itr=children1.begin();itr!=children1.end();++itr){
      if((*itr)->gender1==Gender::FEMALE){
        dau.insert(dau.end(),(*itr));
      }
    }
    return dau;
  }
  std::set<Person*> Person::descendants(){
    return children1;
  }
  std::set<Person*> Person::grandchildren(){
    std::set<Person*> dau;
    for(auto itr=children1.begin();itr!=children1.end();++itr){
      dau.merge((*itr)->children1);
    }
    return dau;
  }
  std::set<Person*> Person::granddaughters(){
    std::set<Person*> dau;
    auto gchildren = grandchildren();
    for(auto itr=gchildren.begin();itr!=gchildren.end();++itr){
      if((*itr)->gender()==Gender::FEMALE){
        dau.insert(dau.end(),(*itr));
      }
  }
  return dau;
  
  }
  std::set<Person*> Person::grandfathers(PMod pmod){
    return children1;
  }
  std::set<Person*> Person::grandmothers(PMod pmod){
    return children1;
  }
  std::set<Person*> Person::grandparents(PMod pmod){
    if(pmod==PMod::MATERNAL&&mother1!=nullptr){
      return mother1->parents();
    }
    else{
      std::set<Person*> dau;
      return dau;
    }
    if(pmod==PMod::PATERNAL&&father1!=nullptr){
      return father1->parents();
    }
    else{
      std::set<Person*> dau;
      return dau;
    }
    std::set<Person*> dau;
    if(father1!=nullptr){
      dau.merge((father1->parents()));
    }
    if(mother1!=nullptr){
      dau.merge((mother1->parents()));
    }
    return dau;

  }
  std::set<Person*> Person::grandsons(){
    return children1;

  }
  std::set<Person*> Person::nephews(PMod pmod, SMod smod ){
    return children1;
  }
  std::set<Person*> Person::nieces(PMod pmod, SMod smod ){
    return children1;
  }
  std::set<Person*> Person::parents(PMod pmod){
    if(pmod==PMod::MATERNAL){
      std::set<Person*> dau;
      if(mother1!=nullptr){
        dau.insert(dau.end(),(mother1));
      }
      return dau;
    }
    if(pmod==PMod::PATERNAL){
      std::set<Person*> dau;
      if(father1!=nullptr){
        dau.insert(dau.end(),(father1));
      }
      return dau;
    }
  

    std::set<Person*> dau;
    if(father1!=nullptr){
      dau.insert(dau.end(),(father1));
    }
    if(mother1!=nullptr){
      dau.insert(dau.end(),(mother1));
    }
    return dau;

  }
  std::set<Person*> Person::siblings(PMod pmod, SMod smod ){
    return children1;
    std::set<Person*> dau;
    if(pmod==PMod::MATERNAL&&smod==SMod::ANY){
      if(mother1!=nullptr){
        for(auto itr=mother1->children1.begin();itr!=mother1->children1.end();++itr){
          if((*itr)->name1!=name1){
            dau.insert(dau.end(),(*itr));
          }
        }
      }
      return dau;
    }
    else if(pmod==PMod::PATERNAL&&smod==SMod::ANY){
      if(father1!=nullptr){
        for(auto itr=father1->children1.begin();itr!=father1->children1.end();++itr){
          if((*itr)->name1!=name1){
            dau.insert(dau.end(),(*itr));
          }
        }
      }
      return dau;
    }
    // else{
    //   return children1;
    // }

    // else{
    //    auto msibling = siblings(PMod::MATERNAL,SMod::FULL);
    //    for(auto itr=msibling.begin();itr!=msibling.end();++itr){
    //       if((){
    //         dau.insert(dau.end(),(*itr));
    //       }


  
  }
    
    // else{
    //   std::set<Person*> dau1;
    //   dau.merge((siblings(PMod::MATERNAL,SMod::ANY)));

    //   std::set_intersection (dau.begin(), dau.end(), siblings(PMod::PATERNAL,SMod::ANY).begin(),siblings(PMod::PATERNAL,SMod::HALF).end(), dau1.begin());
    //   return dau1;

    // }
          
    
      
  std::set<Person*> Person::sisters(PMod pmod, SMod smod ){
    return children1;
  }
  std::set<Person*> Person::sons(){
    std::set<Person*> dau;
    for(auto itr=children1.begin();itr!=children1.end();++itr){
      if((*itr)->gender1==Gender::MALE){
        dau.insert(dau.end(),(*itr));
      }
    }
    return dau;
  }
  std::set<Person*> Person::uncles(PMod pmod, SMod smod ){
    return children1;
  }

    
