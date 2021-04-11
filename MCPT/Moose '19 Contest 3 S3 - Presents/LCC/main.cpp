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
const ll MM = 5e5+10;
using namespace std;
ll a[MM], N, psa[MM], dp[MM], res = 0;
int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    sort(a+1, a+N+1);
    for(int i = 1; i <= N; ++i) psa[i] = psa[i-1]+a[i];
    for(int i = 1; i <= N; ++i){
        dp[i] = max(a[i]-dp[i-1], dp[i-1]);
    }
    cout<<dp[N]<<endl;
    return 0;
}
