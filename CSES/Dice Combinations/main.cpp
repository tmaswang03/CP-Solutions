#include<bits/stdc++.h>
#define REP(i, N) for(int i = 1; i <= N; ++i)
typedef long long ll;
const ll MM = 1e6+10, MOD = 1e9+7;
using namespace std;
ll dp[MM], N;
int main()
{
    dp[0] = 1;
    cin>>N;
    REP(i, N) REP(j, min(i, 6)) dp[i] = (dp[i] + dp[i-j])%MOD;
    cout<<dp[N]<<"\n";
}
