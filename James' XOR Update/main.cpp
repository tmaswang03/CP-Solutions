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
int N, Q, val[MM], dif[2][MM], dpth[MM], a, b, x, lca[20][MM], xo; vector<int> v[MM];
int lg2 (int n){return 31 - __builtin_clz(n);}
void dfs(int cur, int lvl){
    dpth[cur] = lvl;
    for(auto && i : v[cur]){
        if(i==lca[0][cur]) continue;
        lca[0][i] = cur;
        dfs(i, lvl+1);
    }
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
void dfs2(int cur, int a){
    for(auto && i : v[cur]){
        if(i==lca[0][cur])continue;
        dfs2(i, a); dif[a][cur]^=dif[a][i];
    }
}
int main()
{
    scana(N, Q);
    for(int i = 1; i <= N; ++i) scan(val[i]);
    for(int i = 0; i < N-1; ++i){
        scana(a, b);  v[a].pb(b); v[b].pb(a);
    }
    dfs(1, 0);
    for(int i = 1; i < 20; ++i){
        for(int n = 1; n <= N; ++n){
            lca[i][n] = lca[i-1][lca[i-1][n]];
        }
    }
    while(Q--){
        scana(a, b, x);  int par = gett(a, b);
        dif[dpth[a]%2][a]^=x;
        if(dpth[b]%2!=dpth[a]%2)b = lca[0][b];
        dif[dpth[b]%2][b]^=x;
        if(dpth[a]%2==dpth[par]%2) val[par]^=x;
    }
    dfs2(1, 0); dfs2(1, 1);
    for(int i = 1; i <= N; ++i){
        printf("%d ", (val[i]^dif[dpth[i]%2][i]));
    }
    return 0;
}
/*
10 2
0 0 0 0 0 0 0 0 0 0
1 2
1 3
3 4
3 5
2 6
2 7
7 8
8 9
9 10
*/
