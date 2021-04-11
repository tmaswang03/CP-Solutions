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
char grid[MM][2*MM], c; int x, y = 0, N; bool vis[2*MM];
/*
^ pitch: replace the current character with /, and move the cursor one character to the right and one character up.
v pitch: move the cursor one character down, replace the current character with \, and move the cursor one character to the right.
> pitch: replace the current character with _, and move the cursor one character to the right.
*/
int main()
{
    cin>>N; y = N; ms(vis, 0);
    for(int i = 0; i <= 2*N+5; ++i){
        for(int j = 0; j <= N+5; ++j){
            grid[j][i] = '.';
        }
    }
    // column, row
    for(int i = 0; i < N; ++i){
        cin>>c;
        if(c=='^'){
           grid[x][y] = '/'; vis[y] = 1; ++x; --y;
        }
        else if(c=='v'){
            ++y; grid[x][y] = '\\'; vis[y] = 1; ++x;
        }
        else{
            vis[y] = 1; grid[x][y] = '_'; ++x;
        }
    }
    for(int i = 0; i <= 2*N+10; ++i){
        if(vis[i]){
            for(int j = 0; j < N; ++j){
                cout<<grid[j][i];
            }cout<<endl;
        }
    }
    return 0;
}
