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
const ll MM = 2e6+10;
using namespace std;
bool inc = 0;
int N, a[MM], res = 2, dp[MM][2];
int main()
{
    scan(N);
    for(int i = 0; i < N; ++i){
        scan(a[i]);
    }
    if(a[1]>a[0]) inc = 1;
    for(int i = 2; i < N; ++i){
        if(a[i]<a[i-1] && inc){
            ++res;
            inc = 0;
        }
        else if(a[i]>a[i-1] && !inc){
            ++res;
            inc = 1;
        }
    }
    printf("%lld\n", res);
    return 0;
}
