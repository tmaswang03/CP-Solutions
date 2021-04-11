#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const ll MM = 1e6+10;
using namespace std;
ll N, M, R, dp[MM], bit[MM];
struct intrvl{
    ll st, e, v;
}sev[MM];
bool cmp(intrvl a, intrvl b){
    return a.e<b.e;
}
void upd(ll x, ll val){
    for(; x < MM; x+=x&-x) bit[x] = max(bit[x], val);
}
ll query(ll x){
    ll res = 0;
    for(; x > 0; x-=x&-x) res = max(res, bit[x]);
    return res;
}
int main()
{
    // this is just splitting dp
    cin>>N>>M>>R;
    for(int i = 0; i < M; ++i){
       cin>>sev[i].st>>sev[i].e>>sev[i].v;
    }
    sort(sev, sev + M, cmp);
    for(int i = 0; i < M; ++i){
        dp[sev[i].e] = max(dp[sev[i].e], query(sev[i].st-R)+sev[i].v);
        upd(sev[i].e, dp[sev[i].e]);
    }
    cout<<query(MM-1)<<endl;
    return 0;
}
