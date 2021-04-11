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
const ll MM = 3e5+10, inf = 1e9;
using namespace std;
struct edge{
    int v, w, id, u;
} t[MM];
int N, M, s, e, val, res = inf, dst[MM], len[MM], pr[MM]; vector<edge> v[MM]; pii a[MM]; vector<int>p[MM];
void dfs(int cur, int par){
    for(auto && i : v[cur]){
        if(i.v==par) continue;
        dst[i.v] = dst[cur]+i.w;
        pr[i.v] = i.id;
        dfs(i.v, cur);
    }
}
void recur(int pt){
    int st = a[pt].f;
    for(int nd = a[pt].s; nd != st;){
        p[pr[nd]].pb(pt);
        if(t[pr[nd]].v!=nd) nd = t[pr[nd]].v;
        else nd = t[pr[nd]].u;
    }
}
int main()
{
    cin>>N>>M;
    for(int i = 0; i < N-1; ++i){
        cin>>s>>e>>val; v[s].pb({e, val, i}); v[e].pb({s, val, i});
        t[i].u = s; t[i].v = e; t[i].w = val; t[i].id = i;
    }
    for(int i = 0; i < M; ++i){
        cin>>a[i].f>>a[i].s; ms(dst, 0);
        dfs(a[i].f, -1); len[i] = dst[a[i].s];
        recur(i);
    }
    for(int i = 0; i < N-1; ++i){
        int ans = 0;
        for(auto && j : p[i]) len[j]-=t[i].w;
        for(int i = 0; i < M; ++i) ans = max(ans, len[i]);
        for(auto && j : p[i]) len[j]+=t[i].w;
        res = min(res, ans);
    }
    cout<<res<<endl;
    return 0;
}
