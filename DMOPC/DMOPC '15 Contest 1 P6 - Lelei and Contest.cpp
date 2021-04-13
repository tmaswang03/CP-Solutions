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
const ll MM = 2e5+10;
using namespace std;
struct node{
    ll add, rg;
};
ll seg[4*MM], a[MM], N, Q, mod;
node lazy[4*MM];
// apply fermat's little theorem (orz fermat)
// a^p % p = a
// so adding a value to segment is equivalent to just adding it across whole segment
// power is useless
void push(int v){
    if(lazy[v].rg==1) return;
    ll ret = lazy[v].add;
    seg[v<<1]+=ret*lazy[v<<1].rg; seg[v<<1]%=mod;
    seg[v<<1|1]+=ret*lazy[v<<1|1].rg; seg[v<<1|1]%=mod;
    lazy[v<<1].add+=ret; lazy[v<<1].add%=mod;
    lazy[v<<1|1].add+=ret; lazy[v<<1|1].add%=mod;
    lazy[v].add = 0;
}

void build(int lo, int hi, int v){
    lazy[v].rg = hi-lo+1;
    if(lo==hi){
        seg[v] = a[lo]%mod; return;
    }
    int mid = (lo+hi)>>1;
    build(lo, mid, v<<1);
    build(mid+1, hi, v<<1|1);
    seg[v] = seg[v<<1|1]+seg[v<<1];
    seg[v]%=mod;
}

void upd(int lo, int hi, int l, int r, int v, int val){
    push(v);
    if(l > r) return;
    if (lo>=l && r >= hi){
        lazy[v].add+=val;
        seg[v]+=lazy[v].rg*val;
        seg[v]%=mod;
        return;
    }
    int mid = (lo+hi)>>1;
    upd(lo, mid, l, min(r, mid), v<<1, val);
    upd(mid+1, hi, max(l, mid+1), r, v<<1|1, val);
    seg[v] = seg[v<<1]+seg[v<<1|1]; seg[v]%=mod;
}

ll que(int lo, int hi, int l, int r, int v){
    push(v);
    if(l > r) return 0;
    if(lo >= l && r >= hi){
        return seg[v];
    }
    int mid = (lo+hi)>>1;
    return que(lo, mid, l, min(r, mid), v<<1) + que(mid+1, hi, max(l, mid+1), r, v<<1|1);
}

int main()
{
    scan(mod); scan(N); scan(Q);
    for(int i = 1; i <= N; ++i){
        scan(a[i]);
    }
    build(1, N, 1);
    while(Q--){
        int opt, l, r; scan(opt); scan(l); scan(r);
        if(opt==1){
            int v; scan(v);
            upd(1, N, l, r, 1, v);
        }
        else{
            printf("%lld\n", que(1, N, l, r, 1)%mod);
        }
    }
    return 0;
}
