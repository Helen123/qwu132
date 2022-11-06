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
   if(parents().empty()==true){
    std::set<Person*> empty;
    return empty;
   }
   else{
    std::set<Person*> dau;
    dau.merge(parents());
    for(auto itr=parents.begin();itr!=parents.end();++itr){
      auto desc=(*itr)->ancestors();
        dau.merge(desc);
    }
    return dau;
   }
  }

  std::set<Person*> Person::aunts(PMod pmod, SMod smod ){
    std::set<Person*> dau;
    auto parent=parents(pmod);
    for(auto itr=parent.begin();itr!=parent.end();++itr){
      dau.merge((*itr)->sisters(PMod::ANY,smod));

    }
    return dau;
  }
  std::set<Person*> Person::brothers(PMod pmod, SMod smod ){
    std::set<Person*> dau;
     auto sib=siblings(pmod,smod);
     for(auto itr=sib.begin();itr!=sib.end();++itr){
      if((*itr)->gender1==Gender::MALE){
        dau.insert(dau.end(),(*itr));
      }
    }
    return dau;
  }
  std::set<Person*> Person::children(){
    return children1;
  }
  std::set<Person*> Person::cousins(PMod pmod, SMod smod ){
    std::set<Person*> dau;
    auto parent=parents(pmod);
    for(auto itr=parent.begin();itr!=parent.end();++itr){
      auto sib=(*itr)->siblings(PMod::ANY,smod);
      for(auto itr1=sib.begin();itr1!=sib.end();++itr1){
        dau.merge((*itr1)->children1);
      }

    }
    return dau;
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
   if(children1.empty()==true){
    std::set<Person*> empty;
    return empty;
   }
   else{
    std::set<Person*> dau;
    dau.merge(children1);
    for(auto itr=children1.begin();itr!=children1.end();++itr){
      auto desc=(*itr)->descendants();
        dau.merge(desc);
    }
    return dau;
   }
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
    std::set<Person*> dau;
     auto sib=grandparents(pmod);
     for(auto itr=sib.begin();itr!=sib.end();++itr){
      if((*itr)->gender1==Gender::MALE){
        dau.insert(dau.end(),(*itr));
      }
    }
    return dau;
  }
  std::set<Person*> Person::grandmothers(PMod pmod){
      std::set<Person*> dau;
     auto sib=grandparents(pmod);
     for(auto itr=sib.begin();itr!=sib.end();++itr){
      if((*itr)->gender1==Gender::FEMALE){
        dau.insert(dau.end(),(*itr));
      }
    }
    return dau;
  }
  std::set<Person*> Person::grandparents(PMod pmod){
    if(pmod==PMod::MATERNAL&&mother1!=nullptr){
      return mother1->parents();
    }
    else if(pmod==PMod::MATERNAL&&mother1==nullptr){
      std::set<Person*> dau;
      return dau;
    }
    if(pmod==PMod::PATERNAL&&father1!=nullptr){
      return father1->parents();
    }
    else if(pmod==PMod::PATERNAL&&father1==nullptr){
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
    std::set<Person*> dau;
    auto gchildren = grandchildren();
    for(auto itr=gchildren.begin();itr!=gchildren.end();++itr){
      if((*itr)->gender()==Gender::MALE){
        dau.insert(dau.end(),(*itr));
      }
  }
  return dau;

  }
  std::set<Person*> Person::nephews(PMod pmod, SMod smod ){
    std::set<Person*> dau;
    auto sib=siblings(pmod,smod);
    for(auto itr=sib.begin();itr!=sib.end();++itr){
      dau.merge((*itr)->sons());
    }
    return dau;
  }
  std::set<Person*> Person::nieces(PMod pmod, SMod smod ){
    std::set<Person*> dau;
    auto sib=siblings(pmod,smod);
    for(auto itr=sib.begin();itr!=sib.end();++itr){
      dau.merge((*itr)->daughters());
    }
    return dau;
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
    if(pmod==PMod::MATERNAL){
      if(smod==SMod::HALF){
        std::set<Person*> dau;
        auto mochildren=siblings(PMod::MATERNAL);
        auto mfullchildren=siblings(PMod::MATERNAL,SMod::FULL);
        for(auto itr=mochildren.begin();itr!=mochildren.end();++itr){
          bool have=0;
          for(auto itr1=mfullchildren.begin();itr1!=mfullchildren.end();++itr1){
            if((*itr)->name1==(*itr1)->name1){
              have=1;
              break;
            }
          }
          if(have==0){
            dau.insert(dau.end(),(*itr));
          }
        }
        return dau;

      }
      else if(smod==SMod::FULL){
        std::set<Person*> dau;
        auto mochildren=siblings(PMod::MATERNAL);
        auto fachildren=siblings(PMod::PATERNAL);
        for(auto itr=fachildren.begin();itr!=fachildren.end();++itr){
          for(auto itr1=mochildren.begin();itr1!=mochildren.end();++itr1){
            if((*itr)->name1==(*itr1)->name1){
              dau.insert(dau.end(),(*itr));
              break;
            }
          }
        }
        return dau;
      }
      else{
        if(mother1==nullptr){
          std::set<Person*> dau;
          return dau;
        }
        else{
          auto chi=mother1->children1;
          for(auto itr=chi.begin();itr!=chi.end();++itr){
            if((*itr)->name1==name1){
              chi.erase(itr);
              break;
            }
          }
            
          return chi;
        }
      }
        

    }
    else if(pmod==PMod::PATERNAL){
      if(smod==SMod::HALF){
        std::set<Person*> dau;
        auto mochildren=siblings(PMod::PATERNAL);
        auto mfullchildren=siblings(PMod::PATERNAL,SMod::FULL);
        for(auto itr=mochildren.begin();itr!=mochildren.end();++itr){
          bool have=0;
          for(auto itr1=mfullchildren.begin();itr1!=mfullchildren.end();++itr1){
            if((*itr)->name1==(*itr1)->name1){
              have=1;
              break;
            }
          }
          if(have==0){
            dau.insert(dau.end(),(*itr));
          }
        }
        return dau;

        }

      
      else if(smod==SMod::FULL){
        std::set<Person*> dau;
        auto mochildren=siblings(PMod::MATERNAL);
        auto fachildren=siblings(PMod::PATERNAL);
        for(auto itr=fachildren.begin();itr!=fachildren.end();++itr){
          for(auto itr1=mochildren.begin();itr1!=mochildren.end();++itr1){
            if((*itr)->name1==(*itr1)->name1){
              dau.insert(dau.end(),(*itr));
              break;
            }
          }
        }
        return dau;

      }
      else{
         if(father1==nullptr){
          std::set<Person*> dau;
          return dau;
        }
        else{
          auto chi=father1->children1;
          for(auto itr=chi.begin();itr!=chi.end();++itr){
            if((*itr)->name1==name1){
              chi.erase(itr);
              break;
            }
          }
            
          return chi;
        }
      }

    }
    else{
      if(smod==SMod::HALF){
        auto mochildren=siblings(PMod::MATERNAL,SMod::HALF);
        auto fachildren=siblings(PMod::PATERNAL,SMod::HALF);
        mochildren.merge(fachildren);
        return mochildren;

      }
      else if(smod==SMod::FULL){
        return siblings(PMod::PATERNAL,SMod::FULL);
      }
      else{
        auto mochildren=siblings(PMod::MATERNAL);
        auto fachildren=siblings(PMod::PATERNAL);
        mochildren.merge(fachildren);
        return mochildren;
      }

    }
    return children1;
  }
    
          
    
      
  std::set<Person*> Person::sisters(PMod pmod, SMod smod ){
    std::set<Person*> dau;
     auto sib=siblings(pmod,smod);
     for(auto itr=sib.begin();itr!=sib.end();++itr){
      if((*itr)->gender1==Gender::FEMALE){
        dau.insert(dau.end(),(*itr));
      }
    }
    return dau;
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
    std::set<Person*> dau;
    auto parent=parents(pmod);
    for(auto itr=parent.begin();itr!=parent.end();++itr){
      dau.merge((*itr)->brothers(PMod::ANY,smod));

    }
    return dau;
  }

    
