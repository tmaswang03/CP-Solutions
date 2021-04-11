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
const ll MM = 20;
using namespace std;
int N, M, dp[15][MM], c, d, q;
int main()
{
    cin>>N>>M; ms(dp, 0x3f3f3f3f);
    for(int i = 0; i < N; ++i){
        dp[i][0] = 0;
        cin>>c;
        for(int j = 1; j <= 10; ++j) dp[i][j] = min(dp[i][j], dp[i][j-1]+c);
    }
    for(int i = 0; i < M; ++i){
        cin>>d>>q;
    }
    return 0;
}
