#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
using namespace std;

ll dp[5001];//going
ll dp2[5001];// (not going)


int main()
{
    ms(dp,0);
    ll N,H; gc(N); gc(H);
    for(int i = 0 ; i < N; ++i){
        ms(dp,0);
        //g h q t
        // a = gold to get to NPC
        // b = time to get to NPC
        // c = reward for NPC quest
        // d = time for quest
        ll a,b,c,d; gc(a); gc(b); gc(c); gc(d);
        for(int h = 0; h <= H; ++h){
            if(h>=b){
                dp[h]=max(dp[h],dp2[h-b]+a);
            }
            if(h>=d+b){
                dp[h]=max(dp[h],dp[h-d]+c);
            }
        }
        for(int j = 0; j <= H; ++j){
            dp2[j]=max(dp2[j],dp[j]);
        }
    }

    printf("%lld\n",dp2[H]);


    return 0;
}
