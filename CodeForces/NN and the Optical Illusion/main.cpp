#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace std;
// angle = 2*atan(r/(r+R))

int main()
{
    int r, n;
    double lo = 0, hi = 10000, mid;
    scan(n); scan(r);
    while(hi > lo+0.00000001){
        mid = (lo+hi)/2; //smaller radius
        if(3.14159/atan(mid+1.0*r)<n) hi = mid;
        else lo = mid;
    }
    cout<<setprecision(8)<<mid<<endl;
    return 0;
}
