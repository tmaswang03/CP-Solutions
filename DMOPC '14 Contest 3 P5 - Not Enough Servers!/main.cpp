#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define mt make_tuple
#define push_back pb
#define boost() cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
char _;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll  MM = 60, MN =  30, inf = 0x3f3f3f3f;
using namespace std;
int N,M;
bool a[MN][MM];  // 1 = ac, 0 = wa
ll test[MM]; // holds the ppl test case i was
long long dp[1<<21]; //dp holds the subset of ppl that are to be wad,
long long backtrack[1<<21], val[1<<21];
int main()
{
    boost();
    cin>>N>>M; ms(dp, inf) dp[0] = 0; ms(test, 0);
    for(int i = 0; i < N; ++i){
        bool ac = 1;
        for(int j =  0; j < M; ++j){
            char c; cin>>c;
            if(c=='O') a[i][j]  = 1;
            else ac = 0;
        }
        if(ac){
            for(int j = 0; j < M; ++j) a[i][j] = 0;
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(!(a[i][j])) test[j]|=1<<i;
        }
    }
    for(int i = 0; i < 1<<N; ++i){
        for(int j = 0; j < M; ++j){
            if(dp[i|test[j]]>dp[i]+1){
                val[i|test[j]] = j;
                backtrack[i|test[j]] = i;
                dp[i|test[j]] = dp[i]+1;
            }
        }
    }
    cout<<dp[(1<<N)-1]<<endl;
    int cur = (1<<N)-1;
    while(backtrack[cur]!=0){
        cout<<val[cur]+1<<" ";  cur = backtrack[cur];
    }
    cout<<val[cur]+1<<endl;
    return 0;
}
