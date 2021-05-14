#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long double ld;
const ll MM = 2e5+10;
using namespace std;
ll N, bit[MM], l[MM], r[MM], h[MM];
// dp[t] : maximum possible value after t minutes;
vector<pll> v; vector<ll> c;
void upd (ll x, ll val){
    for(; x < MM; x+=x&-x) bit[x] = max(bit[x], val);
}
ll que(ll x){
    ll res = 0;
    for(; x > 0; x-=x&-x) res = max(res, bit[x]);
    return res;
}

int main()
{
    boost();
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>l[i]>>r[i]>>h[i];
        r[i] = l[i] + r[i] - 1;
        v.pb({l[i], i}); v.pb({r[i], i});
        c.pb(l[i]); c.pb(r[i]);
    }
    c.pb(0);
    sort(c.begin(), c.end());
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i){
        bool lft = (v[i].f != r[v[i].s]);
        if(!lft){
            int idx = v[i].s;
            int strt = lower_bound(c.begin(), c.end(), l[idx]) - c.begin();
            int endd  = lower_bound(c.begin(), c.end(), r[idx]) - c.begin();
            ll prev = que(strt-1);
            upd(endd, prev + h[idx]);
        }
    }
    cout<<que(MM-1)<<endl;
    return 0;
}