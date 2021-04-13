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
const ll MM = 1e2+10;
using namespace std;
int M, N, dp[MM], b[MM];
int main()
{
    for(;;){
        ms(dp, 0x3f3f3f); dp[0] = 0;
        scan(M); scan(N);
        if(N == 0 && M == 0) return 0;
        for(int i = 0; i < N; ++i) scan(b[i]);
        for(int i = 0; i < N; ++i){
            for(int j = b[i]; j <= M; ++j){
                dp[j] = min(dp[j], dp[j-b[i]]+1);
            }
        }
        if(dp[M]!=0x3f3f3f) cout<<dp[M]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
