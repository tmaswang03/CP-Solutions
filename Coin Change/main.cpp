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
#define pii pair<int, int>
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e3+10;
using namespace std;
int X, N, C, dp[MM];

int main()
{
    cin>>X>>N; ms(dp, 0x3f3f3f3f); dp[0] = 0;
    while(N--){
        cin>>C;
        for(int i = C; i <= X; ++i){
            dp[i] = min(dp[i], dp[i-C]+1);
        }
    }
    cout<<dp[X];
    return 0;
}
