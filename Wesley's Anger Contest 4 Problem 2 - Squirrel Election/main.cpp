#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;
long long dp[5001];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    pair<int, int>arr[5001];
    int N, total = 0; gc(N);
    for(int i = 1; i <=N; ++i){
        int a,p; gc(a);gc(p);
        arr[i].first=a/2+1;
        arr[i].second=p;
        total+=p;
    }
    ms(dp,0x3f3f3f3f);
    dp[0]=0;
    for(int i = 0; i <= N; ++i){
        for(int j = total; j>=arr[i].second; --j){
                dp[j]=min(dp[j],dp[j-arr[i].second]+arr[i].first);
            }
        }
    long long counter=LONG_MAX;
    for(int i = total/2+1; i <=total; ++i){
        counter=min(counter,dp[i]);
    }
    printf("%lld\n",counter);

    return 0;
}
