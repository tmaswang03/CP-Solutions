#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef long long ll;
char _;

using namespace std;

int main()
{
    vector<ll>dists;
    ll dp[7001], A, B, N;
    ms(dp,0);
    dists.pb(0); dists.pb(990); dists.pb(1010); dists.pb(1970); dists.pb(2030); dists.pb(3060); dists.pb(2940);
    dists.pb(3930); dists.pb(4060); dists.pb(4970); dists.pb(5030); dists.pb(5990); dists.pb(6010); dists.pb(7000);
    dp[0] = 1;
    scan(A); scan(B); scan(N);
    for(int i = 0; i < N; ++i){
        ll d; scan(d);
        dists.pb(d);
    }
    sort(dists.begin(), dists.end());
    for(int i = 0; i < dists.size(); ++i){
        for(int k = min(dists[i],B); k >= A; --k){
            dp[dists[i]] += dp[dists[i]-k];
        }
    }
    cout<<dp[7000]<<endl;
    return 0;
}
