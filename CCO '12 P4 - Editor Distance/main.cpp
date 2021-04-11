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
const ll MM = 90, MN = 1e5+10, inf = 0x3f3f3f3f;
using namespace std;
int a[MM], dst[MN][MM];
struct coord{
    int x,y;
};
int main()
{
    int N, xs, ys, xe, ye; scan(N); ms(dst, inf);
    for(int i = 1; i <= N; ++i){
        scan(a[i]);
    }
    scan(xs); scan(ys); scan(xe); scan(ye);
    dst[xs][ys] = 0;
    queue<coord>q;
    q.push({xs,ys});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        // opt right;
        if(cur.y+1 <= a[cur.x] && dst[cur.x][cur.y+1]>dst[cur.x][cur.y]+1){
            dst[cur.x][cur.y+1] = dst[cur.x][cur.y]+1;
            q.push({cur.x, cur.y+1});
        }
        else if(cur.y+1 > a[cur.x] && cur.x + 1 <= N && dst[cur.x+1][1]>dst[cur.x][cur.y]+1){
            dst[cur.x+1][1] = dst[cur.x][cur.y]+1;
            q.push({cur.x+1, 1});
        }
        if(cur.y-1 >= 1 && dst[cur.x][cur.y-1]>dst[cur.x][cur.y]+1){
            dst[cur.x][cur.y-1] = dst[cur.x][cur.y]+1;
            q.push({cur.x, cur.y-1});
        }
        else if(cur.y-1 < 1 && cur.x - 1 >= 1 && dst[cur.x-1][a[cur.x-1]]>dst[cur.x][cur.y]+1){
            dst[cur.x-1][a[cur.x-1]]=dst[cur.x][cur.y]+1;
            q.push({cur.x-1, a[cur.x-1]});
        }

        if(cur.x-1 >= 1 && cur.y <= a[cur.x-1] && dst[cur.x-1][cur.y]>dst[cur.x][cur.y]+1){
            dst[cur.x-1][cur.y] = dst[cur.x][cur.y]+1;
            q.push({cur.x-1, cur.y});
        }
        else if(cur.x - 1 >= 1 && cur.y > a[cur.x-1] && dst[cur.x-1][a[cur.x-1]]>dst[cur.x][cur.y]+1){
            dst[cur.x-1][a[cur.x-1]]=dst[cur.x][cur.y]+1;
            q.push({cur.x-1, a[cur.x-1]});
        }

        if(cur.x+1 <= N && cur.y <= a[cur.x+1] && dst[cur.x+1][cur.y]>dst[cur.x][cur.y]+1){
            dst[cur.x+1][cur.y] = dst[cur.x][cur.y]+1;
            q.push({cur.x+1, cur.y});
        }
        else if(cur.x + 1 <= N && cur.y > a[cur.x+1] && dst[cur.x+1][a[cur.x+1]]>dst[cur.x][cur.y]+1){
            dst[cur.x+1][a[cur.x+1]] = dst[cur.x][cur.y]+1;
            q.push({cur.x+1, a[cur.x+1]});
        }
    }
    cout<<dst[xe][ye]<<endl;
    return 0;
}
