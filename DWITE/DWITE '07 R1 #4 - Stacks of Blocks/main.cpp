#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

int main()
{

    int n,h; gc(h); gc(n);
    int dp[101];
    ms(dp,0x3f);
    dp[0]=0;
    for(int i = 0; i < n; ++i){
        int a; gc(a);
        for(int j = h; j >= a; --j){
            dp[j]=min(dp[j],dp[j-a]+1);
        }
    }
    printf(dp[h]>=0x3f? "0\n" : "%i\n",dp[h]);
    return 0;
}
