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
const ll MM = 5e2+10;
using namespace std;
int x, dp[MM][MM], N, M;
int main()
{
    cin>>N>>M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin>>x;
            if(i==1 && j == 1) dp[i][j] = x;
            if(i==1) dp[i][j] = dp[i][j-1]+x;
            else if(j==1) dp[i][j] = dp[i-1][j]+x;
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + x;
        }
    }
    cout<<dp[N][M]<<endl;
    return 0;
}