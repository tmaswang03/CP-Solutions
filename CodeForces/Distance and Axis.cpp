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

int main()
{
    int t; cin>>t;
    while(t--){
        int a, k, res = 1e9; cin>>a>>k;
        // distance from o to b and a to b diff = k
        // if b > a; a = k
        // if b < a; a-2*b = k
        // a = k+2*b
        // a =
        int b = min((a-k)/2,a-1);
        res = min(res, abs(a-k));
        res = min(res, abs(k+2*b - a));
        cout<<res<<endl;
    }
    return 0;
}
