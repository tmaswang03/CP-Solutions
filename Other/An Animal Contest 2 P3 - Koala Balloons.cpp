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
const ll MM = 1510;
using namespace std;
int N, M, res, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}, psa[MM][MM]; bool vis[MM][MM]; char re; queue<pii> q;
int gett(int tx, int ly, int sz){
    int bx = tx+sz-1, ry = ly+sz-1;
    return psa[bx][ry]-psa[tx-1][ry]-psa[bx][ly-1]+psa[tx-1][ly-1];
}
bool check(int tx, int ly, int sz){
    if(tx<=0||ly<=0||tx+sz-1>N||ly+sz-1>M) return 0;
    if(gett(tx, ly, sz)>0) return 0;
    return 1;
}
bool solve(int sz){
    int sx = sz, sy = sz;
    ms(vis, 0); vis[sx][sy] = 1;
    if(!check(1, 1, sz)) return 0;
    q.push({sx, sy});
    while(!q.empty()){
        int cx = q.front().f, cy = q.front().s; q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = cx+dx[i], ny = cy+dy[i]; bool chk = 0;
            if(check(nx-sz+1, ny-sz+1, sz) && !vis[nx][ny]){
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return vis[N][M];
}
int main()
{
    cin>>N>>M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin>>re;
            if(re=='X'){
                psa[i][j] = 1;
            }
            psa[i][j]+=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }
    int lo = 0, hi = min(N, M);
    while(lo < hi){
        int mid = (lo+hi+1)>>1;
        if(solve(mid)){
            lo = mid; res = mid;
        }
        else hi = mid-1;
    }
    cout<<res<<endl;
    return 0;
}