#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <climits>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;

using namespace std;

int dp[100000];
int arr[100000];
int main()
{
    ms(dp,-1);
    int N,K; gc(N); gc(K);
    for(int i = 0; i < N; ++i){
        int a; gc(a);
        arr[i]=a;
    }
    dp[0]=0;
    for(int i = 1; i < N; ++i){
        dp[i]=INT_MAX;
        for(int j = 0; j<=K; ++j){
            if(i-j>=0){
                dp[i]=min(dp[i],dp[i-j]+abs(arr[i]-arr[i-j]));
            }
        }
    }
    printf("%i",dp[N-1]);
    return 0;
}
