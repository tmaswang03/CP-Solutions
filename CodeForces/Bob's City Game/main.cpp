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
int H, W, N, grid[MM][MM], res = 1e9+10; ;
int dif(int x, int y){
    int min1 = 1e9+10, max1 = 0;
    for(int i = x; i <= x+N-1; ++i){
        for(int j = y; j<= y+N-1; ++j){
            min1 = min(min1, grid[i][j]);
            max1 = max(max1, grid[i][j]);
        }
    }
    return max1 - min1;
}
int main()
{
    scan(H); scan(W); scan(N);
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            scan(grid[i][j]);
        }
    }
    for(int i = 0; i <= H-N; ++i){
        for(int j = 0; j<= W-N; ++j){
            res = min(res, dif(i, j));
        }
    }
    cout<<res<<endl;
    return 0;
}
