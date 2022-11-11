#include "Dictionary.h"
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>  
using namespace std;

Dictionary::Dictionary(std::istream& stream){
    std::string line;
    while (std::getline(stream, line )&&line[0]!='#'){
        mWords.push_back(line);
    }
}

float distance(Point& p, char c){
    return sqrt(pow(p.x - QWERTY[int(c)-97].x, 2) + pow(p.y - QWERTY[int(c)-97].y, 2) * 1.0);
}
Heap Dictionary::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    Heap h=Heap(maxcount);
    for(auto i:mWords){
        if(i.length()==points.size()){
            size_t count=0;
            float sum=0;
            for(auto j: points){
                float d=distance(j,i[count]);
                float s=1 / (10*pow(d,2) + 1);
                sum+=s;
                count++;
            }
            float thisscore=sum/float(count);
            if(thisscore>cutoff&&h.count()<maxcount){
                h.push(i,thisscore);
            }
            else if(thisscore>cutoff&&h.lookup(0).score<thisscore){
                h.pushpop(i,thisscore);
            }

        }
    }
    return h;
}