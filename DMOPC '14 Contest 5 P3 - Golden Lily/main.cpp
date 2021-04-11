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
const ll MM = 1e3+10, inf = 0x3f3f3f;
using namespace std;
int L, D, x, y, dp[MM][MM], a[MM][MM];
int dfs(int curx,int cury,int parx,int pary){
    int res = dp[curx][cury];
    if(res!=-1) return res;
    res = inf;
    int curdpth = a[curx][cury];
    if(curx - 1 >= 0 && (curx-1 != parx || cury != pary)){
        res = min(res, curdpth+dfs(curx-1, cury, curx, cury));
    }
    if(curx + 1 < L && (curx+1 != parx || cury != pary)){
        res = min(res, curdpth+ dfs(curx+1, cury, curx, cury));
    }
    if(cury - 1 >= 0){
        res = min(res, curdpth+dfs(curx, cury-1, curx, cury));
    }
    return dp[curx][cury] = res;
}
int main()
{
    ms(dp, 0x3f3f3f3f);
    scan(L); scan(D); // x, y;
    for(int i = 0; i < D; ++i){
        for(int j = 0; j < L; ++j){
            scan(a[i][j]);
        }
    }
    scan(x); scan(y);
    queue<pair<int, int> > q;
    dp[0][0]=a[0][0];
    q.push({0,0});
    while(!q.empty()){
        int curx = q.front().f, cury = q.front().s; q.pop();
        int curdpth = dp[cury][curx];
        if(curx - 1 >= 0 && (dp[cury][curx-1]>curdpth+a[cury][curx-1])){
            dp[cury][curx-1]=curdpth+a[cury][curx-1];
            q.push({curx-1,cury});
        }
        if(curx + 1 < L && (dp[cury][curx+1]>curdpth+a[cury][curx+1])){
            dp[cury][curx+1]=curdpth+a[cury][curx+1];
            q.push({curx+1,cury});
        }
        if(cury + 1 < D &&  (dp[cury+1][curx]>curdpth+a[cury+1][curx])){
            dp[cury+1][curx]=curdpth+a[cury+1][curx];
            q.push({curx, cury+1});
        }
    }
    printf("%d\n", dp[y][x]);
    return 0;
}
