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
int N, X, Y, R, a, b, dst[MM], par[MM], dist[MM], res = 1e6; vector<int> v[MM];
void dfs (int c, int lvl, int p){
    dst[c] = lvl;
    for(auto && i : v[c]){
        if(i==p) continue;
        if(lvl+1 < dst[i]) dfs(i, lvl+1, c);
    }
}
void getmin(int cur, int lvl, int p){
    dist[cur] = lvl;
    for(auto && i : v[cur]){
        if(lvl + 1  < dist[i]){
            par[i] = cur;
            getmin(i, lvl+1, cur);
        }
    }
}
int main()
{
    cin>>N>>R; ms(dst, 0x3f3f3f3f); ms(dist, 0x3f3f3f3f);
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b;
        v[a].pb(b); v[b].pb(a);
    }
    for(int i = 0; i < R; ++i){
        cin>>a; dfs(a, 0, -1);
    }
    cin>>X>>Y; par[X] = -1;
    getmin(X, 0, -1);
    while(Y!=-1){
        res = min(res, dst[Y]);
        Y = par[Y];
    }
    cout<<res<<endl;
    return 0;
}
