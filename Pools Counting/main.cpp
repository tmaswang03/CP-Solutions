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
const ll MM = 1e2+10;
using namespace std;
int N, M, K, dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, 1, -1}, x, y, cnt; bool vis[MM][MM], used[MM][MM];
queue<pii> q;
void bfs(int x, int y){
    q.push({x, y}); used[x][y] = 1;
    while(!q.empty()){
        auto c = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = c.f + dirx[i], ny = c.s+diry[i];
            if(!used[nx][ny]&&vis[nx][ny]){
                q.push({nx, ny});
                used[nx][ny] = 1;
            }
        }
    }
}

int main()
{
    ms(vis, 0);
    cin>>N>>M>>K;
    for(int i = 0; i < K; ++i){
        cin>>x>>y;
        vis[x][y] = 1;
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(used[i][j]||!vis[i][j]) continue;
            ++cnt;
            bfs(i, j);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
