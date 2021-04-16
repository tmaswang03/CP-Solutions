#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MAXN = 1e9+10;
const ll DPM = 6000000;
using namespace std;
ll dp[DPM];
ll sqr(ll N){ return N*N; }
ll solve(ll N){
    if(N==1||N==2) return dp[N] = 1;
    if(N < DPM && dp[N]!=-1) return dp[N];
    ll res = 0;
    for(ll i = 1; sqr(i) <= N; ++i){
        if(sqr(N/i)>N && i!=1){
            res+=solve(N/i);
        }
        res+=solve(i)*(N/i-N/(i+1));
    }
    if(N<DPM) return dp[N] = res;
    return res;
}
int main()
{
    ll N; cin>>N; ms(dp, -1);
    cout<<solve(N)<<endl;
    return 0;
}
