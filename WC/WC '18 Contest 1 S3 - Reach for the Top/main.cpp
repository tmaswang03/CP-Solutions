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
const ll MM = 2e6+10, inf = 0x3f3f3f3f;
using namespace std;
ll dp[MM], H, J, ans = inf, N, pt, bit[MM]; pii a[MM];
ll conv(int i){ return MM - i-1; }
void upd(int x, ll val){
    for(; x < MM; x+=x&-x) bit[x] = min(bit[x], val);
}
ll que(int x){
    ll res = inf;
    for(; x > 0; x-=x&-x) res = min(res, bit[x]);
    return res;
}
int main()
{
    cin>>H>>J>>N; ms(dp, inf); ms(bit, inf);
    for(int i = 0; i < N; ++i){
        cin>>a[i].f>>a[i].s;
    }
    sort(a, a+N); dp[0] = 0;
    for(int i = 1; i <= H+J; ++i){
        while(a[pt].s<i && pt < N) ++pt;
        if(a[pt].f <= i && i <=a[pt].s){
            dp[i] = -1; continue;
        }
        if(i<J) continue;
        if(dp[i-J]!=-1) {
            dp[i] = 1 + min(dp[i-J], que(conv(i-J)));
            upd(conv(i), dp[i]+1);
        }
        if(i >= H) ans = min(ans, dp[i]);
    }
    if(ans!=inf) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
