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
const ll MM = 210, inf = 0x3f3f3f3f                             ;
using namespace std;
int n, len, x[MM], t[MM], dp[MM][MM][MM][2], res = 0;
int main()
{
    cin>>n>>len; ms(dp, 0x3f);
    for(int i = 1; i <= n; ++i) cin>>x[i];
    for(int i = 1; i <= n; ++i) cin>>t[i];
    dp[n+1][0][0][0] = 0; x[n+1] = len;
    for(int l = n+1; l > 0; --l){
        for(int r = 0; r < l; ++r){
            for(int k = 0; k <= n-(l-r)+1; ++k){
                int tmp  = min(dp[l][r][k][0]+x[l]-x[l-1], dp[l][r][k][1]+(len-x[l-1]+x[r]));
                int d = (tmp <= t[l-1]) ? 1 : 0;
                dp[l-1][r][k+d][0] = min(dp[l-1][r][k+d][0], tmp);
                tmp = min(dp[l][r][k][0]+(len-(x[l]-x[r+1])), dp[l][r][k][1]+(x[r+1]-x[r]));
                d = (tmp <= t[r+1]) ? 1 : 0;
                dp[l][r+1][k+d][1] = min(dp[l][r+1][k+d][1], tmp);
            }
        }
    }
    for(int l = n+1; l > 0; --l){
        for(int r = 0; r < l; ++r){
            for(int k = 0; k <= n-(l-r)+1; ++k){
                if(dp[l][r][k][0]<inf || dp[l][r][k][1]<inf) res = max(res, k);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
