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
int n, m, cnt, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}; bool vis[MM][MM]; char c;
void mark(int x, int y){
    queue<pii> q; q.push({x, y}); vis[x][y] = 1;
    while(!q.empty()){
        auto c = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = c.f+dx[i], ny = c.s+dy[i];
            if(nx<0||nx>n||ny>m||ny<0||!vis[nx][ny]) continue;
            vis[nx][ny] = 0; q.push({nx, ny});
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin>>c; vis[i][j] = (c=='.');
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!vis[i][j]) continue;
            ++cnt;
            mark(i, j);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
