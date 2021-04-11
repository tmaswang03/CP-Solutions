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
const ll MM = 5e2+10, inf = 1e9;
using namespace std;
ll dp[MM][MM], x, y;
ll gett(int x, int y){
    ll res = inf;
    if(dp[x][y]!=-1) return dp[x][y];
    if(x==y) return dp[x][y] = 0;
    for(int i = 1; i <= x/2; ++i){
        res = min(res, 1LL + gett(i, y) + gett(x-i, y));
    }
    for(int i = 1; i <= y/2; ++i){
        res = min(res, 1 + gett(x, i) + gett(x, y-i));
    }
    return dp[x][y] = res;
}
int main()
{
    cin>>x>>y; ms(dp, -1);
    cout<<gett(x, y)<<endl;
    return 0;
}
