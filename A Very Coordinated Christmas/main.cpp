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
const ll MM = 1e3+10;
using namespace std;
char grid[MM][MM]; int dst[MM][MM], dirx[4] = {0, 0, -1, 1}, diry[4] = {1, -1, 0, 0}, N, M, stx, sty, ex, ey, px, py, res = 0;
queue<pii>q;
int main()
{
    cin>>N>>M; ms(dst, 0x3f3f3f3f);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin>>grid[i][j];
            if(grid[i][j]=='O'){stx = i; sty = j;}
            else if(grid[i][j]=='X'){ex = i; ey = j;}
            else if(grid[i][j]=='P'){px = i; py = j;}
        }
    }
    q.push({stx, sty}); dst[stx][sty] = 0;
    while(!q.empty()){
        auto c = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = c.f + dirx[i], ny = c.s+diry[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || grid[nx][ny]=='#') continue;
            if(dst[c.f][c.s]+1 < dst[nx][ny]){
                dst[nx][ny] = dst[c.f][c.s]+1;
                q.push({nx, ny});
            }
        }
    }
    res+=dst[px][py]; ms(dst, 0x3f3f3f3f); dst[px][py] = 0;
    q.push({px, py});
    while(!q.empty()){
        auto c = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = c.f + dirx[i], ny = c.s+diry[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || grid[nx][ny]=='#') continue;
            if(dst[c.f][c.s]+1 < dst[nx][ny]){
                dst[nx][ny] = dst[c.f][c.s]+1;
                q.push({nx, ny});
            }
        }
    }
    res+=dst[ex][ey];
    if(res>=0x3f3f3f3f) cout<<-1<<endl;
    else cout<<res<<endl;
    return 0;
}
