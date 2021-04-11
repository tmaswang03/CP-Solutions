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
#define eb emplace_back
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10, MN = 4*MM, inf = 1e9;
using namespace std;
ll a[MM], bit[MN][2], N, Q, k, l, r, lft[MM], rt[MM]; vector<ll> v; pii t[20][MM];
int gett(int x){ return lower_bound(v.begin(), v.end(), x)-v.begin()+1;}
int lg2(int x){ return 31 - __builtin_clz(x);}
void upd(ll x, int v, bool b){
    for(; x<MN; x+=x&-x) bit[x][b] = v;
}
ll query1(int x, bool b){
    ll res = 0;
    for(; x > 0; x-=x&-x){
        res = max(res, bit[x][b]);
    }
    return res;
}
ll query2(int x, bool b){
    ll res = N+1;
    for(; x > 0; x-=x&-x){
        res = min(res, bit[x][b]);
    }
    return res;
}
pii rmq(int l, int r){
    int sz = lg2(r-l+1); pii res1 = t[sz][l], res2 = t[sz][r-(1<<sz)+1];
    if(res1.f==res2.f){
        if(res1.s<res2.s) return res1;
        else return res2;
    }
    if(res1.f>res2.f) return res1;
    return res2;
}
int main()
{
    scana(N, k);
    for(int i = 1; i <= N; ++i){ scan(a[i]); v.eb(a[i]); v.eb(a[i]+k); v.eb(a[i]-k);}
    sort(v.begin(), v.end());
    for(int i = 1; i <= N; ++i){
        lft[i] = min(lft[i-1]+1, i-query1(gett(a[i]-k)-1, 0));
        lft[i] = min(lft[i], i-query1(MN-gett(a[i]+k)-1, 1)); ll pt = gett(a[i]);
        upd(pt, i, 0); upd(MN-pt, i, 1);
    }
    ms(bit, 0x3f3f3f3f);
    for(int i = N; i >= 1; --i){
        rt[i] = min(rt[i+1]+1, query2(gett(a[i]-k)-1, 0)-i);
        rt[i] = min(rt[i], query2(MN-gett(a[i]+k)-1, 1)-i);
        ll pt = gett(a[i]);
        upd(pt, i, 0); upd(MN-pt, i, 1);
        t[0][i] = {rt[i], i};
    }
    for(int i = 1; i < 20; ++i){
        for(int j = 1; j <= N-(1<<i); ++j){
            pii res1 = t[i-1][j], res2 = t[i-1][j+(1<<(i-1))];
            if(res1.f==res2.f){
                if(res1.s<res2.s) t[i][j] = res1;
                else t[i][j] = res2;
            }
            else if(res1.f<res2.f) t[i][j] = res2;
            else t[i][j] = res1;
        }
    }
    scan(Q);
    while(Q--){
        scana(l, r);
        if(lft[r]>=r-l+1) printf("%d %d\n", l, r);
        else{
            pii res = rmq(l, r-lft[r]);
            if(lft[r]>res.f){
                printf("%d %d\n", r-lft[r]+1, r);
            }
            else printf("%d %d\n", res.s, res.s+res.f-1);
        }
    }
    return 0;
}
