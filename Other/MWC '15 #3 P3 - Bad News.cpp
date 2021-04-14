#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
const ll MAXN = 30;
using namespace std;
char cw[MAXN][MAXN];
pair<int, int> dir[9]; //x,y
string s; int N,Q;
bool searchw(int pos, bool visited[][30], int x, int y){
    //dir 1 = tl, 2 = up, 3 = tr, 4 = lft, 5 = right, 6 = bl, 7 = down, 8 = br
    if(pos==s.length()) return 1;
    for(int d = 1; d <= 8; ++d){
        int nx = x+dir[d].f, ny = y+dir[d].s;
        if(nx>= 0 && nx < N && ny>= 0 && ny < N && !visited[nx][ny] && cw[nx][ny]==s[pos] && pos<s.length()){
            visited[nx][ny] = 1;
            if(searchw(pos+1, visited, nx, ny)){
                return 1;
            }
            visited[nx][ny] = 0;
        }
    }
    return 0;
}
bool searchf(){
    bool visited[MAXN][MAXN]; ms(visited, 0);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(cw[i][j]==s[0]){
                visited[i][j] = 1;
                if(searchw(1, visited,  i, j)){
                    return 1;
                }
                visited[i][j] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    dir[1] = mp(-1,-1);  dir[2] = mp(0,-1); dir[3] = mp(1,-1); dir[4] = mp(-1,0); dir[5] = mp(1,0);
    dir[6] = mp(-1,1); dir[7] = mp(0,1); dir[8] = mp(1,1);
    cin>>N>>Q;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin>>cw[i][j];
        }
    }
    for(int i = 0; i < Q; ++i){
        cin>>s; bool temp = searchf();
        printf(temp ? "good puzzle!\n" : "bad puzzle!\n");
    }
    return 0;
}
