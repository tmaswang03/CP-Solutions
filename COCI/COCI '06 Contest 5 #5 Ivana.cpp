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
const ll MM = 3e2+10;
using namespace std;
// dp[l][r] = best results in range l r
int dp[MM][MM], N, a[MM], psa[MM], cnt;
int gett (int l, int r) {
    if(l) return psa[r] - psa[l-1];
    return psa[r];
}
int dfs(int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l==r) return dp[l][r] = a[r];
    int res = 0;
    res = max(res, gett(l, r) - dfs(l, r-1));
    res = max(res, gett(l, r) - dfs(l+1, r));
    return dp[l][r] = res;
}
int main()
{
    cin>>N; ms(dp, -1);
    for(int i = 0; i < N; ++i){ cin>>a[i]; a[i]%=2; }
    for(int i = N; i < 3*N; ++i) { a[i] = a[i - N]; }
    psa[0] = a[0];
    for(int i = 1; i < 3*N; ++i) { psa[i] = psa[i-1] + a[i]; }
    for(int i = N; i < 2*N; ++i) {
        if(a[i] + gett(i, i + N - 1) > 2*dfs(i+1, i+N-1) ) ++cnt;
    }
    cout<<cnt<<endl;
    return 0;
}