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
const ll MM = 270000;
using namespace std;
ll N, R, o, x, y, w, dp[MM]; vector<pii> v[MM];
ll dfs(int n) {
    if(dp[n] != -1) return dp[n];
    ll res = 0;
    for(auto && i : v[n]) {
        res = max(res, i.s + dfs(i.f));
    }
    return dp[n] = res;
}
int main()
{
    cin>>N>>R; ms(dp, -1);
    for(int i = 0; i < (1<<N) - 1; ++i) {
        cin>>o>>x>>y>>w;
        v[o].pb({x, w}); v[o].pb({y, 0});
    }
    cout<<R + dfs(1)<<endl;
    return 0;
}