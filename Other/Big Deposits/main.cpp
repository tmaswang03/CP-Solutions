#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
ll P,Y,T;
ll calc(ll n){
    ll cur = 0;
    ld p = (1.0*P+100.0)/100;
    for(int i = 0; i < Y; ++i){
        cur+=n;
        cur*=p;
        if(cur >= T) return cur;
    }
    return cur;
}
int main()
{
    scan(P); scan(Y); scan(T);
    ll lo = 0, hi = T, mid, ret =  0;
    while(hi >= lo){
        mid = (lo+hi)>>1;
        if(calc(mid)>=T){
            hi = mid-1;
            ret = mid;
        }
        else lo = mid+1;
    }

    printf("%lld\n", ret);
    return 0;
}
