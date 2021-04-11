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
const ll MM = 3e3+50;
using namespace std;
ll bit[MM][MM], a[MM][MM], N, K, res =  0;
void upd(int x, int y, ll val){
    for(int x1 = x; x1 <= N; x1+=x1&-x1){
        for(int y1 = y; y1 <= N; y1+=y1&-y1){
            bit[x1][y1] = max(bit[x1][y1],  val);
        }
    }
}
ll query(int x, int y){
    ll res =  0;
    for(int x1 = x; x1 > 0; x1-=x1&-x1){
        for(int y1 = y; y1 > 0; y1-=y1&-y1){
            res = max(bit[x1][y1],  res);
        }
    }
    return res;
}
int main()
{
    cin>>N>>K; ms(a,0);
    for(int i = 1; i <= N; ++i){
        for(int j = N-i+1; j <= N; ++j){
            scan(a[i][j]);
        }
    }
    for(int cur = N; cur >= 1; --cur){
        int x = N, y = cur;
        while(x<=N&&y<=N){
            upd(y, x, a[y][x]);
            if(y>=cur+K-1){
                res+=query(y, x+K-1);
            }
            --x; ++y;
        }
    }
    printf("%lld\n", res);
    return 0;
}
