#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e5+10;
using namespace std;
ll bit[MM], N, Q, que[MM], lft = 1, psa[MM];
pair<ll, ll> a[MM];
struct q{
    ll idx, l, r, k;
};
bool comp (q &a, q &b){
    return a.k < b.k;
}

q qs[MM];

void upd(int x, int val){
    for(; x <= MM; x+=x&-x) bit[x]+=val;
}
ll query(int x){
    ll res = 0;
    for(; x > 0; x-=x&-x) res+=bit[x];
    return res;
}

int main()
{
    ms(bit, 0);
    scan(N); scan(Q);
    for(int i = 1; i <= N; ++i){
        scan(a[i].f); a[i].s = i;
        psa[i] = psa[i-1]+a[i].f;
    }
    sort(a+1, a+N+1);
    for(int i = 0; i < Q; ++i){
        ll l, r, k; scan(l); scan(r); scan(k);
        qs[i] = {i,l,r,k};
    }
    sort(qs, qs+Q, comp);
    for(int i = 0; i < Q; ++i){
        while(qs[i].k > a[lft].f && lft <= N){
            upd(a[lft].s, a[lft].f); ++lft;
        }
        que[qs[i].idx] = psa[qs[i].r] - psa[qs[i].l-1] - 2*(query(qs[i].r) - query(qs[i].l-1));
    }
    for(int i = 0; i < Q; ++i){
        printf("%lld\n", que[i]);
    }
    return 0;
}
