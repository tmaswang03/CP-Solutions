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
const ll MM = 20;
using namespace std;
vector<int> v[MM]; bool vis[MM], edge; int N, cnt = 0;
void dfs(int cur){
    vis[cur] = 1;
    for(auto && i : v[cur]){
        if(vis[i]){ ++cnt; continue;}
        if(i<=cur) continue;
        dfs(i);
    }
    vis[cur] = 0;
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin>>edge;
            if(edge) v[i].pb(j);
        }
    }
    for(int i = 0; i < N; ++i) dfs(i);
    cout<<cnt<<endl;
    return 0;
}
