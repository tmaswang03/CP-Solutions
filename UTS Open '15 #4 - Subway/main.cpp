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
const ll MM = 2e3+10;
using namespace std;
struct edge{
    int b, x, y;
};
double dp[MM][MM], diff[MM][MM], top, bot; vector<edge> v[MM]; int N, M, T, a, b, x, y;
// state transitions dp[N][T]
// the probability to be at the Ith station at time t;
// probability of picking edge is 1/adj[i].size();

int main()
{
    cin>>N>>M>>T;
    for(int i = 0; i < M; ++i){
        cin>>a>>b>>x>>y; v[a].pb({b, x, y});
    } dp[0][1] = 1; dp[1][1] = -1;
    for(int t = 0; t <= T; ++t){
        for(int i = 1; i <= N; ++i){
            if(t>=1) dp[t][i]+=dp[t-1][i];
            if(i==N) continue;
            double add = dp[t][i]/(double)v[i].size();
            for(auto && it : v[i]){
                if(t+it.x>T) continue;
                dp[t+it.x][it.b]+=add/(it.y-it.x+1);
                dp[min(T+1, t+it.y+1)][it.b]-=add/(it.y-it.x+1);
            }
        }
    }
    for(int t = 1; t <= T; ++t){
        top+=t*dp[t][N];
        bot+=dp[t][N];
    }
    cout<<fixed<<setprecision(10)<<top/bot<<endl;
    return 0;
}
