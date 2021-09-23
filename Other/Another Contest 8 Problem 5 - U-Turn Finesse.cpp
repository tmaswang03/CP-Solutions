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
const ll MM = 1e6+10, mod = 998244353;
using namespace std;
ll a[MM], T, N, bit[MM], pre[MM], suf[MM], res, add;
// count number of increasing subsequences with value <= i;
// number of decreasing subsequences starting at i
// dp[i] =
ll madd(ll x, ll y) {
    return (x+y) %mod;
}
void upd(ll x, ll val) {
    for(; x <= N; x+=x&-x) bit[x] = madd(bit[x], val);
}

ll que(ll x) {
    ll ret = 0;
    for(; x > 0; x-=x&-x) ret = madd(ret, bit[x]);
    return ret;
}

int main()
{
    scan(T);
    while(T--){
        scan(N); res = 0;
        for(int i = 0; i <= N; ++i) bit[i] = 0;
        for(int i = 0; i < N; ++i) scan(a[i]);
        for(int i = 0; i < N; ++i) {
            add = que(a[i]-1) + 1;
            pre[i] = add;
            upd(a[i], pre[i]);
        }
        for(int i = 0; i <= N; ++i) bit[i] = 0;
        for(int i = N-1; i >= 0; --i) {
            add = que(a[i]-1) + 1;
            suf[i] = add;
            upd(a[i], add);
            res += (pre[i]*suf[i])%mod; res %= mod;
        }
        printf("%lld\n", res);
    }
    return 0;
}