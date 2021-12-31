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
const ll MM = 1e5+10, MN = 510, inf = -1e9;
using namespace std;
int a[MN], N, tot = 0, ans = 0, dp[MN][MM], dpp[MM];
int dfs(int pos, int diff) {
    if(dp[pos][diff] != -1) return dp[pos][diff];
    if(pos == N && diff == 0) {
        return dp[N][diff] = 0;
    }
    else if(pos == N) return inf;
    int ret = 0;
    ret = max({dfs(pos+1, diff + a[pos]) + a[pos], dfs(pos+1, diff), dfs(pos+1, abs(diff-a[pos])) + a[pos]});
    return dp[pos][diff] = ret;
}
int main()
{
    cin>>N; ms(dp, -1);
    for(int i = 0; i < N; ++i) {
        cin>>a[i]; tot += a[i];
    }
    cout<<tot - dfs(0, 0)/2<<endl;
    return 0;
}