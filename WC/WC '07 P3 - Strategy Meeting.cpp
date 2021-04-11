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
const ll MM = 20, mod = 13371337;
using namespace std;
int N, T, e, cnt, dp[1<<16][MM];
vector<int> v[MM];

int dfs(int mask, int cur){
    if(cur==N-1) return dp[mask][cur] = 1;
    if(dp[mask][cur]!=-1) return dp[mask][cur];
    int res = 0;
    for(auto && i : v[cur]){
        if(mask&(1<<i)) continue;
        res+=dfs(mask|(1<<i), i); res%=mod;
    }
    return dp[mask][cur] = res%mod;
}

int main()
{
    cin>>T;
    while(T--){
        cin>>N; ms(dp, -1);
        for(int i = 0; i < N; ++i){
            v[i].clear();
            for(int j = 0; j < N; ++j){
                cin>>e; if(e) v[i].pb(j);
            }
        }
        cout<<dfs(1, 0)<<endl;
    }
    return 0;
}
