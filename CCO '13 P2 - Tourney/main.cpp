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
const ll MM = (1<<20)+10;
using namespace std;
struct seg{
    ll val, idx;
}t[MM<<2];
ll N, M, a[MM], x, y, cnt[MM]; char opt;
void build(int v, int l, int r){
    if(l==r){t[v] = {a[r], r}; return;}
    int mid = l+r>>1;
    build(v<<1, l, mid); build(v<<1|1, mid+1, r);
    if(t[v<<1].val>t[v<<1|1].val){t[v] = t[v<<1];}
    else t[v] = t[v<<1|1];
    ++cnt[t[v].idx];
}
void upd(int v, int l, int r, int p, ll val){
    if(l==r && r==p){t[v] = {val, p}; return;}
    int mid = l+r>>1;
    if(p<=mid) upd(v<<1, l, mid, p, val);
    else upd(v<<1|1, mid+1, r, p, val);
    --cnt[t[v].idx];
    if(t[v<<1].val>t[v<<1|1].val) t[v] = t[v<<1];
    else t[v] = t[v<<1|1];
    ++cnt[t[v].idx];
}
int main()
{
    boost();
    cin>>N>>M; N = 1<<N;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    build(1, 1, N);
    while(M--){
        cin>>opt;
        if(opt == 'R'){cin>>x>>y; upd(1, 1, N, x, y);}
        else if(opt == 'W'){cout<<t[1].idx<<endl;}
        else{cin>>x; cout<<cnt[x]<<endl;}
    }
    return 0;
}
