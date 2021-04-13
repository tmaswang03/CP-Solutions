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
const ll MM = 2e5+10;
using namespace std;
int N, Q, a, b, dpth[MM], lca[20][MM]; vector<int>v[MM];
int lg2(int n){ return 31 - __builtin_clz(n);}
void dfs(int cur, int par, int d){
    dpth[cur] = d; lca[0][cur] = par;
    for(auto && i : v[cur]){
        if(i==par) continue;
        dfs(i, cur, d+1);
    }
}
int gett(int a, int b){
    if(dpth[a]<dpth[b]) swap(a, b);
    while(dpth[a]!=dpth[b]){
        a = lca[lg2(dpth[a]-dpth[b])][a];
    }
    if(a==b) return a;
    for(int i = 19; i >= 0; --i){
        if(lca[i][a] && lca[i][b] && lca[i][a]!=lca[i][b]) a = lca[i][a], b = lca[i][b];
    }
    return lca[0][a];
}
int main()
{
    cin>>N>>Q;
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b; v[a].pb(b); v[b].pb(a);
    }
    dfs(1, -1, 0);
    for(int i = 1; i < 20; ++i){
        for(int j = 1; j <= N; ++j){
            lca[i][j] = lca[i-1][lca[i-1][j]];
        }
    }


    while(Q--){
        cin>>a>>b; int par = gett(a, b);
        cout<<dpth[a]-dpth[par]+dpth[b]-dpth[par]<<endl;
    }
    return 0;
}
