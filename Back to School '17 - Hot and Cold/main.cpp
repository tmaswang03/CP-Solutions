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
const ll MM = 1e5+10, LOG = 20;
using namespace std;
ll N, S, a, b,t, lca[LOG][MM], par[MM], dpth[MM] ; vector<int> v[MM];
ll calc(ll n){ return n*(n+1)/2;}
int lg2(int n) { return 31 - __builtin_clz(n);}
void dfs(int cur, int lvl){
    dpth[cur] = lvl;
    for(auto && i : v[cur]){
        if(i==par[cur]) continue;
        par[i] = cur;
        dfs(i, lvl+1);
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

ll query(int a, int b){ return dpth[a] + dpth[b] - 2*dpth[gett(a, b)]; }
// idea find the lca of a, b; find distance from a to lca = d1, b to lca = d2, target to lca  = x
// answer = (d1*(d1+1) )/2 + (d2*(d2+1) )/2 + x*gett(b, a)
int main()
{
    scan(N); scan(S);
    for(int i = 0; i < N-1; ++i){
        scana(a, b); v[a].pb(b); v[a].pb(b);
    }
    for(int i = 0; i < S; ++i){
        scana(a, b, t);
        ll lca = gett(a, b), x = query(t, lca), res = 0;
        res+=calc(gett(a, lca)) + calc(gett(b, a)) + gett(a, b)*x;
        printf("%lld\n", res);
    }
    return 0;
}
