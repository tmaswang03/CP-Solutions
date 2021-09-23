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
const ll MM = 60;
using namespace std;
ll dp[MM][MM][MM][MM], N, M, psa[MM][MM], a[MM][MM];
ll calc (ll tx, ll ty, ll bx, ll by){
    return psa[bx][by] - psa[tx-1][by] - psa[bx][ty-1] + psa[tx-1][ty-1];
}
ll dfs(ll tx, ll ty, ll bx, ll by){
    if(tx == bx && ty == by) dp[tx][ty][bx][by] = 0;
    if(dp[tx][ty][bx][by]!=-1) return dp[tx][ty][bx][by];
    ll res = LLONG_MAX, add = calc(tx, ty, bx, by);
    for(int i = tx; i < bx; ++i){
        res = min(res, dfs(tx, ty, i, by) + dfs(i+1, ty, bx, by));
    }
    for(int i = ty; i < by; ++i){
        res = min(res, dfs(tx, ty, bx, i) + dfs(tx, i+1, bx, by));
    }
    res += add;
    return dp[tx][ty][bx][by] = res;
}
int main()
{
    cin>>N>>M; ms(dp, -1);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin>>a[i][j]; psa[i][j] = psa[i][j-1] + psa[i-1][j] - psa[i-1][j-1] + a[i][j];
        }
    }
    cout<<dfs(1, 1, N, M);
    return 0;
}