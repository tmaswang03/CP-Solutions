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
const ll MM = 1e5+10, mod = 1e9+7;
using namespace std;
ll N, a[MM], D, k, inv[MM], fac[MM];
ll calc(ll n, ll k){
    return (((fac[n]*inv[k])%mod)*inv[n-k])%mod;
}
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
    boost();
    cin>>N; fac[0] = 1;
    for(int i = 1; i <= N; ++i) fac[i]=(fac[i-1]*i)%mod;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 0; i <= N; ++i) inv[i] = gett(fac[i]);
    sort(a+1, a+N+1);
    cin>>D;
    while(D--){
        cin>>k;
        int lo = lower_bound(a+1, a+N+1, a[k]) - a, hi = upper_bound(a+1, a+N+1, a[k]) - a;
        cout<<calc(hi - lo, k - lo + 1)<<endl;
    }
    return 0;
}
