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
const ll MM = 1e6+10;
using namespace std;
// sort range by increasing left order and decreasing right order
// each bit index holds the maximum dp value for r > value
// backtracking :
int N, bit[MM], dp[MM], pre[MM], fin = 0;
pair<int, int> a[MM];
void upd(int x, int val){
    for(int cur = x; cur<= MM; cur+=cur&-cur){
        if(dp[val]>=dp[bit[cur]]||bit[cur]==-1) bit[cur] = val;
    }
}
pair<int, int> query(int x){
    pair<int, int> res = mp(0, -1);
    for(int cur = x; cur > 0; cur-=cur&-cur){
        if(dp[bit[cur]] > res.f) res = mp(dp[bit[cur]], bit[cur]);
    }
    return res;
}
bool comp(pair<int, int> &a, pair<int, int> &b){
    if(a.f!=b.f) return a.f>b.f;
    return a.s<b.s;
}
int main()
{
    scan(N); ms(bit, -1); ms(dp, 0);
    for(int i = 0; i < N; ++i){
        scan(a[i].f); scan(a[i].s);
    }
    sort(a , a+N, comp);
    for(int i = 0; i < N; ++i){
        auto res = query(a[i].s);
        dp[i] = res.f+1;
        pre[i] = res.s;
        if(dp[i]>dp[fin]) fin = i;
        upd(a[i].s, i);
    }
    printf("%d\n", dp[fin]);
    while(fin!=-1){
        printf("%d %d\n", a[fin].f, a[fin].s);
        fin = pre[fin];
    }
    return 0;
}
