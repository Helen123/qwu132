#include "StarMap.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
using std::istringstream;
using std::string;

StarMap* StarMap::create(std::istream& stream) {
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.
  return new StarMap(stream);
}

StarMap::StarMap(std::istream& stream){
  std::string line;
  int id=0;
  while (std::getline(stream, line)){
    std::string token;
    Star* s=new Star();
    id++;
    float x;
    float y;
    float z;
    size_t count=0;
    std::stringstream ss(line);
    while(std::getline(ss, token,'\t' )){
      if(count==0){
        x=stof(token);
        count++;
      }
      else if(count==1){
        y=stof(token);
        count++;
      }
      else if (count==2){
        z=stof(token);
        count++;
      }
    }
    s->id=id;
    s->x=x;
    s->y=y;
    s->z=z;
    stars.insert(*s);
    // if(id==1){
    //   root=new Node(*s);
    // }
    // else{
    //   root->nodeinsert(*s,1);
    // }
  }
}
StarMap::~StarMap(){
  stars.~set();
}
float distance(float x, float y, float z, Star& s){
  float d = sqrt(pow(x-s.x, 2) +
                pow(y -s.y, 2) +
                pow(z - s.z, 2) * 1.0);
  return d;
}
std::vector<Star> StarMap::find(size_t n, float x, float y, float z){
  Heap out=Heap(n);
for(auto i: stars){
  out.closest(i,distance(x,y,z,i));
}
std::vector<Star>result;
for(size_t i=0;i<out.count();i++){
  result.insert(result.end(),*(out.get(i).value));
}
return result;


}