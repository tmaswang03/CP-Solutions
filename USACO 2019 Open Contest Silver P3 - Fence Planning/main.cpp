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
const ll MM = 1e5+10, inf = 1e9;
using namespace std;
int rnk[MM], hed[MM], N, M, x, y, res = inf;
struct rect{
    int bx, by, tx, ty;
}r[MM];
int gett(int x){ return hed[x] == x ? x : hed[x] = gett(hed[x]); }
void join(int x, int y){
    x = gett(x); y = gett(y);
    if(rnk[x]<rnk[y]) swap(x, y);
    r[x].bx = min(r[x].bx, r[y].bx);
    r[x].by = min(r[x].by, r[y].by);
    r[x].tx = max(r[x].tx, r[y].tx);
    r[x].ty = max(r[x].ty, r[y].ty);
    hed[y] = x; rnk[x]+=rnk[y];
}
int calc(int x){
    x = gett(x);
    return (r[x].tx-r[x].bx+r[x].ty-r[x].by);
}
int main()
{
    cin>>N>>M;
    for(int i = 1; i <= N; ++i){
        cin>>r[i].bx>>r[i].by; r[i].tx=r[i].bx, r[i].ty=r[i].by;
        hed[i] = i; rnk[i] = 1;
    }
    while(M--){
        cin>>x>>y; join(x, y);
    }
    for(int i = 1; i <= N; ++i){
        res = min(res, calc(i));
    }
    cout<<2*res<<endl;
    return 0;
}
