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
ll dp[MM], N, W, a, b, res = 0;
int main()
{
    cin>>N>>W; ms(dp, 0x3f3f3f);
    dp[0] = 0;
    // dp[i] = minimum weight for value of i
    for(int i = 0; i < N; ++i){
        cin>>a>>b;
        for(int j = MM -1; j >= b; --j){
            dp[j] = min(dp[j], dp[j-b] + a);
            if(dp[j] <= W) res = max(res, 1LL*j);
        }
    }
    cout<<res<<endl;
    return 0;
}