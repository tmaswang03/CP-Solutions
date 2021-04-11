#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7, MM = 1e6+10;
using namespace std;
int main()
{
    // t to adult, n months, k births/month, c = # of adults
    cin>>N>>K>>T>>C; ms(dp, 0);
    dp[0] = C;
    for(int i = 1; i <= N; ++i){
        dp1[i] = dp1[i-T-1]*K;
        dp1[i]%=MOD;
    }
    res=(2*dp[N])%MOD;
    for(int i = N-1; i >= N-T; --i){ res+= K*dp1[i]; res%=MOD;}
    cout<<res<<endl;
    return 0;
}
