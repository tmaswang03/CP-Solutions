#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace std;
ll a[MM], psa[MM], I, N, J, res;
int main()
{
    scan(I); scan(N); scan(J);
    while(J--){
        ll l, r, k; scan(l); scan(r); scan(k);
        psa[l]+=k; psa[r+1]-=k;
    }
    for(int i = 1; i <= I; ++i){
        a[i] = a[i-1]+psa[i];
        if(a[i]<N) ++res;
    }
    printf("%lld\n", res);
    return 0;
}
