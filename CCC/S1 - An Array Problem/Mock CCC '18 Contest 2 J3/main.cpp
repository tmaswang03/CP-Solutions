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
const ll MM = 60;
using namespace std;
ll a[MM], sum = 0, max1 = 0;
int main()
{
    ll N; scan(N);
    for(int i = 0; i < N; ++i){
        scan(a[i]);
        sum+=a[i]; max1 = max(max1, a[i]);
    }
    printf("%lld\n", min(sum-max1, sum/2));
    return 0;
}
