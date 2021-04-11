#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e5+5;
using namespace std;
int N,M, K, dis[26][26], psa[maxn][26], dp[maxn], best[maxn][26]; string s;

int main()
{
    //bruce
    cin>>N>>M>>K>>s;
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < M; ++j)
            cin>>dis[i][j];
    for(int k = 0; k < M; ++k)
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < M; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);

    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < M; ++j){
            psa[i][j] = psa[i-1][j] + dis[s[i-1] - 'a'][j];
        }
    }
    ms(dp, 0x3f); dp[0] = 0;
    for(int i = K; i <= N; ++i){
        for(int p = 0; p < M; ++p){
            dp[i] = min(dp[i], best[i-K][p]+psa[i][p]);
        }
        for(int p = 0; p < M; ++p){
            best[i][p] = min(best[i-1][p], dp[i] - psa[i][p]);
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}
