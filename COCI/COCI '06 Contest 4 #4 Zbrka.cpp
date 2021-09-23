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
const ll MN = 1e3+10, MC = 1e4+10, mod = 1e9+7;
using namespace std;
ll dp[2][MC], N, C, ssa[MC];
ll mmod(ll x){ return ((x % mod) + mod) % mod; }
int main()
{
    cin>>N>>C; dp[0][0] = 1;
    for(int i = 1; i <= N; ++i){
        int ci = i%2, pi = (i+1)%2;
        for(int j = 0; j <= C; ++j) dp[ci][j] = 0;
        for(int j = C; j >= 0; --j) ssa[j] = (dp[pi][j] + ssa[j+1])%mod;
        for(int j = 0; j <= C; ++j){
            dp[ci][j] = mmod(ssa[j-min(i-1, j)] - ssa[j+1]);
        }
    }
    cout<<dp[N%2][C]<<endl;
    return 0;
}