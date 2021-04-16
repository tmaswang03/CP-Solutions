#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{
    string a;
    string b;
    string c;
    cin>>a;
    cin>>b;
    c = b;
    string substr1;
    for(int k = 0 ; k < c.length(); k++){
    for(int i = 0 ; i < c.length(); i++){
        if(i+k<c.length()){
           b[i]=c[i+k];
    }
        else if(i==c.length()-1){
            b[i]=c[k-1];
        }
        else{
            b[i]=c[-(b.length()-k-i)];
        }
    }
    }






    return 0;
}
