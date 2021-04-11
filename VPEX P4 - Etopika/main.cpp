#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
const ll MM = 1e5+10, LOG = 20, MD = 1e6+10;
using namespace std;
ll N, D, a, b, d, lca[LOG][MM], par[MM], dpth[MM], dst[MM], dp[2], c1 = 1, c2 = 1; vector<pii> v[MM];
int lg2(int n) { return 31 - __builtin_clz(n);}
void dfs(int cur, int lvl, ll d){
    dpth[cur] = lvl; dst[cur] = d;
    for(auto && i : v[cur]){
        if(i.f==par[cur]) continue;
        par[i.f] = cur;
        dfs(i.f, lvl+1, d+i.s);
    }
}

void init(){
    for(int i = 1; i <= N; ++i) lca[0][i] = par[i];
    for(int l = 1; l < LOG; ++l){
        for(int i =1 ; i <= N; ++i) lca[l][i] = lca[l-1][lca[l-1][i]];
    }
}

int gett(int a, int b){
    if(dpth[a]<dpth[b]) swap(a, b);
    while(dpth[a]!=dpth[b]) a = lca[lg2(dpth[a]-dpth[b])][a];
    if(a==b) return a;
    for(int i = LOG-1; i >= 0; --i){
        if(lca[i][a] && lca[i][b] && lca[i][a]!=lca[i][b]) a = lca[i][a], b = lca[i][b];
    }
    return lca[0][a];
}

ll query(int a, int b){ return dst[a] + dst[b] - 2*dst[gett(a, b)]; }

int main()
{
    scana(N, D); ms(dp, 0); ms(lca, 0);
    for(int i = 0; i < N-1; ++i){
        scana(a, b, d); v[a].pb({b, d}); v[b].pb({a, d});
    }
    dfs(1, 0, 0);
    init();
    for(int i = 0; i < D; ++i){
        scana(a, b); ll cnst = query(a, b);
        ll t1 = dp[0], t2 = dp[1];
        dp[0] = min(t1+query(c1, b)+cnst, t2+query(c2, b)+cnst);
        dp[1] = min(t1+query(c1, a)+cnst, t2+query(c2, a)+cnst);
        c1 = a; c2 = b;
    }
    printf("%lld\n", min(dp[0], dp[1]));
    return 0;
}
