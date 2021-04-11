#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e3+10;
using namespace std;
struct point{
    int x, y;
    int dist(point p1){
        int x1 = p1.x-x;
        int y1 = p1.y-y;
        return x1*x1+y1*y1;
    }
};

struct pthold{
    int src, nd, lngth;
};
bool comp(const pthold &a,const pthold &b){ return a.lngth < b.lngth;}
point a[MM];
vector< pthold >v; // holds all possible distances for each point
int dp[MM], dpres[MM];
bool vis[MM];
int main()
{
    boost();
    int N; cin>>N; ms(dp, 0);
    for(int i = 0; i < N; ++i){
        int ptx, pty; cin>>ptx>>pty;
        a[i] = {ptx, pty};
    }
    a[N] = {0,0};
    for(int i = 0; i <= N; ++i){
        point pt = a[i];
        for(int j = 0; j <= N; ++j)
            if(i^j) v.pb({i, j , pt.dist(a[j])});
    }

    sort(v.begin(), v.end(), comp);
    // idea, after sorting by increasing distances, run thru and keep track of best dp for each point
    // dp = max dp travelling from one point with a distance less than current
    // vis,  prevents going from doublecounting a road length
    // dpres result
    int lastdist = -1;
    for(int i = 0; i < v.size(); ++i){
        pthold pts = v[i]; int dst = pts.lngth, a = pts.src, b = pts.nd;
        if(dst>lastdist){
            lastdist =dst;
            ms(vis, 0);
        }
        if(!vis[a]){
            dp[a] = dpres[a];
            vis[a] = 1;
        }
        if(!vis[b]){
            dp[b] = dpres[b];
            vis[b] = 1;
        }
        if(a==N) dpres[a] = max(dpres[a], dp[b]);
        if(b==N) dpres[b] = max(dpres[b], dp[a]);
        if(a!=N && b!=N){
            dpres[a] = max(dpres[a], dp[b]+1);
            dpres[b] = max(dpres[b], dp[a]+1);
        }
    }
    cout<<dpres[N]+1<<endl;
    return 0;
}
