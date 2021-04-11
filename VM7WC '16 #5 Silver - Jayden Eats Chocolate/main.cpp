#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace std;
int dp[MM], opt[4], N, res = 0;
int main()
{
    scan(N); ms(dp, 0);
    for(int i = 0; i < 3; ++i){
        scan(opt[i]);
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < 3; ++j){
            if(i>=opt[j]){
                if(i - opt[j] > 0 && dp[i-opt[j]]==0) continue;
                dp[i] = max(dp[i], dp[i-opt[j]] + 1);
            }
        }
    }
    printf("%lld\n", dp[N]);
    return 0;
}
