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
const ll MM = 2e4+10;
using namespace std;
int dp[MM][2], N, lft[MM], rt[MM];
// dp states : the minimum length to end on left side or right side
int main()
{
    cin>>N; ms(dp, 0x3f3f3f3f); dp[0][0] = dp[0][1] = 0; lft[0] = rt[0] = 1;
    for(int i = 1; i <= N; ++i){
        cin>>lft[i]>>rt[i];
        int len = rt[i]-lft[i];
        // end on the left
        dp[i][0] = 1 + len + min(dp[i-1][0]+abs(rt[i]-lft[i-1]), dp[i-1][1] + abs(rt[i]-rt[i-1]));
        dp[i][1] = 1 + len + min(dp[i-1][0]+abs(lft[i]-lft[i-1]), dp[i-1][1] + abs(lft[i]-rt[i-1]));
    }
    cout<<min(dp[N][0] + abs(N-lft[N]), dp[N][1] + abs(N-rt[N]))-1<<endl;
    return 0;
}
