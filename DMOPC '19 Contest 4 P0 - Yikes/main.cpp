#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
using namespace std;

int main()
{
    string str1,str2; cin>>str1>>str2;
    int counter = 0;
    for(int i = 0; i < str1.length(); ++i){
        if(str1[i]!=str2[i]){
            ++counter;
        }
    }
    if(counter==1){
        cout<<"LARRY IS SAVED!"<<endl;
    }
    else{
        cout<<"LARRY IS DEAD!"<<endl;
    }
    return 0;
}
