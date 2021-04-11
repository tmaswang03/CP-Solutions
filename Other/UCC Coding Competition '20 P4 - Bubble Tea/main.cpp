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
const ll MM = 1e6+10;
using namespace std;
int N, dp[MM], a[MM];
int main()
{
    cin>>N; ms(dp, 0x3f3f3f); dp[0] = 0;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i <= N; ++i){
        dp[i] = a[i]+dp[i-1];
        if(i>=2){
            dp[i] = min(dp[i], dp[i-2]+a[i]+a[i-1]-min(a[i], a[i-1])/4);
        }
        if(i>=3){
            dp[i] = min(dp[i], dp[i-3]+a[i]+a[i-1]+a[i-2]-min({a[i], a[i-1], a[i-2]})/2);
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}
