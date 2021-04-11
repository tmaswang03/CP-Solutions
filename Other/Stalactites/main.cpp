#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
const ll MM = 252;
using namespace std;
int a[MM][MM][MM], N, Q;
ll sum = 0, bit[MM][MM][MM];
char opt;
void upd(int x, int y, int z, int l){
    for(int x1 = x; x1 < MM; x1+=x1&-x1){
        for(int y1 = y; y1 < MM; y1+=y1&-y1){
            for(int z1 = z; z1 < MM; z1+=z1&-z1){
                bit[x1][y1][z1]+=l;
            }
        }
    }
}
ll que(int x, int y, int z){
    ll ret = 0;
    for(int x1 = x; x1 > 0; x1-=x1&-x1){
        for(int y1 = y; y1 > 0; y1-=y1&-y1){
            for(int z1 = z; z1 > 0; z1-=z1&-z1){
                ret+=bit[x1][y1][z1];
            }
        }
    }
    return ret;
}

ll querypris(int x1, int x2, int y1, int y2, int z1, int z2){
    return que(x2, y1-1, z1-1) + que(x1-1, y2, z1-1) + que(x1-1, y1 - 1, z2) + que(x2, y2, z2)
                - que(x1-1, y2, z2)- que(x2, y1-1, z2) - que(x1-1, y1-1, z1-1) - que(x2, y2, z1-1);
}

int main()
{
    scan(N); scan(Q); ms(bit, 0); ms(a, 0);
    while(Q--){
        scanf("%c", &opt);
        if(opt=='C'){
            int x,y,z,l; scana(x, y, z, l);
            int diff = l-a[x][y][z]; a[x][y][z] = l;
            upd(x,y,z,diff);
        }
        else{
            int x1, y1, z1, x2, y2, z2; scana(x1, y1, z1, x2, y2, z2);
            sum+=querypris(x1, x2, y1, y2, z1, z2);
        }
    }
    printf("%lld\n", sum);
    return 0;
}
