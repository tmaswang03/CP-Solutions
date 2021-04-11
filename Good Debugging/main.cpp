#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e6+10;
using namespace std;
int N, M, L, l, r; bool lazy[4*MM];
struct{
    int l, r, val;
}t[4*MM];
// everytime you update a range the new value is then
// r-l+1 - cur where cur is the number of bugs in that range
// binary search for the value 1, N that equals
void pushdown(int v){
    if(!lazy[v]) return;
    lazy[v] = 0;
    t[v<<1].val = t[v<<1].r-t[v<<1].l+1-t[v<<1].val;
    lazy[v<<1]=!lazy[v<<1];
    t[v<<1|1].val = t[v<<1|1].r-t[v<<1|1].l+1-t[v<<1|1].val;
    lazy[v<<1|1]=!lazy[v<<1|1];
}
void build(int v, int l, int r){
    t[v].l = l; t[v].r = r; t[v].val = r-l+1;
    if(l==r) return ;
    int mid = l+r>>1;
    build(v<<1, l, mid); build(v<<1|1, mid+1, r);
}
void upd(int v, int l, int r, int lo, int hi){
    if(l>hi||r<lo) return;
    if(lo <= l && r <= hi){
        t[v].val = r-l+1-t[v].val; lazy[v] = !lazy[v]; return;
    }
    pushdown(v);
    int mid = l+r>>1;
    upd(v<<1, l, mid, lo, min(hi, mid)); upd(v<<1|1, mid+1, r, max(lo, mid+1), hi);
    t[v].val = t[v<<1].val + t[v<<1|1].val;
}
int query(int v, int l, int r, int lo, int hi){
    pushdown(v);
    if(l>hi || r<lo) return 0;
    if(lo <= l && r <= hi) return t[v].val;
    int mid = l+r>>1;
    return query(v<<1, l, mid, lo, min(mid, hi)) + query(v<<1|1, mid+1, r, max(lo, mid+1), hi);
}
int bsearch(){
    int lo = 0, hi = N, mid, ret = 0;
    if(query(1, 1, N, 1, N)<L) return N+1;
    while(lo < hi){
        mid = lo+hi>>1;
        if(query(1, 1, N, 1, mid)<L) lo = mid+1, ret = mid+1;
        else hi = mid;
    }
    return ret;
}
int main()
{
    scana(N, M, L);
    build(1, 1, N);
    while(M--){
        scana(l, r);
        upd(1, 1, N, l, r);
        int tmp = bsearch();
        if(tmp>N) printf("AC?\n");
        else printf("%d\n", tmp);
    }
    return 0;
}
