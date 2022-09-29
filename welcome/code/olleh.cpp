#include <iostream>

using namespace std;
int main(){
    string in="";
    getline(cin, in);
    string out="";
    int count =0;
    string tem="";
    for(long unsigned int i = 0; i<in.length(); i++){
        if (!(isspace(in[i])||ispunct(in[i]))){
            count++;
            tem+=in[i];
    
        }
        else{
            for(int j=count-1;j>=0;j--){
                out+=tem[j];
            }
            tem="";
            count=0;
            out+=in[i];
        }
    }
    for(int i=count-1;i>=0;i--){
        out+=tem[i];
    }
        cout<<out<<endl;
        return 0;

    }