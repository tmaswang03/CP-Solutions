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
ll N, K, a[MM], res, inv[MM];
ll calc(ll n, ll k){
    ll out = 1;
    for(ll i = n; i > n-k; --i) out = (out*i)%mod;
    for(ll i = 1; i <= k; ++i){
        out = (out*inv[i])%mod;
    }
    return out%mod;
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
    cin>>N>>K;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i <= K; ++i){
        inv[i] = gett(i);
    }
    sort(a+1, a+N+1);
    // the value = number less icK;
    for(int i = K; i <= N; ++i){
        res=(res+calc(i-1, K-1)*a[i])%mod;
    }
    cout<<res<<endl;
    return 0;
}
