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
const ll MM = 1510, inf = 0x3f3f3f;
using namespace std;
int N, v[MM][MM], dp[MM][MM], res = inf;
// interval dp
// start with only the first element
// pick where to place the next number
// you can either place at front or back
int recur(int frnt, int bak){
    if(dp[frnt][bak]!=-1) return dp[frnt][bak];
    if(frnt>=N||bak>=N) return 0; int mx = max(frnt, bak);
    // add to front or to the back
    return dp[frnt][bak] = min(recur(mx+1, bak)+v[mx+1][frnt], recur(frnt, mx+1) + v[mx+1][bak]);
}
int main()
{
    cin>>N; ms(dp, -1);
    for(int i = 0; i < N; ++i){
       for(int j = 0; j < N; ++j){
            cin>>v[i][j];
       }
    }
    cout<<recur(0,0)<<endl;
    return 0;
}
