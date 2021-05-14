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
const ll MM = 1e5+10;
using namespace std;
int N, a[MM], b[MM], dp[MM][2];
int main()
{
    cin>>N; ms(dp, -0x3f3f3f); dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i <= N; ++i) cin>>b[i];
    dp[1][0] = b[1], dp[1][1] = a[1];
    for(int i = 2; i <= N; ++i){
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]) + b[i];
        dp[i][1] = max(dp[i-1][0], dp[i-2][0]+a[i-1]) + a[i];
    }
    cout<<max(dp[N][1], dp[N][0])<<endl;
    return 0;
}