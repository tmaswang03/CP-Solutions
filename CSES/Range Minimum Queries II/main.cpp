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
const ll MM = 2e5+10, inf = 1e9+10;
using namespace std;
ll n, q, t[4*MM], a[MM], opt, x, y;
void build(int v, int l, int r){
    if(l==r){ t[v] = a[l]; return; }
    int mid = l+r>>1;
    build(v<<1|1, mid+1, r); build(v<<1, l, mid);
    t[v] = min(t[v<<1], t[v<<1|1]);
}

void upd(int v, int l, int r, int p, int val){
    if(l==r && r == p){t[v] = val; return;}
    int mid = l+r>>1;
    if(mid >= p) upd(v<<1, l, mid, p, val);
    else upd(v<<1|1, mid+1, r, p, val);
    t[v] = min(t[v<<1], t[v<<1|1]);
}

ll query(int v, int l, int r, int lo, int hi){
    if(lo <= l && r <= hi) return t[v];
    if(l > hi || r < lo) return inf;
    int mid = l+r>>1;
    return min(query(v<<1, l, mid, lo, min(mid, hi) ), query(v<<1|1, mid+1, r, max(lo, mid+1), hi));
}

int main()
{
    cin>>n>>q;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    build(1, 1, n);
    while(q--){
        cin>>opt>>x>>y;
        if(opt==1) upd(1, 1, n, x, y);
        else cout<<query(1, 1, n, x, y)<<endl;
    }
    return 0;
}
