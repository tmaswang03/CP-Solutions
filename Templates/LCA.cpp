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
const ll MM = 1e5+10;
using namespace std;
int N, S, a, b, t, psa[MM], dpth[MM], lca[20][MM]; vector<int> v[MM];
int dfs1(int cur){
    for(int i = 1; i < 20; ++i){
        lca[i][cur] = lca[i-1][lca[i-1][cur]];
    }
    for(auto && i : v[cur]){
        if(i==lca[0][cur]) continue;
        dpth[i] = dpth[cur] + 1; lca[0][i] = cur;
        dfs1(i);
    }
}
int gett(int x, int y){
    if(dpth[x] < dpth[y]) swap(x, y);
    for(int i = 19; i >= 0; --i){
        if(dpth[lca[i][x]] >= dpth[y]) x = lca[i][x];
    }
    if(x==y) return x;
    for(int i = 19; i >= 0; --i){
        if(lca[i][x] && lca[i][y] && lca[i][x]!=lca[i][y]) x = lca[i][x], y = lca[i][y];
    }
    return lca[0][x];
}
int main()
{
    cin>>N;
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b; v[a].pb(b); v[b].pb(a);
    } dpth[1] = 1;
    dfs1(1);
}
