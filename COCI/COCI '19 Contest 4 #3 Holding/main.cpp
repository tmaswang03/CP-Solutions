#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
char _;
int N, L, R, K, a[101], dp[101][10001];
int main()
{
    // help from bruce
    scan(N); scan(L); scan(R); scan(K);
    for(int i = 1; i <= N; ++i){
        scan(a[i]);
    }
    ms(dp, 0x3f); dp[0][0] = 0;
    for(int i = 1 ; i <= N; ++i){
        for(int j = R-L+1; j > 0; --j){
            int cost = abs(i-(L+j-1) );
            for(int k = cost; k <= K; ++k){
                dp[j][k] = min(dp[j][k], dp[j-1][k-cost]+a[i]);
            }
        }
    }
    int ans = 2e9;
    for(int i = 0; i <= K; ++i){
        ans = min(ans, dp[R-L+1][i]);
    }
    cout<<ans<<endl;
    return 0;
}
