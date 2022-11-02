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
    return children1;
  }
  std::set<Person*> Person::descendants(){
    return children1;
  }
  std::set<Person*> Person::grandchildren(){
    return children1;
  }
  std::set<Person*> Person::granddaughters(){
    return children1;
  }
  std::set<Person*> Person::grandfathers(PMod pmod){
    return children1;
  }
  std::set<Person*> Person::grandmothers(PMod pmod){
    return children1;
  }
  std::set<Person*> Person::grandparents(PMod pmod){
    return children1;
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
    return children1;
  }
  std::set<Person*> Person::siblings(PMod pmod, SMod smod ){
    return children1;
  }
  std::set<Person*> Person::sisters(PMod pmod, SMod smod ){
    return children1;
  }
  std::set<Person*> Person::sons(){
    return children1;
  }
  std::set<Person*> Person::uncles(PMod pmod, SMod smod ){
    return children1;
  }

    
