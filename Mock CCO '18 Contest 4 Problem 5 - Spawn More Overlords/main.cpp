#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e4+10, inf = 0x3f3f3f3f, MN = 1e4;
int s[MM], u[MM], dp[MM];
using namespace std;
int main()
{
    ms(dp, inf);
    int N, T; scan(N); scan(T);
    for(int i = 0; i < N; ++i)
        scan(s[i]);
    for(int i = 0; i < N; ++i)
        scan(u[i]);
    dp[0] = 0;
    for(int i = 0; i < N; ++i){
        int sum = 0;
        for(int k = 1; k <= u[i]>>1; k<<=1){
            for(int j = MN; j >= s[i]*k; --j){
                dp[j] = min(dp[j], dp[j-s[i]*k]+k);
            }
            sum+=k;
        }
        sum = u[i]-sum;
        for(int j = MN; j >= s[i]*sum; --j){
            dp[j] = min(dp[j], dp[j-s[i]*sum]+sum);
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = MN-s[i]; j >= 0; --j){
            dp[j] = min(dp[j+s[i]]+1, dp[j]);
        }
    }
    printf(dp[T]==inf ? "-1\n" : "%d\n", dp[T]);
    return 0;
}
