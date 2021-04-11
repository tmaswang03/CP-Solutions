#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 5e3+100;
using namespace std;
struct item{
    ll n,v,p;
};
ll dp[MM], N, K, M, sum, res = -1e9+10, C, F; item a;
int main()
{
    cin>>N>>M; ms(dp, 0);
    for(ll i = 0; i < N; ++i){
        cin>>a.n>>a.v>>a.p;
        sum = a.n;
        for(ll k = 1; k <= a.n>>1; k<<=1){
            sum-=k;
            for(ll j = 5000; j >= a.v*k; --j){
                dp[j] = max(dp[j], dp[j-a.v*k]+k*a.p);
            }
        }
        for(ll j = 5000; j >= a.v*sum; --j){
            dp[j] = max(dp[j], dp[j-a.v*sum]+sum*a.p);
        }
    }
    for(ll i = 1; i <= 5000; ++i) dp[i] = max(dp[i-1], dp[i]);
    for(ll i = 0; i < M; ++i){
        cin>>C>>F;
        res = max(res, dp[C] - F);
    }
    cout<<res<<endl;
    return 0;
}
