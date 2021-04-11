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
const ll MM = 1e5+10, MN = 2e5+10;
using namespace std;
vector<int> v[MM]; ll in[MM], out[MM], dpth[MM], t, N, a, b, Q, lca[20][MM], val[MM], bit[MN]; char opt;
int lg2(int n) { return 31 - __builtin_clz(n);}
void upd(int c, ll val){ for(c; c < MN; c+=c&-c) bit[c]+=val;}
ll query(int c){
    ll res = 0;
    for(; c > 0; c-=c&-c) res+=bit[c];
    return res;
}
void dfs(int c, int p, int lvl){
    in[c] = ++t; dpth[c] = lvl;
    for(auto && i : v[c]){
        if(i==p) continue; lca[0][i] = c;
        dfs(i, c, lvl+1);
    }
    out[c] = ++t;
}

void init(){
    for(int i = 1; i < 20; ++i)
        for(int c = 1; c <= N; ++c) lca[i][c] = lca[i-1][lca[i-1][c]];
}
int gett(int a, int b){
    if(dpth[a]<dpth[b]) swap(a, b);
    while(dpth[a]!=dpth[b]) a = lca[lg2(dpth[a]-dpth[b])][a];
    if(a==b) return a;
    for(int i = 19; i >= 0; --i){
        if(lca[i][a]&&lca[i][b]&&lca[i][a]!=lca[i][b]) a = lca[i][a], b = lca[i][b];
    }
    return lca[0][a];
}
int main()
{
    cin>>N;
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b; v[a].pb(b); v[b].pb(a);
    }
    dfs(1, 0, 0);
    init();
    ms(bit, 0); ms(val, 0);
    cin>>Q;
    while(Q--){
        cin>>opt>>a>>b;
        if(opt=='Q'){
            int par = gett(a, b);
            cout<<query(in[a]) - query(in[par]) + query(in[b]) - query(in[par]) + val[par] - val[a] - val[b]<<endl;
        }
        else{
            upd(in[a], -val[a]); upd(out[a]+1, val[a]); val[a] = b;
            upd(in[a], b); upd(out[a]+1, -b);
        }
    }
    return 0;
}
