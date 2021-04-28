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
const ll MM = 3e5+5, mod = 1e9+7;
using namespace std;
int N; ll dp[MM], ans; vector<int> v[MM]; string S;
void dfs(int u, int pa, char col){
    ll sum = 0, join = 0;
    for(auto && i : v[u]){
        if(i==pa) continue;
        dfs(i, u, col);
        join = (join + (sum + join)*dp[i])%mod;
        sum = (sum + dp[i])%mod;
    }
    if(S[u]==col){
        dp[u] = (1+sum+join)%mod;
        ans = (ans+dp[u])%mod;
    }
    else{
        dp[u] = (sum+join)%mod;
        ans = (ans+join)%mod;
    }
}
int main()
{
    cin>>N>>S; S = " "+S;
    for(int i = 1; i < N; ++i){
        int a, b; cin>>a>>b;
        v[a].pb(b); v[b].pb(a);
    }
    dfs(1, 0, 'R'); dfs(1, 0, 'B');
    cout<<ans<<endl;
    return 0;
}
