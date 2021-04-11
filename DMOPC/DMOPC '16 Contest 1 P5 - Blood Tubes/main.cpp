#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
const ll MM = 5e5+20, MN = 5e5+10;
using namespace std;
ll bit[MM], N, res = 0;
ll query (ll cur) {
    ll ret = 0;
    for (cur++;cur>0;cur-=(cur&-cur)) ret += bit[cur];
    return ret;
}
void upd (ll cur, ll v){
    for (cur++;cur<=MN;cur+=(cur&-cur)) bit[cur] += v;
}
int main()
{
    scan(N); ms(bit, 0);
    for(int i = 0; i < N; ++i){
        int val; scan(val);
        // count inversions, if put in front inversions = number of needles <
        // if back inversions = number of needles >
        res+=min(query(val-1), query(N)-query(val));
        upd(val, 1);
    }
    printf("%lld\n", res);
    return 0;
}
