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
const ll MM = 1e6+10, MN = 1e3+10;
using namespace std;
ll T, N, M, dp[MM][2], a[MN][2], b[MN][2], res = 0; bool vis[MM][2];
int main()
{
    cin>>T;
    while(T--){
        cin>>N>>M; ms(vis, 0); vis[0][1] = vis[0][0] = 1; ms(dp, -0x3f3f3f3f); res = 0;
        dp[0][0] = dp[0][1] = 0;
        for(int i = 0; i < N; ++i){
            cin>>a[i][0]>>b[i][0];
            for(int j = MM-1; j >= a[i][0]; --j){
                vis[j][0]|=vis[j-a[i][0]][0]; dp[j][0] = max(dp[j][0], dp[j-a[i][0]][0]+b[i][0]);
            }
        }
        for(int i = 0; i < M; ++i){
            cin>>a[i][1]>>b[i][1];
            for(int j = MM-1; j >= a[i][1]; --j){
                vis[j][1]|=vis[j-a[i][1]][1]; dp[j][1] = max(dp[j][1], dp[j-a[i][1]][1]+b[i][1]);
            }
        }
        for(int i = 0; i < MM; ++i){
            if(!vis[i][0]||!vis[i][1]) continue;
            res = max(res, dp[i][0]+dp[i][1]);
        }
        cout<<res<<endl;
    }
    return 0;
}
