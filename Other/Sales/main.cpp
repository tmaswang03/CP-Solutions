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
const ll MM = 3e4+1;
using namespace std;
int p[MM], va[MM], B, N, D, l, r, a, b, t[1<<16][51];
void build(int v, int l, int r){
    if(l==r){
        for(int i = 1; i <= B; ++i){
            if(p[l]<=i) t[v][i] = va[l];
        }
        return;
    }
    int mid = l+r>>1;
    build(v<<1, l, mid); build(v<<1|1, mid+1, r);
    for(int i = 1; i <= B; ++i){
        for(int j = 0; j <= i; ++j){
            t[v][i] = max(t[v][i], t[v<<1][j]+t[v<<1|1][i-j]);
        }
    }
}
void upd(int v, int l, int r, int idx, int pr){
    if(idx<l || idx > r) return;
    if(l==r && r==idx){
        for(int i = 1; i <=B; ++i){
            if(pr<=i) t[v][i] = va[l];
            else t[v][i] = 0;
        }
        return;
    }
    int mid = l+r>>1;
    if(idx<=mid) upd(v<<1, l, mid, idx, pr);
    else upd(v<<1|1, mid+1, r, idx, pr);
    for(int i = 1; i <= B; ++i){
        t[v][i] = 0;
        for(int j = 0; j <= i; ++j){
            t[v][i] = max(t[v][i], t[v<<1][j]+t[v<<1|1][i-j]);
        }
    }
}
int query(int lvl, int v, int l, int r, int lo, int hi){
    if(lo>r||hi<l) return 0;
    if(lo<=l && r <= hi){
        return t[v][lvl];
    }
    int mid = l+r>>1;
    int res = 0;
    for(int i = 0; i <= lvl; ++i){
        res = max(res, query(i, v<<1, l, mid, lo, min(hi, mid))+query(lvl-i, v<<1|1, mid+1, r, max(lo, mid+1), hi));
    }
    return res;
}
int main()
{
    scana(B, N, D);
    for(int i = 1; i <= N; ++i) scana(p[i], va[i]);
    build(1, 1, N);
    for(int i = 0; i < D; ++i){
        scana(a, b, l, r);
        upd(1, 1, N, a, b);
        printf("%d\n",query(B, 1, 1, N, l, r));
    }
    return 0;
}
