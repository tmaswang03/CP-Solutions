#include<bits/stdc++.h>
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

int main()
{
    boost();
    int t; cin>>t;
    while(t--){
        int w; cin>>w;
        string s, res = ""; cin>>s;
        for(int i = 0; i < w; ++i){
            res+=s[i+i];
        }
        cout<<res<<endl;
    }
    return 0;
}
