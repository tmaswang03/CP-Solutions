#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    for(int i = 0; i < 5; ++i){
        string str, tempstr=""; getline(cin, str);
        for(int it = 0; it < str.length(); ++it){
            if(str[it]=='"'){
                ++it;
                while(str[it]!='"'){
                    tempstr+=str[it];
                    ++it;
                }
                tempstr+=' ';
            }
            else if(str[it]=='*' && str[it-1]=='/'){
                ++it;
                while(str[it]!='*' || str[it+1]!='/'){
                    tempstr+=str[it];
                    ++it;
                }
                tempstr+=' ';
            }
            else if(str[it]=='/' && str[it-1]=='/'){
                ++it;
                while(it<str.length()){
                    tempstr+=str[it];
                    ++it;
                }
                tempstr+=' ';
            }
            else if(str[it]=='\''){
                ++it;
                while(str[it]!='\''){
                    tempstr+=str[it];
                    ++it;
                }
                tempstr+=' ';
            }
        }
        if(tempstr[tempstr.length()-1]==' ') tempstr.pop_back();
        cout<<tempstr<<endl;
    }
    return 0;
}
