#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef int ll;
#define mp(a,b) make_pair(a,b);
using namespace std;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;


int main()
{
    ll n, t; gc(n); gc(t);
    pii dp[t+1][3]; //  time, value
    ms(dp,0);
    for(int i = 1; i <= n; ++i){
        ll p,a,g,pv,av,gv;
        gc(p); gc(pv); gc(a); gc(av); gc(g); gc(gv); //poortime+val, average + val, good + val
        for(int k = t; k >= min({p,a,g}); --k){
            for(int j = 0; j < 3; ++j){
                if(k-p>=0){
                    dp[k][0].second=max(dp[k][0].second,dp[k-p][j].second+pv);
                }
                if(k-a>=0){
                    dp[k][1].second=max(dp[k][1].second,dp[k-a][j].second+av);
                }
                if(k-g>=0){
                    dp[k][2].second=max(dp[k][2].second,dp[k-g][j].second+gv);
                }
            }
        }
    }
    printf("%lld\n",max({dp[t][0].second,dp[t][1].second,dp[t][2].second}));
    return 0;
}
