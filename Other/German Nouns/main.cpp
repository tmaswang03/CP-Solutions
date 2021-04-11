#include <iostream>
#include <vector>
#include <cctype>
#include <string.h>
#include <string>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
using namespace std;

int main()
{
    vector <string> stringstr;
    int l;cin>>l;
    stringstr.resize(l+1);
    int j =1;
    string testing = "qwertyuiopasdfghjklzxcvbnm";
    for(int i = 0 ; i < l+1;i++){
    string a;
    getline(cin,a);
    stringstr[i]=a;
    }
     for(int i = 1; i < l+1; i++){
        for(int k = 0; k < stringstr[i].length();k++){
            if((isupper(stringstr[i][k])==0)){
              while(testing.find(stringstr[i][k+j])!=string::npos){
                j++;
              }

              string substr1=stringstr[i].substr(k,k+j);
              cout<<substr1<<endl;
              j=1;
            }
        }

    }

    return 0;
}
