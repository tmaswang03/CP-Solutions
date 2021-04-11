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
const ll MM = 1e5+10, mod = 1e9+7;
using namespace std;
ll dp[MM][2], N, a, b; vector<int> v[MM];
ll dfs(int cur, int par, int col){
    // 1 = black 0 = white
    if(dp[cur][col]!=-1) return dp[cur][col];
    ll res = 1;
    for(auto && i : v[cur]){
        if(i==par) continue;
        if(col==0){
            res*=((dfs(i, cur, 0)+dfs(i, cur, 1))%mod); res%=mod;
        }
        else{
            res*=dfs(i, cur, 0); res%=mod;
        }
    }
    return dp[cur][col]=res%mod;
}
int main()
{
    cin>>N; ms(dp, -1);
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b;
        v[a].pb(b); v[b].pb(a);
    }
    cout<<(dfs(1, -1, 1)+dfs(1, -1, 0))%mod<<endl;
    return 0;
}
