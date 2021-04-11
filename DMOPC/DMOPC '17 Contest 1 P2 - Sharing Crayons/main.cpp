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
const ll MM = 1e5+10;
using namespace std;
ll a[MM], psa[MM];
int main()
{
    ll N, M; scan(N); scan(M);
    ll res = 0;
    map<ll, ll>mp;
    for(int i = 1; i <= N; ++i){
        scan(psa[i]); psa[i]+=psa[i-1];
    }
    for(int i = 0; i < N; ++i){
        res+=mp[psa[i]%M]; ++mp[psa[i]%M];
    }
    printf("%lld\n", res);

    return 0;
}
