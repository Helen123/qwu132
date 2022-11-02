#include "Person.h"


// Person Member Functions
  Person::Person(const std::string n, Gender g){
    name1=n;
    gender1=g;
    father1=nullptr;
    mother1=nullptr;
  }
  Person::~Person(){
    delete father1;
    delete mother1;
    children1.clear();
}
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
  std::set<Person*> Person::children(){
    return children1;
  }


  std::set<Person*> Person::ancestors(PMod pmod = PMod::ANY){
    std::set<Person*> out;
    return out;


  }
  std::set<Person*> Person::aunts(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::brothers(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::children(){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::cousins(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::daughters(){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::descendants(){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::grandchildren(){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::granddaughters(){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::grandfathers(PMod pmod = PMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::grandmothers(PMod pmod = PMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::grandparents(PMod pmod = PMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::grandsons(){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::nephews(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::nieces(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::parents(PMod pmod = PMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::siblings(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::sisters(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::sons(){
    std::set<Person*> out;
    return out;
  }
  std::set<Person*> Person::uncles(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> out;
    return out;
  }

    
