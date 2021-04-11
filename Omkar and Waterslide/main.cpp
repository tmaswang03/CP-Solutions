#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e5+10;
using namespace std;
ll a[MM];

int main()
{
    int t; scan(t);
    while(t--){
        ll n, res = 0; scan(n);
        for(int i = 0; i < n; ++i) scan(a[i]);
        for(int i = 1; i < n; ++i){
            if(a[i-1]>a[i]) res+=a[i-1]-a[i];
        }
        printf("%d\n", res);
    }
    return 0;
}
