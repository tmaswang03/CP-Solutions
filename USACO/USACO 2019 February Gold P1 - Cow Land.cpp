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
vector<ll> et, v[MM];
ll N, Q, in[MM], out[MM], cnt = 1, a, b, lca[LOG][MM], par[MM], dpth[MM], opt, x, y, e[MM], bit[2*MM], res;
ll lg2(ll n){ return 31 - __builtin_clz(n);}
void upd(ll x, ll v){ for(; x < 2*MM; x+=x&-x) bit[x]^=v;}
ll query(ll x){
    ll res = 0;
    for(; x > 0; x-=x&-x) res^=bit[x];
    return res;
}
void dfs(ll cur, ll lvl){
    et.pb(cur); in[cur] = cnt++; dpth[cur] = lvl;
    for(auto && i : v[cur]){
        if(i==par[cur]) continue;
        par[i] = cur;
        dfs(i, lvl+1);
    }
    et.pb(cur); out[cur] = cnt++;
}
void init(){
    for(ll i = 1 ; i <= N; ++i) lca[0][i] = par[i];
    for(ll lg = 1; lg < LOG; ++lg){
        for(ll i = 1; i <= N; ++i){
            lca[lg][i] = lca[lg-1][lca[lg-1][i]];
        }
    }
}
ll gett(ll a, ll b){
    if(dpth[a]<dpth[b]) swap(a, b);
    while(dpth[a]!=dpth[b]){
        ll cur = lg2(dpth[a]-dpth[b]);
        a = lca[cur][a];
    }
    if(a==b) return a;
    for(ll i = LOG-1; i>=0; --i){
        if(lca[i][a]>0 && lca[i][b]>0 && lca[i][a]!=lca[i][b]) a = lca[i][a], b = lca[i][b];
    }
    return lca[0][a];
}
int main()
{
    scana(N, Q); ms(lca, 0);
    for(ll i = 1; i <= N; ++i) scan(e[i]);
    for(ll i = 0; i < N-1; ++i){
        scana(a, b); v[a].pb(b); v[b].pb(a);
    }
    et.pb(0);
    dfs(1, 0);
    for(ll i = 1; i < et.size(); ++i) upd(i, e[et[i]]);
    init();
    while(Q--){
        scana(opt, x, y);
        if(opt==1){
            upd(in[x], e[x]); upd(out[x], e[x]); e[x] = y;
            upd(in[x], e[x]); upd(out[x], e[x]);
        }
        else{
            res = 0;
            res^=query(in[x]); res^=query(in[y]);
            res^=e[gett(x, y)];
            printf("%lld\n", res);
        }
    }
    return 0;
}
