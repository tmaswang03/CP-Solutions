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
const ll MM = 2001;
using namespace std;
int n,m,a,b, dp[MM], res = 0x3f3f3f3f;
int main()
{
    cin>>n>>m>>a>>b; ms(dp, 0x3f3f3f3f); dp[0] = 0;
    // 1 ride = a, m ride = b;
    for(int i = 1; i < MM; ++i){
        dp[i] = min(dp[i], dp[i-1]+a);
    }
    for(int i = m; i < MM; ++i){
        dp[i] = min(dp[i], dp[i-m]+b);
    }
    for(int i = n; i < MM; ++i){
        res = min(res, dp[i]);
    }
    cout<<res<<endl;
    return 0;
}
