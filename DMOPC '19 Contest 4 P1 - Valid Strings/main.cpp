#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
using namespace std;

int main()
{
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
        string s; cin>>s;
        stack<char>st;
        bool good = 1;
        int bracketcounter = 0, bracketcounter2 = 0;
        for(int j = 0; j < s.length(); ++j){
            if(s[j]=='('){
                ++bracketcounter;
               }
            else if(s[j]==')'){
                ++bracketcounter2;
            }
            if(bracketcounter2>bracketcounter){
                good = 0;
            }
        }
            if(bracketcounter2==bracketcounter && good){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }

    }
    return 0;
}
