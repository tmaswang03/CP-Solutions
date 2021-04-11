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
const ll MM = 1e5+20, MN = 1e5+10;
using namespace std;
ll bit1[MM], bit2[MM],  a[MM], N, M;
ll query (ll cur,ll bit[]) {
    ll ret = 0;
    for (cur++;cur>0;cur-=(cur&-cur)) ret += bit[cur];
    return ret;
}
ll range(ll l, ll r,ll bit[]){
    ll ret = query(r, bit)-query(l-1, bit);
    return ret;
}
void update (ll cur, ll v,ll bit[]){
    for (cur++;cur<=MN;cur+=(cur&-cur)) bit[cur] += v;
}


int main()
{
    scan(N); scan(M);
    for(int i = 1; i <= N; ++i){
        scan(a[i]); update(i, a[i], bit1);
        update(a[i], 1, bit2);
    }
    for(int i = 0; i < M; ++i){
        char opt;
        scanf("%s", &opt);
        if(opt == 'Q'){
            ll v; scan(v);
            printf("%lld\n", query(v, bit2));
        }
        else if(opt == 'S'){
            ll l, r; scan(l); scan(r);
            printf("%lld\n", range(l, r, bit1));
        }
        else{
            ll x, v; scan(x); scan(v);
            update(x, v-a[x], bit1);
            update(a[x], -1, bit2);
            update(v, 1, bit2);
            a[x] = v;
        }
    }
    return 0;
}
