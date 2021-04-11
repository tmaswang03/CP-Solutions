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
const ll MM = 1e5+10;
using namespace std;
int N, a[MM], dp[MM]; bool vis[MM];
vector<int> v[MM]; priority_queue<pii>pq;
// idea : find the boxes that hold the greatest # of keys
int dfs1(int cur){
    if(dp[cur]!=-1) return dp[cur];
    dp[cur] = 0;
    for(auto && i : v[cur]) dp[cur]+=dfs1(i);
    return ++dp[cur];
}

void dfs2(int cur){
    vis[cur] = 1;
    for(auto && i : v[cur]){
        if(!vis[i]) dfs2(i);
    }
}
int main()
{
    for(int t = 0; t < 2; ++t){
        cin>>N; ms(dp, -1); ms(vis, 0); int cnt = 0;
        for(int i = 1; i <= N; ++i) v[i].clear();
        for(int i = 1; i <= N; ++i){
            cin>>a[i]; v[a[i]].pb(i);
        }
        for(int i = 1; i <= N; ++i) if(dp[i]==-1) dfs1(i);
        for(int i = 1; i <= N; ++i) pq.push(mp(dp[i], i));
        while(!pq.empty()){
            int c = pq.top().s; pq.pop();
            if(!vis[c]){++cnt; dfs2(c);}
        }
        cout<<cnt<<" ";
    }
    return 0;
}
