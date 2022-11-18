#include "StarMap.h"
#include <string>

StarMap* StarMap::create(std::istream& stream) {
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.
  return new StarMap(stream);
}

StarMap::StarMap(std::istream& stream){
  std::string line;
    while (std::getline(stream, line )){
      std::string token;
        Star* s=new Star;
        float x;
        float y;
        float z;
        size_t count=0;
        while(std::getline(line, token,'\t' )){
          if(count==0){
            x=stof(token);
            count++;
          }
          else if(count==1){
            y=
          }

        }
       
        if(t==0){
         mWords.push_back(line);   
        } 
        }
}
    ~StarMap();
