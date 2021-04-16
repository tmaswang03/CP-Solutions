#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e6+1;
using namespace std;
ll arr[MAXN], suff[MAXN], pre[MAXN], temp[MAXN], sufdp[MAXN], day[MAXN], dp[MAXN];
int main()
{
    //with help from bruce
    // i-K<= j <= (day[i]-1)*k
    //dp[i] = max(i-k)-(i-1)*k (dp[j]+val[i]-val[j+1])
    int N, K; scan(N); scan(K);
    for(int i = 1; i <= N; ++i){
        scan(arr[i]); day[i] = (i-1)/K+1;
     }
    ms(suff,0); ms(sufdp,0); ms(dp, 0); ms(pre,0);
    int maxday = (N-1)/K+1;
    for(int i = 1; i <= N; ++i){
        if(day[i]!=day[i-1]) pre[i] = arr[i];
        else pre[i] = max(pre[i-1],arr[i]);
    }
    for(int i = N; i >= 1; --i){
        if(day[i]!=day[i+1]) suff[i] = arr[i];
        else suff[i] = max(suff[i+1],arr[i]);
    }
    for(int i = 1; i <= N; ++i){
        dp[i] = pre[i];
    }
    for(int i = 2; i <= maxday; ++i){ // last = (day[i]-1)*k, first = i-k ==> day[i]-2*k+1, maxday = i*k
        int first = i*K-2*K+1, last = i*K-K;
        sufdp[last] = temp[last] = dp[last];
        for(int r = last-1; r>= first; --r){
            sufdp[r] = max(sufdp[r+1], dp[r]);
            temp[r] = max(temp[r+1], suff[r+1]+dp[r]);
        }
        for(int l = last+1; l <= i*K; ++l) dp[l] = max(sufdp[l-K] + pre[l],temp[l-K]);
    }
    cout<<dp[N]<<endl;


    return 0;
}
