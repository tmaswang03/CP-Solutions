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
const ll MM = 6e2+10;
using namespace std;
int dp[MM][MM], W, H, N, w, h; bool vis[MM][MM];
int dfs(int width, int height) {
    if(dp[width][height] != -1) return dp[width][height];
    if(vis[width][height]) return dp[width][height] = 0;
    int res = width*height;
    for(int i = 1; i < width; ++i) {
        res = min(res, dfs(i, height) + dfs(width - i, height));
    }
    for(int i = 1; i < height; ++i) {
        res = min(res, dfs(width, i) + dfs(width, height - i));
    }
    return dp[width][height] = res;
}
int main()
{
    cin>>W>>H>>N; ms(dp, -1);
    for(int i = 0; i < N; ++i) {
        cin>>w>>h; vis[w][h] = 1;
    }
    cout<<dfs(W, H)<<endl;
    return 0;
}