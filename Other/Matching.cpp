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
const ll MM = 25, mod = 1e9+7;
using namespace std;
ll a[MM][MM], N, dp[1<<20];
// dp transitions : use a bitmask to see who is left, only matters who is left to match up
ll dfs(int cur, int msk){
    if(cur==N) return 1;
    if(dp[msk]!=-1) return dp[msk];
    int res = 0;
    for(int i = 0; i < N; ++i){
        if(msk&(1<<i)) continue; // this person is already used
        if(a[cur][i]) res += dfs(cur+1,msk|(1<<i));
        res%=mod;
    }
    return dp[msk]=res%mod;
}
int main()
{
    cin>>N; ms(dp, -1);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) cin>>a[i][j];
    }
    cout<<dfs(0, 0)<<endl;
    return 0;
}
