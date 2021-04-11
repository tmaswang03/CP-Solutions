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
const ll MM = 1e5+10, inf = 0x3f3f3f3f;
using namespace std;
// credit to https://cp-algorithms.com/

struct segm {
    ll s, pr, su, res;
};
ll a[MM];
segm seg[4*MM];

segm share(segm l, segm r) {
    segm ret;
    // can either be entirely in left half, right half or cross of both
    ret.s = l.s + r.s;
    ret.pr = max(l.pr, l.s + r.pr);
    ret.su = max(r.su, r.s + l.su);
    ret.res = max(max(l.res, r.res), l.su + r.pr);
    return ret;
}

segm ret(ll val) {
    return {val, val, val, val};
}

void build(int cur, int lo, int hi) {
    if (lo == hi) {
        seg[cur] = ret(a[lo]);
        return;
    }
    int mid = (lo + hi) >> 1;
    build(cur<<1, lo, mid);
    build(cur<<1|1, mid+1, hi);
    seg[cur] = share(seg[cur<<1], seg[cur<<1|1]);
}

void upd(int cur, int lo, int hi, int pos, ll val) {
    if (lo == hi) {
        seg[cur] = ret(val);
        return;
    }
    int mid = (lo + hi) >> 1;
    if (pos <= mid) upd(cur<<1, lo, mid, pos, val);
    else upd(cur<<1|1, mid+1, hi, pos, val);
    seg[cur] = share(seg[cur<<1], seg[cur<<1|1]);
}

segm q(int cur, int lo, int hi, int l, int r) {
    if (l > r) return segm{-inf,-inf,-inf,-inf};
    if (l == lo && r == hi) return seg[cur];
    int mid = (lo + hi) >> 1;
    return share(q(cur<<1, lo, mid, l, min(r, mid)), q(cur<<1|1, mid+1, hi, max(l, mid+1), r));
}

int main()
{
    int N, Q; cin>>N>>Q;
    for(int i = 1; i <= N; ++i){
        cin>>a[i];
    }
    build(1, 1, N);
    for(int i = 0; i < Q; ++i){
        char opt; ll l, r; cin>>opt>>l>>r;
        if(opt=='S') upd(1, 1, N, l, r);
        else cout<<q(1, 1, N, l, r).res<<endl;
    }
    return 0;
}
