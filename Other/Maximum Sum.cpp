#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
const ll MM = 1e5+10;
using namespace std;
int a[MM], dp[MM];
int main()
{
    int N; cin>>N;
    for(int i = 1; i <= N; ++i){
        cin>>a[i];
    }
    for(int i = 1; i <= N; ++i){
        dp[i] = max(dp[i-1], dp[i-2]+a[i]);
    }
    cout<<dp[N]<<endl;
    return 0;
}
