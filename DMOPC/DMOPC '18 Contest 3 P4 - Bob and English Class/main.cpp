#include<bits/stdc++.h>
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
const ll MM = 2e5+10;
using namespace std;
int K, N, z[MM], a, b, d, dpth[MM], dst[MM], t[MM][20]; vector<pii> v[MM];
int lg2(int x){ return 31 - __builtin_clz(x); }
void dfs(int cur, int d, int lvl){
    dpth[cur] = lvl; dst[cur] = d;
    for(auto && i : v[cur]){
        if(i==t[cur][0]) continue;
        t[i][0] = cur; dfs(i, d+i.s, lvl+1);
    }
}
int lca(int a, int b){
    if(dpth[a]<dpth[b]) swap(a, b);
    while(dpth[a]!=dpth[b]){
        a = lca[lg2(dpth[a]-dpth[b])][a];
    }
    if(a==b) return a;
    for(int i = 19; i >= 0; --i){
        if(lca[a][i] && lca[b][i] && lca[a][i]!=lca[b][i]){
            a = lca[a][i]; b = lca[b][i];
        }
    }
    return lca[a][0];
}
int main()
{
    cin>>N>>K;
    for(int i = 1; i <= K; ++i){
        cin>>z[i];
    }
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b>>d; v[a].pb({b, d}); v[b].pb({a, d});
    }
    for(int i = 1; i < 20; ++i){
        for(int j = 1; j <= N; ++j){
            t[i][j] = t[t[i-1][j]][i];
        }
    }
    return 0;
}
