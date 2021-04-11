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
const ll MM = 2e3+10, inf = 0x3f3f3f;
using namespace std;
ll N, strt, dp[MM][MM][2], psa[MM], res;
struct pi{
    ll x, d;
    bool operator < (const pi &o){ return x<o.x; }
}a[MM];
int main()
{
    boost(); cin>>N;
    for(int i = 1; i <= N; ++i) cin>>a[i].x>>a[i].d;
    sort(a+1, a+N+1); ms(dp, -1);
    for(int i = 1; i <= N; ++i){ if(a[i].x==0) strt = i; psa[i]=psa[i-1]+a[i].d;}
    dp[strt][strt][0]=dp[strt][strt][1]=res=a[strt].d;
    for(int l = strt; l > 0; --l){
        for(int r = strt; r <= N; ++r){
            int dstl = a[l].x-a[l-1].x, dstr = a[r+1].x-a[l].x;
            if(dstl <= dp[l][r][0]) dp[l-1][r][0] = max(dp[l-1][r][0], dp[l][r][0]-dstl+a[l-1].d);
            if(dstr <= dp[l][r][0]) dp[l][r+1][1] = max(dp[l][r+1][1], dp[l][r][0]-dstr+a[r+1].d);
            dstr = a[r+1].x-a[r].x, dstl = a[r].x-a[l-1].x;
            if(dstl <= dp[l][r][1]) dp[l-1][r][0] = max(dp[l-1][r][0], dp[l][r][1]-dstl+a[l-1].d);
            if(dstr <= dp[l][r][1]) dp[l][r+1][1] = max(dp[l][r+1][1], dp[l][r][1]-dstr+a[r+1].d);
            if(dp[l][r][1]>=0||dp[l][r][0]>=0) res = max(res, psa[r]-psa[l-1]);
        }
    }
    cout<<res<<endl;
    return 0;
}
