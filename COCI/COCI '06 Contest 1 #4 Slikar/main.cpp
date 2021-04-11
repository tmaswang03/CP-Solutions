#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 53, inf = 0x3f3f3f3f;
using namespace std;
char grid[MM][MM];
int ovfw [MM][MM], dst[MM][MM];
struct flow{
    int x,y,tm;
};
int main()
{
    int R, C, stx, sty, bx, by; cin>>R>>C; ms(ovfw , inf); ms(dst, inf);
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            cin>>grid[i][j];
            if(grid[i][j]=='S'){
                stx = i; sty = j;
            }
            else if(grid[i][j]=='D'){
                bx = i; by = j;
            }
        }
    }
    queue<flow>q;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(grid[i][j] == '*'){
                ovfw[i][j] = 0;
                q.push({i,j,0});
            }
            else if(grid[i][j] == 'X'){
                ovfw[i][j] = 0;
            }
        }
    }
    ovfw[bx][by] = inf-1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i = cur.x-1; i <= cur.x+1; ++i){
            for(int j = cur.y-1; j <= cur.y+1; ++j){
                if( (i==cur.x||j==cur.y) && ovfw[i][j]==inf && cur.x>=0 && cur.y>=0 && cur.x<R && cur.y<C){
                    ovfw[i][j] = cur.tm+1;
                    q.push({i,j,cur.tm+1});
                }
            }
        }
    }
    q.push({stx,sty,0}); dst[stx][sty] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i = cur.x-1; i <= cur.x+1; ++i){
            for(int j = cur.y-1; j <= cur.y+1; ++j){
                if((i==cur.x||j==cur.y) && ovfw[i][j]>cur.tm+1 && cur.x>=0 && cur.y>=0 && cur.x<R && cur.y<C){
                    if(dst[i][j]>cur.tm+1){
                        dst[i][j] = cur.tm+1;
                        q.push({i,j,cur.tm+1});
                    }
                }
            }
        }
    }
    if(dst[bx][by]==inf) cout<<"KAKTUS"<<endl;
    else cout<<dst[bx][by]<<endl;
    return 0;
}
