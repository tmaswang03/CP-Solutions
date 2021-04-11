#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int N, K, words =0;
string out;
int main()
{
    cin>>N>>K;
    for(int i = 0; i < N; ++i){
        string s; cin>>s;
        if(out.empty()){ out+=s; words = 1;}
        else if(out.length()+s.length()-words+1>K){
            cout<<out<<"\n";
            out.clear();
            out+=s;
            words = 1;
        }
        else{
            out+=" "+s;
            ++words;
        }
    }
    if(!out.empty()) cout<<out<<"\n";
    return 0;
}
