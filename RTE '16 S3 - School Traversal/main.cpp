#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef unsigned int ll;
typedef long double ld;
const ll MM = 6e3+10;
using namespace std;
ll dp[MM][MM];
int N, a, b, w, Q;
vector<pii>v[MM];
void dfs(int src, int c){
    for(auto && i : v[c]){
        if(dp[src][i.f]>dp[src][c]+i.s){
            dp[src][i.f] = dp[src][c]+i.s;
            dfs(src, i.f);
        }
    }
}

int main()
{
    scan(N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            dp[i][j] = UINT_MAX;
        }
    }
    for(int i = 0; i < N-1; ++i){
        scana(a, b, w); v[a].pb({b, w}); v[b].pb({a,w});
    }
    for(int i = 0; i < N; ++i){dp[i][i] = 0; dfs(i, i); }
    scan(Q);
    while(Q--){
        scana(a,b);
        printf("%lld\n", dp[a][b]);
    }
    return 0;
}
