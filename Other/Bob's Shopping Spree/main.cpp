#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e3+10;
using namespace std;
struct deal{
    ll q,t,d, a;
};

struct item{
    ll p, s;
};
ll N, M, K, dp[MM];
deal ds[MM];
item itms[MM];
int main()
{
    ms(dp, 0);
    scan(N); scan(M); scan(K);
    for(int i = 1; i <= N; ++i){
        scan(itms[i].p); scan(itms[i].s);
    }
    for(int i = 1; i <= M; ++i){
        scan(ds[i].q); scan(ds[i].t); scan(ds[i].d); scan(ds[i].a);
    }
    for(int j = 1; j <= N; ++j){
        for(int i = itms[j].p; i <= K; ++i){
            dp[i] = max(dp[i], dp[i-itms[j].p]+itms[j].s);
        }
    }

    for(int j = 1; j <= M; ++j){
        ll sum = 0;
        for(int k = 1; k <= ds[j].a>>1; k<<=1){
            for(int i = K; i >= ds[j].d*k; --i){
                dp[i] = max(dp[i], dp[i-ds[j].d*k]+itms[ds[j].t].s*ds[j].q*k);
            }
            sum+=k;
        }
        sum = ds[j].a - sum;
        for(int i = K; i >= ds[j].d*sum; --i){
            dp[i] = max(dp[i], dp[i-ds[j].d*sum]+itms[ds[j].t].s*ds[j].q*sum);
        }
    }

    printf("%lld\n", dp[K]);
    return 0;
}
