#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace std;
struct mwv{
    ll t, fi;
};
mwv a[MM]; ll endt[110];
bool comp(mwv b, mwv c){
    return b.t < c.t;
}
int main()
{
    ll N,M,T, res = -1; scan(N); scan(M); scan(T);
    for(int i = 0; i < M; ++i){
        scan(a[i].t); scan(a[i].fi);
    }
    sort(a, a+M, comp); ms(endt, 0);
    for(int i = 0; i < M; ++i){
        pair<ll, ll> br = {0, 0x3f3f3f3f};
        for(int j = 0; j < N; ++j){
            if(endt[j]<a[i].t && a[i].t-endt[j]<br.s){
                br.s = a[i].t - endt[j];
                br.f = j;
            }
        }
        if(a[i].t-endt[0]>=T){
            printf("%lld\n", endt[0]);
            return 0;
        }
        endt[br.f] = max(endt[br.f], a[i].t) + a[i].fi;
        sort(endt, endt+N);
    }
    res = LLONG_MAX;
    for(int j = 0; j < N; ++j){
        res = min(res, endt[j]);
    }
    printf("%lld\n", res);
/*
3 5 20
0 3
1 3
2 3
8 2
9 1
*/
    return 0;
}
