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
const ll MM = 1e5+10, mod = 1e9+7;
using namespace std;
ll N, M, dp[MM], x, y, ans, cnt[MM]; vector<int> v[MM];
int main()
{
    cin>>N>>M;
    for(int i = 0; i < M; ++i){
        cin>>x>>y; v[x].pb(y);
    }
    for(int i = 1; i <= N; ++i){
        cnt[i] = max(cnt[i], 1LL);
        for(auto && j : v[i]){
            cnt[j]+=cnt[i]; cnt[j]%=mod; 
            dp[j] += (dp[i]+cnt[i]);
            dp[j]%=mod; 
        }
        if(v[i].size()==0){
            ans = (ans + dp[i])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}