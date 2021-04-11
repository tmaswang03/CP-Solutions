#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

long long dp[100001];


int main()
{
    int N,M; gc(N);gc(M);
    for(int i = 0; i < N; ++i){
        int a,p; gc(a); gc(p);
        for(int j = M; j>=p; --j){
                dp[j]=max(dp[j],dp[j-p]+a);

            }
        }

    printf("%lld\n",dp[M]);

    return 0;
}
