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
const ll MM = 1e5+10, inf = 1e9+10;
using namespace std;
typedef pair<ll, ll> pll;
struct seg{ll mi, gcd, cnt = 0;}t[MM<<2];
char opt; int l, r, N, M, a[MM];
// if the gcd is equal on both sides and gcd == mi;
// count number with same gcd;
void build (int v, int l, int r){
    if(l>r) return;
    if(l==r){ t[v].mi = t[v].gcd = a[l]; t[v].cnt = 1; return;}
    int mid = l+r>>1;
    build(v<<1, l, mid);
    build(v<<1|1, mid+1, r);
    t[v].mi = min(t[v<<1].mi, t[v<<1|1].mi);
    t[v].gcd = __gcd(t[v<<1].gcd, t[v<<1|1].gcd);
    if(t[v].gcd == t[v<<1].gcd && t[v].gcd==t[v].mi) t[v].cnt+=t[v<<1].cnt;
    if(t[v].gcd == t[v<<1|1].gcd && t[v].gcd==t[v].mi) t[v].cnt+=t[v<<1|1].cnt;
}

void upd(int v, int l, int r, int p, int val){
    if(l==r && r==p){ t[v].mi = t[v].gcd = val; t[v].cnt = 1; return;}
    int mid = l+r>>1;
    if(p <= mid) upd(v<<1, l, mid, p, val);
    else upd(v<<1|1, mid+1, r, p, val);
    t[v].cnt = 0;
    t[v].mi = min(t[v<<1].mi, t[v<<1|1].mi);
    t[v].gcd = __gcd(t[v<<1].gcd, t[v<<1|1].gcd);
    if(t[v].gcd == t[v<<1].gcd && t[v].gcd==t[v].mi) t[v].cnt+=t[v<<1].cnt;
    if(t[v].gcd == t[v<<1|1].gcd && t[v].gcd==t[v].mi) t[v].cnt+=t[v<<1|1].cnt;
}

pll qgcd(int v, int l, int r, int lo, int hi){
    if(lo>hi) return {0,0};
    if(lo <= l && r <= hi) return {t[v].gcd, t[v].cnt};
    int mid = l + r >> 1;
    pll lgcd = qgcd(v<<1, l, mid, lo, min(mid, hi)), rgcd = qgcd(v<<1|1, mid+1, r, max(mid+1, lo), hi);
    if(lgcd.f && rgcd.f){
        int res = __gcd(lgcd.f, rgcd.f), gcnt = 0;
        if(res == lgcd.f) gcnt+=lgcd.s;
        if(res == rgcd.f) gcnt+=rgcd.s;
        return {res, gcnt};
    }
    else if (lgcd.f) return lgcd;
    else return rgcd;
}

ll qmi(int v, int l, int r, int lo, int hi){
    if(lo>hi) return inf;
    if(lo <= l && r <= hi) return t[v].mi;
    int mid = l + r >> 1;
    return min(qmi(v<<1, l, mid, lo, min(hi, mid)), qmi(v<<1|1, mid+1, r, max(lo, mid+1), hi));
}

int main()
{
    cin>>N>>M;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    build(1, 1, N);
    while(M--){
        cin>>opt>>l>>r;
        if(opt == 'C') upd(1, 1, N, l, r);
        else if (opt=='M') cout<<qmi(1, 1, N, l, r)<<endl;
        else if (opt == 'G') cout<<qgcd(1, 1, N, l, r).f<<endl;
        else cout<<qgcd(1, 1, N, l, r).s<<endl;
    }
    return 0;
}
