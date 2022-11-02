#include "GenePool.h"
#include <fstream>
using namespace std;

// GenePool Member Functions
  GenePool::GenePool(std::istream& stream){
    //pool;
    count=0;

  }


  GenePool::~GenePool(){
    pool.erase(pool.begin(),pool.end());
  }


  Person* GenePool::find(const std::string& name) const{
    Person* p=new Person("a",Gender::MALE);
    return p;

  }