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
const ll MM = 5e5+10, MN = 5e4+10;
using namespace std;
int a[MN], b[MM], sat[MN], M, N;
struct node{
    int l, r, val, idx;
}t[4*MN];
void build(int v, int l, int r){
    if(l==r){
        t[v].l = l, t[v].r = r, t[v].idx = l; return;
    }
    int mid = l+r>>1;
    build(v<<1, l, mid);
    build(v<<1|1, mid+1, r);
}
void upd(int v, int l, int r, int x){
    if(l==r && r==x){ ++t[v].val; ++sat[t[v].idx]; return;}
    int mid = l+r>>1;
    if(x>mid) upd(v<<1|1, mid+1, r, x);
    else upd(v<<1, l, mid, x);
    t[v].val = min(t[v<<1].val, t[v<<1|1].val);
    if(t[v<<1].val<=t[v<<1|1].val){
        t[v].idx = t[v<<1].idx;
    }
    else if(t[v<<1|1].val < t[v<<1].val){
        t[v].idx = t[v<<1|1].idx;
    }
}
int query(int v, int l, int r, int lo, int hi){
    if(l>hi||r<lo) return N;
    if(lo<=l && r <= hi) return t[v].idx;
    int mid = l+r>>1;
    int lft = query(v<<1, l, mid, lo, min(hi, mid));
    int rt = query(v<<1|1, mid+1, r, max(mid+1, lo), hi);
    if(sat[lft]<=sat[rt]) return lft;
    return rt;
}
int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin>>N>>M; sat[N] = 0x3f3f3f3f;
    for(int i = 0; i < N; ++i) cin>>a[i];
    sort(a, a+N);
    build(1, 0, N-1);
    for(int i = 0; i < M; ++i){
        cin>>b[i];
        int lft = upper_bound(a, a+N, b[i])- a;
        int idx = query(1, 0, N-1, lft, N-1);
        upd(1, 0, N-1, idx);
    }
    // if all have the same # of worms eaten, give it to the one with the smallest that is greater than cur
    // else give it to the one that is least out of all that is greater
    return 0;
}
