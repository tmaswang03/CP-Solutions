
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
const ll MM = 1e5+10;
using namespace std;
ll a[MM];
int main()
{
    ll n, res = 0, cur = 1, prev = 0x3f3f3f3f3f3f3f; scan(n);
    for(int i = 0; i < n; ++i){
        scan(a[i]);
    }
    sort(a, a+n);
    for(;;){
        ll po = 1, diff = 0;
        for(int i = 0; i < n; ++i){
            diff += abs(po - a[i]);
            po*=cur;
        }
        if(diff > prev) break;
        prev = diff;
        ++cur;
    }
    printf("%lld\n", prev);
    return 0;
}
