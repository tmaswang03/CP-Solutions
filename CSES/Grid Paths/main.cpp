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
const ll MM = 1e3+10, mod = 1e9+7;
using namespace std;
bool grid[MM][MM]; char c; ll N, dp[MM][MM];

int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            cin>>c; grid[i][j] = (c=='.');
        }
    } dp[1][1] = grid[1][1];
    for(int i = 2; i <= N; ++i) dp[1][i] = min(dp[1][i-1], 1LL*grid[1][i]), dp[i][1] = min(dp[i-1][1], 1LL*grid[i][1]);
    for(int i = 1; i <= N; ++i){
        for(int j = 2; j <= N; ++j){
            if(!grid[i][j]) continue;
            dp[i][j] = dp[i-1][j]+dp[i][j-1]; dp[i][j]%=mod;
        }
    }
    cout<<dp[N][N]<<endl;
    return 0;
}
