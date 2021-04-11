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
const ll MM = 1e2+10, mod = 1e9+7;
using namespace std;
ll dp[MM][2], N, K, D;
ll dfs(int sum, bool used){
    if(sum==N&&used) return dp[sum][used] = 1;
    if(sum>=N) return 0;
    if(~dp[sum][used]) return dp[sum][used];
    ll res = 0;
    for(int i = 1; i <= K; ++i){
        res+=dfs(sum+i, (used|(i>=D)));
        res%=mod;
    }
    return dp[sum][used] = res;
}
int main()
{
    ms(dp, -1);
    cin>>N>>K>>D;
    cout<<dfs(0, 0)<<endl;
    return 0;
}
