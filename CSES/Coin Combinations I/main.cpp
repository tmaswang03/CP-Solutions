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
const ll MM = 1e6+10, MOD = 1e9+7;
using namespace std;
ll dp[MM], N, X, c; vector<int> v;
int main()
{
    dp[0] = 1;
    cin>>N>>X;
    while(N--){
        cin>>c;
        v.pb(c);
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= X; ++i){
        for(auto && j : v){
            if(j>i) break;
            dp[i] = (dp[i]+dp[i-j])%MOD;
        }
    }
    cout<<dp[X]<<endl;
    return 0;
}