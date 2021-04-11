#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, j, N) for(int i = j; i < N; ++i)
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
const ll MM = 1e5+10, seed = 131, mod = 1e9+7;
using namespace std;
ll hsh[MM], rhsh[MM], dpth[MM], N, Q, a, b, w, m, par1, par2, lca[20][MM], p[MM], modi[MM]; vector<pii>v[MM];
int lg2(int x){return 31 - __builtin_clz(x);}
ll hmod(ll in){return (in%mod+mod)%mod;}
void dfs(int c, ll h, ll rh, int lvl){
    dpth[c] = lvl; hsh[c] = h; rhsh[c] = rh;
    for(auto && i : v[c]){
        if(i.f==lca[0][c]) continue;
        lca[0][i.f] = c;
        dfs(i.f, hmod(h*seed+i.s), hmod(rh+i.s*p[lvl]), lvl+1);
    }
}
int query(int a, int b){
    if(dpth[a]<dpth[b]) swap(a, b);
    while(dpth[a]^dpth[b]) a = lca[lg2(dpth[a]-dpth[b])][a];
    if(a==b) return a;
    for(int i = 19; i >= 0; --i){
        if(lca[i][a] && lca[i][b] && lca[i][a]!=lca[i][b]) a = lca[i][a], b = lca[i][b];
    }
    return lca[0][a];
}
ll gethsh(int a, int b){return hmod(hsh[b] - hsh[a]*p[(dpth[b]-dpth[a])]);}
ll getrhsh(int a, int b){return hmod((rhsh[b] - rhsh[a])*modi[dpth[a]]);}
ll path (int a, int p1, int b){return hmod(hmod(getrhsh(p1, a)*p[dpth[b]-dpth[p1]]) + gethsh(p1, b));}

int main()
{
    ll inv = 190839696;
    scana(N, Q); p[0] = 1; modi[0] = 1; modi[1] = inv;
    for(int i = 1; i < MM; ++i) p[i] = hmod(seed*p[i-1]);
    for(int i = 2; i < MM; ++i) modi[i] = hmod(modi[i-1]*inv);
    for(int i = 0; i < N-1; ++i){
        scana(a, b, w); v[a].pb({b, w}); v[b].pb({a, w});
    }
    dfs(1, 0, 0, 0);
    for(int i = 1; i < 20; ++i){
        for(int n = 1; n <= N; ++n){
            lca[i][n] = lca[i-1][lca[i-1][n]];
        }
    }
    while(Q--){
        scana(a, b, w, m);
        par1 = query(a, b), par2 = query(w, m);
        if(path(a, par1, b)==path(w, par2, m)) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
