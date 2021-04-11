#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;

ll dp[4000][4000];
ll dp2[4000][4000];


ll stressless (int w, int o){
    if(w<0||o<0){
        return 0;
    }
    if(dp[w][o]==-1){
        if(w<=o){
            dp[w][o]=0;
        }
        else if(o==0){
            dp[w][o]=1;
        }
        else{
            dp[w][o]=(stressless(w-1 ,o)+stressless(w,o-1))%mod;
        }
    }

    return dp[w][o];
}



int main()
{
    ms(dp,-1);
    ms(dp2,-1);
    int w,o;
    int t; gc(t);
    for(int i = 1; i <= t; ++i){
        scanf("%i-%i", &w, &o);
        printf("Case #%i: %i %i\n",i,stressless(w,o),stressless(o+1,o));
    }
    return 0;
}
