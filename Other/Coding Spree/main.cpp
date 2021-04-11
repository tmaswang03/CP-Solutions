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
const ll MM = 1e3+10;
using namespace std;
ll dp[MM], N, T, V, H;
int main()
{
    scan(N); scan(T);
    while(N--){
        scan(V); scan(H);
        for(int i = T; i >= H; --i){
            dp[i]  = max(dp[i], dp[i-H]+V);
        }
    }
    cout<<dp[T]<<endl;
    return 0;
}
