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
ll N, x, y, c1[MM], c2[MM], tot, t[20][MM], dpth[MM], cnt[MM], psa[MM];
int lg2(int in){ return 31 - __builtin_clz(in);}
struct edge{
    int b, idx;
};
vector<edge> v[MM];
void dfs(int cur, int par, int l){
    dpth[cur] = l; t[0][cur] = par;
    for(auto && i : v[cur]){
        if(i.b==par) continue;
        dfs(i.b, cur, l+1);
    }
}
int gett(int a, int b){
    if(dpth[a]<dpth[b]) swap(a, b);
    while(dpth[a]!=dpth[b]) a = t[lg2(dpth[a]-dpth[b])][a];
    if(a==b) return a;
    for(int i = 19; i >= 0; --i){
        if(t[i][a] && t[i][b] && t[i][a]!=t[i][b]) a = t[i][a], b = t[i][b];
    }
    return t[0][a];
}
void dfs2(int cur, int par){
    for(auto && i : v[cur]){
        if(i.b==par) continue;
        dfs2(i.b, cur);
        cnt[i.idx]+=psa[i.b];
        psa[cur]+=psa[i.b];
    }
}
int main()
{
    cin>>N;
    for(int i = 0; i < N-1; ++i){
        cin>>x>>y>>c1[i]>>c2[i];
        v[x].pb({y, i});
        v[y].pb({x, i});
    }
    dfs(1, -1, 0);
    for(int l = 1; l < 20; ++l){
        for(int i = 1; i <= N; ++i){
            t[l][i] = t[l-1][t[l-1][i]];
        }
    }
    for(int i = 2; i <= N; ++i){
        int lca = gett(i, i-1);
        ++psa[i]; ++psa[i-1]; psa[lca]-=2;
    }
    dfs2(1, -1);
    for(int i = 0; i < N-1; ++i){
        tot+=min(c1[i]*cnt[i], c2[i]);
    }
    cout<<tot<<endl;
    return 0;
}