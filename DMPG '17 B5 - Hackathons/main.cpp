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
const ll MM = 1e6+10;
using namespace std;
int N, Q, dp[MM], t, w, T;
int main()
{
    boost();
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>t>>w;
        dp[t] = max(dp[t], w);
    }
    for(int i = 0; i < MM; ++i){
        dp[i] = max(dp[i], dp[i-1]);
    }
    cin>>Q;
    for(int i = 0; i < Q; ++i){
        cin>>T;
        cout<<dp[T]<<endl;
    }
    return 0;
}
