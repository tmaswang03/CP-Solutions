#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
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
const ll MM = 1e5+10;
ll a[MM], t[4*MM], N, M, opt, l, r; bool done[4*MM];
using namespace std;
void build(int v, int l, int r){
    if(l==r){
        t[v] = a[l];
        if(t[v]<=1) done[v] = 1;
        return;
    }
    int mid = l+r>>1;
    build(v<<1, l, mid); build(v<<1|1, mid+1, r);
    t[v] = t[v<<1]+t[v<<1|1];
    if(done[v<<1] && done[v<<1|1]) done[v] = 1;
}
void upd(int v, int l, int r, int lo, int hi){
    if(done[v]) return;
    if(l==r && lo <= l && l <= hi){
        t[v] = sqrt(t[v]);
        if(t[v]<=1) done[v] = 1;
        return;
    }
    if(l>hi || r<lo || r<l) return;
    int mid = l+r>>1;
    upd(v<<1, l, mid, lo, min(mid, hi)); upd(v<<1|1, mid+1, r, max(mid+1, lo), hi);
    t[v] = t[v<<1|1] + t[v<<1];
    if(done[v<<1]&&done[v<<1|1]) done[v] = 1;
}

ll query(int v, int l, int r, int lo, int hi){
    if(lo<=l && r<=hi) return t[v];
    if(l>hi || r<lo || r<l) return 0;
    int mid = l+r>>1;
    return query(v<<1, l, mid, lo, min(hi, mid)) + query(v<<1|1, mid+1, r, max(lo, mid+1), hi);
}
int main()
{
    scan(N);
    for(int i = 1; i <= N; ++i) scan(a[i]);
    build(1, 1, N);
    scan(M);
    while(M--){
        scana(opt, l, r);
        if(opt==1){
            printf("%lld\n", query(1, 1, N, l, r));
        }
        else upd(1, 1, N, l, r);
    }
    return 0;
}
