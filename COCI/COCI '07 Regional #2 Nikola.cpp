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
const ll MM = 2e3 + 10;
using namespace std;
int N, a[MM], dp[MM][MM];
// dp[i][j]
// minimum cost to get to ith index with j cost
int dfs(int index, int step) {
    if(index >= N || index < 0) return 0x3f3f3f3f3f3f;
    if(index == N - 1) return 0;
    if(dp[index][step] != -1) return dp[index][step];
    int res = 0x3f3f3f3f;
    if(step <= index && step != 0) {
        res = min(res, a[index - step] + dfs(index - step, step));
    }
    res = min(res, a[index + step + 1] + dfs(index + step + 1, step + 1));
    return dp[index][step] = res;
}
int main()
{
    cin>>N; ms(dp, -1); dp[0][0] = 0;
    for(int i = 0; i < N; ++i) cin>>a[i];
    cout<<a[1] + dfs(1, 1)<<endl;
    return 0;
}