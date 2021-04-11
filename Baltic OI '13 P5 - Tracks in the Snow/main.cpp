#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
const ll MM = 4e3+10;
using namespace std;
char print, grid[MM][MM]; int cnt = 0, h, w, prnt, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1}, x, y, c1 = 1, c2 = 0;
bool visited[MM][MM], used[MM][MM];
queue<pii>q[2];
// idea : bfs top tracks and then bfs all the tracks around it
pii gett(){
    for(int i = h; i >= 1; --i){
        for(int j = w; j >= 1; --j){
            if(grid[i][j]!='.' && !visited[i][j]) return mp(i, j);
        }
    }
    return {0, 0};
}
int main()
{
/*
3 5
RRRRR
RCRCR
RCRCR
*/
    cin>>h>>w; ms(visited, 0);
    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            cin>>grid[i][j]; prnt+=grid[i][j]!='.';
        }
    }
    q[0].push({h,w}); visited[h][w] = 1;
    if(grid[h][w]=='R') print = 'F';
    else print = 'R';
    while(!q[c1].empty()||!q[c2].empty()){
        ++cnt;
        if(print=='R') print = 'F';
        else print = 'R';
        c1^=1; c2^=1;
        while(!q[c1].empty()){
            auto c = q[c1].front(); q[c1].pop();
            for(int i = 0; i < 4; ++i){
                int x = dx[i]+c.f, y = dy[i]+c.s;
                if(x<=0||y<=0||x>h||y>w||visited[x][y]) continue;
                if(grid[x][y]!='.'){
                    if(grid[x][y]==print){
                        q[c1].push({x,y});
                        visited[x][y] = 1;
                    }
                    else{
                        q[c2].push({x,y});
                        visited[x][y] = 1;
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
