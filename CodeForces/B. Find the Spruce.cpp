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
const ll MM = 510;
using namespace std;
char grid[MM][MM]; ll t, n, m, cnt, dp[MM][MM];
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m; ms(dp, 0); ll res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin>>grid[i][j];
                dp[i][j] = (grid[i][j]=='*');
            }
        }
        for(int i = n-1; i >= 0; --i){
            for(int j = 0; j < m; ++j){
                if(dp[i][j]==1){
                    dp[i][j] += min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});
                    res += dp[i][j];
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
