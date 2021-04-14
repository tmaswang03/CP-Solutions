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
const ll MM = 2e5+10, mod = 998244353;
using namespace std;
ll N, dp[MM], dnum = 1, num, divd;
ll gett(ll in){
    ll out = 1, e = mod-2;
    while(e){
        if(e&1LL) out*=in;
        in*=in; e>>=1; out%=mod; in%=mod;
    }
    return out%mod;
}
int main()
{
    cin>>N;
    dp[0] = 1; dp[1] = 1;
    for(int i = 2; i <= N-1; ++i){
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }
    for(int i = 1; i <= N; ++i) dnum = (dnum*2)%mod;
    num = dp[N-1]; divd = gcd(num, dnum);
    num/=divd; dnum/=divd;
    dnum = gett(dnum);
    cout<<(num*dnum)%mod<<endl;
}
