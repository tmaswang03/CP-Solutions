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
const ll MM = 1e3+10;
using namespace std;
struct ch{int x,y,l,w,ra,alt;};
int psa[MM][MM], R, C, L, W, H, opt, resx = 1, resy = 1, tx, ty, tx1, ty1; ch a[MM];
// ra = 1 = vertical, 0 = horizontal
// alt = 1 =  <= first, 0 = > first
// idea : loop through all possible top left top right, keep counter of each
int query(int x1, int y1, int x2, int y2){
    return psa[x2][y2]-psa[x2][y1-1]-psa[x1-1][y2]+psa[x1-1][y1-1];
}
int main()
{
    scana(R, C);
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            scan(psa[i][j]); psa[i][j]+=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }
    scana(L, W, H);
    for(int i = 0; i < H; ++i){
        scana(a[i].x, a[i].y, a[i].l, a[i].w, a[i].ra, a[i].alt);
    }
    for(int x = 1; x <= R-L+1; ++x){
        for(int y = 1; y <= C-W+1; ++y){
            int val = 0;
            for(int i = 0; i < H; ++i){
                if(H-i+val < opt) break;
                tx = x+a[i].x-1; ty = y+a[i].y-1; tx1 = tx+a[i].l-1; ty1 = ty+a[i].w-1;
                if(a[i].ra){
                    if(a[i].alt) val+= query(tx, ty, tx1, ty1) >= query(tx1+1, ty, tx1+a[i].l, ty1);
                    else val+= query(tx, ty, tx1, ty1) < query(tx1+1, ty, tx1+a[i].l, ty1);
                }
                else{
                    if(a[i].alt) val+= query(tx, ty, tx1, ty1) >= query(tx, ty1+1, tx1, ty1+a[i].w);
                    else val+= query(tx, ty, tx1, ty1) < query(tx, ty1+1, tx1, ty1+a[i].w);
                }
            }
            if(val>opt){
                opt = val;
                resx = x, resy = y;
            }
        }
    }
    printf("%d %d", resx, resy);
    return 0;
}
