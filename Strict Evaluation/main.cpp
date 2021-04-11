#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10, inf = 1e15;
using namespace std;
ll seg[4*MM], lazy[4*MM], N, Q, a[MM];
bool typ[4*MM];
// idea, if you are adding set node to 0 else 1
// if adding onto a set, turn add into 1
// if setting onto add, reset add to 0,
void resolve (ll v){
    if(!typ[v]){
        seg[(v<<1)|1]+=lazy[v];
        seg[v<<1]+=lazy[v];
        lazy[(v<<1)|1]+=lazy[v];
        lazy[v<<1]+=lazy[v];
        lazy[v] = 0;
    }
    else{
        seg[(v<<1)|1]=lazy[v];
        seg[v<<1]=lazy[v];
        lazy[(v<<1)|1]=lazy[v];
        lazy[v<<1]=lazy[v];
        lazy[v] = 0; typ[v] = 0;  typ[(v<<1)|1] = 1; typ[v<<1] = 1;
    }
}

void build(ll lo, ll hi, ll v){
    if(lo==hi){
        seg[v] = a[lo]; return;
    }
    ll mid = (lo+hi)>>1;
    build(lo, mid, v<<1);
    build(mid+1, hi, (v<<1)|1);
    seg[v] = min(seg[v<<1], seg[(v<<1)|1]);
}

void inc(ll lo, ll hi, ll l, ll r, ll v, ll val){
    if(l > r) return;
    if(lo==l && r==hi){
        seg[v]+=val; lazy[v]+= val; return;
    }
    resolve(v);
    ll mid = (lo+hi)>>1;
    inc(lo, mid, l, min(r, mid), v<<1, val);
    inc(mid+1 , hi, max(l, mid+1), r, (v<<1)|1, val);
    seg[v] = min(seg[v<<1], seg[(v<<1)|1]);
}

void newval(ll lo, ll hi, ll l, ll r, ll v, ll val){
    if(l > r) return;
    if(lo==l && r==hi){
        seg[v]=val; lazy[v]= val; typ[v] = 1; return;
    }
    resolve(v);
    ll mid = (lo+hi)>>1;
    newval(lo, mid, l, min(r, mid), v<<1, val);
    newval(mid+1 , hi, max(l, mid+1), r, (v<<1)|1, val);
    seg[v] = min(seg[v<<1], seg[(v<<1)|1]);
}

ll query(ll lo, ll hi, ll l, ll r, ll v){
    if(l > r) return inf;
    if(l <= lo && hi <= r) return seg[v];
    resolve(v);
    ll mid = (lo+hi)>>1;
    return min(query(lo, mid, l, min(r, mid), v<<1),  query(mid+1, hi, max(l, mid+1), r , (v<<1)|1));
}

int main()
{
    scan(N); scan(Q);
    for(ll i = 1; i <= N; ++i){
        scan(a[i]);
    }
    build(1, N, 1);
    while(Q--){
        ll opt, l, r, v; scan(opt);
        if(opt==1){
            scana(l, r, v);
            inc(1, N, l, r, 1, v);
        }
        else if(opt == 2){
            scana(l,r,v);
            newval(1, N, l, r, 1, v);
        }
        else{
            scana(l,r);
            printf("%lld\n", query(1, N, l, r, 1));
        }
    }
    return 0;
}
