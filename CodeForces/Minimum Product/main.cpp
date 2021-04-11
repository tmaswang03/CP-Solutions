#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        ll a,b,x,y,n, res = 1e18+1; cin>>a>>b>>x>>y>>n;
        res = min(res, max(x, a-n)*max(y, (b-(n - (a-max(x, a-n))) )));
        res = min(res, max(y, b-n)*max(x, (a-(n - (b-max(y, b-n))) ))) ;
        res = min(b*max((a-n), x), res);
        res = min(a*max((b-n), y), res);
        cout<<res<<endl;
    }
    return 0;
}
