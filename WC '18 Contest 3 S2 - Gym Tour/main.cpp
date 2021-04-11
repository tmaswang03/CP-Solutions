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
vector<int> v[MM]; int N, K, F, dis[MM], dpth[MM], ma, a, b, op1, op2; bool mark[MM];
// help from bruce
void dfs(int cur, int par){
    dis[cur] = 0;
    for(auto && i : v[cur]){
        if(i==par) continue;
        dpth[i] = dpth[cur]+1;
        dfs(i, cur);
        if(mark[i]){
            dis[cur]+=dis[i]+1; mark[cur] = 1;
        }
    }
    if(mark[cur]) ma = max(ma, dpth[cur]);
}
int main()
{
    cin>>N>>K>>F;
    for(int i = 0; i < K; ++i){
        cin>>a; mark[a] = 1;
    }
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b;
        v[a].pb(b); v[b].pb(a);
    }
    dfs(1, 0); op1 = 2*dis[1]-ma;
    mark[F] = 1; dfs(1, 0);
    op2 = dis[1];
    cout<<min(op1, op2)<<endl;
    return 0;
}
