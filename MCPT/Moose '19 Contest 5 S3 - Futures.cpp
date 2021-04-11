#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
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
const ll MM = 1e6+10, inf = 0x3f3f3f;
using namespace std;
ll dp[MM], N, K, p[MM], res = 0, prefm[MM];
int main()
{
    boost();
    cin>>N>>K; ms(prefm, -inf);
    for(int i = 1; i <= N; ++i){ cin>>p[i]; prefm[i] = max(prefm[i-1], -p[i]);}
    for(int l = 0; l < K; ++l){
        for(int i = 1; i <= N; ++i){
            dp[i] = prefm[i-1]+p[i]; res = max(dp[i], res); dp[i] = max(dp[i], dp[i-1]);
            prefm[i-1] = (i==1) ? max(-inf, -p[i]) : max(prefm[i-2], dp[i-2]-p[i-1]);
        }
        prefm[N] = max(prefm[N-1], dp[N-1]-p[N]);
    }
    cout<<res<<endl;
    return 0;
}
