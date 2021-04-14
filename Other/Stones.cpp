#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

int main()
{
    int n,K; gc(n); gc(K);
    int arr[100];
    for(int i = 0; i < n; ++i){
        int a; gc(a);
        arr[i]=a;
    }
    bool dp[100001];
    ms(dp,0);
    for(int i = 1; i <= K; ++i){
        for(int j = 0; j < n; ++j){
            if(i-arr[j]>=0){
                dp[i]=max((int)dp[i],abs(dp[i-arr[j]]-1));
            }
        }
    }
    printf(dp[K] ? "First\n" : "Second\n");

    return 0;
}
