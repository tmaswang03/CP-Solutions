#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
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
const ll MM = 400, mod = 1e9+7;
using namespace std;
ll N, dp[MM][MM][2], res = 0, inv[MM], fax[MM];
ll gett(ll in){
    ll out = 1, e = mod-2;
    while(e){
        if(e&1LL) out*=in;
        in*=in; e>>=1; out%=mod; in%=mod;
    }
    return out%mod;
}
ll calc(ll n, ll k){
    return (((fax[n]*inv[k])%mod)*inv[n-k])%mod;
}
ll add(ll x, ll y){
    return (x+y)%mod;
}
int main()
{
    cin>>N;
    fax[0] = 1;
    for(int i = 1; i <= N; ++i) fax[i] = (fax[i-1]*i)%mod;
    for(int i = 0; i <= N; ++i) inv[i] = gett(fax[i]);
    dp[0][0][0] = 1;
    for(int i = 1; i <= N; ++i){
        // dp[i][k][0], the number of ways if you were to give out k vals to the first i children
        // 0 = satisfy none, 1 = satisfy atleast one
        for(int j = 0; j <= N; ++j){
            for(int k = 0; k <= j; ++k){
                ll mul = calc(N-j+k, k);
                if(k!=i) dp[i][j][0] = add(dp[i][j][0], (dp[i-1][j-k][0]*mul)%mod );
                dp[i][j][1] = add(dp[i][j][1], (dp[i-1][j-k][1]*mul%mod));
                if(k==i) dp[i][j][1] = add(dp[i][j][1], dp[i-1][j-k][0]*mul%mod );
                dp[i][j][0]%=mod; dp[i][j][1]%=mod;
            }
        }
    }

    cout<<dp[N][N][1]<<endl;
    return 0;
}
