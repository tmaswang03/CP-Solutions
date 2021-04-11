#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 3e3+10;
using namespace std;
ll H, W, N, grid[MM][MM], mins[MM][MM], explosions[MM][MM], res = 1e9+10 ;
int main()
{
    scan(H); scan(W); scan(N);
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            scan(grid[i][j]);
        }
    }
    for(int i = 0; i < H; ++i){
        priority_queue<pair<ll, ll > >exp;
        priority_queue<pair<ll,ll>,  vector<pair<ll,ll>>, greater<pair<ll,ll>> >mi;
        for(int j = 0; j < W; ++j){
            while(!exp.empty() && exp.top().s < j - N +1) exp.pop();
            while(!mi.empty() && mi.top().s < j - N +1) mi.pop();
            exp.push({grid[i][j], j});
            mi.push({grid[i][j], j});
            explosions[i][j] = exp.top().f;
            mins[i][j] = mi.top().f;
        }
    }
    for(int i = 0; i < W; ++i){
        priority_queue<pair<ll, ll > >exp;
        priority_queue<pair<ll,ll>,  vector<pair<ll,ll>>, greater<pair<ll,ll>> >mi;
        for(int j = 0; j < H; ++j){
            while(!exp.empty() && exp.top().s < j - N +1) exp.pop();
            while(!mi.empty() && mi.top().s < j - N +1) mi.pop();
            exp.push({explosions[j][i], j});
            mi.push({mins[j][i], j});
            explosions[j][i] = exp.top().f;
            mins[j][i] = mi.top().f;
        }
    }
    for(int i = H-1; i >= N-1; --i){
        for(int j = W-1; j >= N-1; --j){
            res = min(res, explosions[i][j]- mins[i][j]);
        }
    }
    printf("%lld\n", res);
    return 0;
}
