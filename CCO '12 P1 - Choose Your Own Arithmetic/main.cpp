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
const ll MM = 15, MN = 5e6+10;
using namespace std;
int digs[MM], V, W, D, N; bool vis[MN][7];
void dfs(int c, int m){
    if(m>W||vis[c][m]) return;
    vis[c][m] = 1;
    for(int i = 0; i < D; ++i){
        dfs(c+digs[i] , m+1);
        dfs(c*digs[i], m+1);
    }
}
int main()
{
    scana(W, D);
    REP(i, D) scan(digs[i]);
    scan(V);
    for(int i = 0; i < D; ++i) dfs(digs[i], 0);
    while(V--){
        scan(N);
        if(vis[N][W]) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
