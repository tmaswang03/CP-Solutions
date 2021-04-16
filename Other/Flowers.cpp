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
const ll MM = 2e5+10;
using namespace std;
ll dp[MM], h[MM], b[MM], N, bit[MM], res;
void upd (int x, int v){
    for(; x<= N; x+=x&-x){
        if(dp[v]>dp[bit[x]]) bit[x] = v;
    }
}
ll query(int x){
    ll cur = 0;
    for(; x; x-=x&-x){
        cur = max(cur, dp[bit[x]]);
    }
    return cur;
}

int main()
{
    scan(N); ms(bit, -1);
    for(int i = 0; i < N; ++i) scan(h[i]);
    for(int i = 0; i < N; ++i) scan(b[i]);
    for(int i = 0; i < N; ++i){
        dp[i] = query(h[i]-1); dp[i]+=b[i];
        upd(h[i], i);
        res = max(res, dp[i]);
    }
    cout<<res<<endl;
    return 0;
}
