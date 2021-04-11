#include<bits/stdc++.h>
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
const ll MM =
using namespace std;
struct shp{
    int c,s,p;
};
shp a[26];
int main()
{
    int C,S,P,N; scan(C); scan(S); scan(P); scan(N);
    for(int i = 0; i < N; ++i){
        scan(a[i].c); scan(a[i].s); scan(a[i].p);
    }
    return 0;
}
