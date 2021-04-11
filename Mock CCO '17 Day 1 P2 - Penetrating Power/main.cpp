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
const ll MM = 2e5+10, inf = 0x3f3f3f3f;
using namespace std;
// credit to https://cp-algorithms.com/
ll seg[4*MM], lazy[4*MM];
void push(int cur){
    seg[cur*2] += lazy[cur];
    lazy[cur*2] += lazy[cur];
    seg[cur*2+1] += lazy[cur];
    lazy[cur*2+1] += lazy[cur];
    lazy[cur] = 0;
}

void upd(int cur, int lo, int hi , int l, int r, int val){
    if (l > r)  return;
    if(l == lo && r == hi){
        seg[cur]+=val;
        lazy[cur]+=val;
        return;
    }
    push(cur);
    int mid = (lo + hi) / 2;
    upd(cur*2, lo, mid, l, min(r,mid), val);
    upd(cur*2+1, mid+1, hi, max(l, mid+1), r, val);
    seg[cur] = max(seg[cur*2],seg[cur*2+1]) ;
}

ll que(int cur, int lo, int hi, int l, int r) {
    if (l > r) return -inf;
    if (l == lo && r == hi) return seg[cur];
    push(cur);
    int mid = (lo + hi) / 2;
    return max(que(cur*2, lo, mid, l, min(r, mid)), que(cur*2+1, mid+1, hi, max(l, mid+1), r));
}

int main()
{
    int N, K, Q; scan(N); scan(K); scan(Q); ms(seg, 0); ms(lazy, 0);
    for(int i = 0; i < Q; ++i){
        int opt, pos,q; scan(opt); scan(pos); scan(q);
        if(!opt) upd(1, 0, N-1, max(pos-K+1,0), pos, q);
        else printf("%lld\n",que(1, 0, N-1, pos, min(N-1, q)));
    }
    return 0;
}
