#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f;

ll dp[400][400];
ll pfsum[401];
int arr[400];

ll mincost(int l, int r){
    if(dp[l][r]>=INF){
            if(l>r){
                dp[l][r]=INF;
            }
            else if(l==r){
                dp[l][r]=0;
            }
            else{
             for(int i = l; i < r; ++i){
                        dp[l][r]=min(dp[l][r],mincost(l,i)+mincost(i+1,r)+pfsum[r+1]-pfsum[l]);
            }
        }
    }
    return dp[l][r];
}



int main()
{
    ms(dp,INF);
    pfsum[0]=0;
    int n; gc(n);
    for(int i = 0; i < n; ++i){
        int a; gc(a);
        pfsum[i+1]=pfsum[i]+a;
        arr[i]=a;
    }
    for(int l = n-1; l >=0; --l){
        for(int r = l; r < n; ++r){
                if(l==r){
                    dp[l][r]=0;
                }
                else{
                 for(int i = l; i < r; ++i){
                        dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+pfsum[r+1]-pfsum[l]);
                }
            }
        }
    }
    printf("%llu\n",dp[0][n-1]);
    return 0;
}
