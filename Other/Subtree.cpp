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
ll N, mod, x, y, dp[MM], pref[MM], suf[MM], tmp[MM], ret[MM]; vector<int> v[MM];
// dp[n]
// number of ways if node n is black
// answer:
// imagine rooting tree at node n
// answer is
// +1 because you can not include subtree as well
// all subtrees under node n :
// dp[n] = 1
// for (edges):
// dp[n] *= (dp[edges]+1)
void dfs(int cur, int par){
    dp[cur] = 1;
    for(auto && i : v[cur]){
        if(i==par) continue;
        dfs(i, cur);
        dp[cur]*=(dp[i]+1); dp[cur]%=mod;
    }
    // covers all subtrees
    // consider going up towards parents
    // ways *= number of ways parents have not using current
    // pref suf
}
struct edge{
    ll cur, par, carry;
};
/*
10 1000
8 5
10 8
6 5
1 5
4 8
2 10
3 6
9 2
1 7
*/
queue<edge> q;
int main()
{
    cin>>N>>mod;
    for(int i = 0; i < N-1; ++i){
        cin>>x>>y;
        v[x].pb(y); v[y].pb(x);
    }
    dfs(1, -1);
    q.push({1, -1, 1}); ret[1] = dp[1];
    while(!q.empty()){
        edge c = q.front(); q.pop();
        ll cnt = 0, cur = c.cur, par = c.par, carry = c.carry;
        for(auto && i : v[cur]){
            if(i==par) continue;
            tmp[++cnt] = dp[i]+1;
        }
        pref[1] = tmp[1]; suf[cnt] = tmp[cnt]; pref[0] = 1; suf[cnt+1] = 1;
        for(int i = 2; i <= cnt; ++i) pref[i] = (pref[i-1]*tmp[i]) % mod;
        for(int i = cnt-1; i >= 1; --i) suf[i] = (suf[i+1]*tmp[i]) % mod;
        cnt = 0;
        for(auto && i : v[cur]){
            if(i==par) continue;
            ++cnt;
            ll ncarry = (((pref[cnt-1]*suf[cnt+1])%mod*carry)%mod+1)%mod;
            ret[i] = (dp[i]*ncarry)%mod;
            q.push({i, cur, ncarry});
        }

    }
    for(int i = 1; i <= N; ++i) cout<<ret[i]<<endl;
    return 0;
}