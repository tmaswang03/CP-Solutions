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
const ll MM = 2e3+10, mod = 998244353;
using namespace std;
ll N, M, a[MM], dp[MM][MM];
int main()
{
    // idea : dp[i][j] = sum of combinations of first i books using j books
    // = dp[i-1][j] + a[i]*dp[i-1][j-1]
    cin>>N;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i <= N; ++i){
        dp[i][1] = (dp[i-1][1] + a[i])%mod;
        for(int j = 2; j <= i; ++j){
            dp[i][j] += (a[i]*dp[i-1][j-1])%mod;
            dp[i][j] += dp[i-1][j]; dp[i][j] %=mod;
        }
    }
    for(int i = 1; i <= N; ++i){
        cout<<(dp[N][i] + mod)%mod<<" ";
    }
    return 0;
}