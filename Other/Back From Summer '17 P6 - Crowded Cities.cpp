#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MM = 1e5+10, ML = 5e3+10;
struct t{
    int l,w,h,p,i;
    bool operator <(const t &o){
        return mt(l,w,h)<mt(o.l, o.w, o.h);
    }
};
ll dp[MM], bit[ML][ML], pre[MM], rep1 = 0, rep2 = 0, cnt = 0, N; t a[MM];
void upd(int x, int y, int v){
    for(int x1 = x; x1 <= ML-10; x1+=x1&-x1){
        for(int y1 = y; y1<= ML-10; y1+=y1&-y1){
            if(dp[v]>dp[bit[x1][y1]]) bit[x1][y1] = v;
        }
    }
}

ll query(int x, int y){
    int res = -1;
    for(int x1 = x; x1 > 0; x1-=x1&-x1){
        for(int y1 = y; y1 > 0; y1-=y1&-y1){
            if( (res==-1&&dp[bit[x1][y1]])||dp[res]<dp[bit[x1][y1]]) res = bit[x1][y1];
        }
    }
    return res;
}

int main()
{
    scan(N);  ms(bit, 0); ms(dp, 0);
    for(int i = 1; i <= N; ++i){
        scana(a[i].l, a[i].w, a[i].h, a[i].p); a[i].i = i;
        if(a[i].l < a[i].w) swap(a[i].l, a[i].w);
    }
    sort(a+1, a+N+1);
    for(int i = 1; i <= N; ++i){
        pre[i] = query(a[i].w, a[i].h);
        if(pre[i]==-1) dp[i] = a[i].p;
        else dp[i] = dp[pre[i]]+a[i].p;
        upd(a[i].w, a[i].h, i);
        if(dp[i]>dp[rep1]) rep1 = i;
    }
    printf("%lld\n", dp[rep1]); rep2 = rep1;
    for(; rep1!=-1; rep1 = pre[rep1]) ++cnt;
    printf("%lld\n", cnt);
    for(; rep2!=-1; rep2 = pre[rep2]) printf("%lld ", a[rep2].i);
    return 0;
}
