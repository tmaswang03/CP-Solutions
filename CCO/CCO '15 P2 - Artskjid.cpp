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
const ll MM = 20, MN = 1e6;
using namespace std;
int N, M, x, y, l, dp[MN][MM]; vector<pii> v[MM];
int dfs(int mask, int cur) {
    if(cur == N-1) return dp[mask][cur] = 0;
    if(dp[mask][cur] != -1) {
        return dp[mask][cur];
    }
    int res = -1e9;
    for(auto && i : v[cur]) {
        int nxt = i.f, w = i.s;
        if(mask & (1<<nxt)) continue;
        res = max(res, w + dfs(mask|(1<<nxt), nxt));
    }
    return dp[mask][cur] = res;
}

int main()
{
    cin>>N>>M; ms(dp, -1);
    for(int i = 0; i < M; ++i) {
        cin>>x>>y>>l;
        v[x].pb({y, l});
    }
    cout<<dfs(1, 0)<<endl;
    return 0;
}