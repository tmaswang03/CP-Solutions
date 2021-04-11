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
        string str; getline(cin, str);
        int lastword = 0, wordcounter = 0;
        for(int k = 0; k < str.length(); ++k){
            lastword=0;
            while(str[k]!=' ' &&str[k]!=char(39) && k<str.length()){
                if(isalpha(str[k]))lastword++;
                ++k;
            }
            if(lastword>3) ++wordcounter;
        }
        cout<<wordcounter<<endl;
    }
    return 0;
}
