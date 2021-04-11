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
const ll MM = 250, MV = 1e6+10, MT = 1e3+10;
using namespace std;
// dp states : min capacity to have value j, first i items;
int dp[MM*MT], N, W, w, t, res;
int main()
{
    cin>>N>>W; ms(dp, 0x3f3f3f3f); dp[0] = 0;
    for(int i = 0; i < N; ++i){
        cin>>w>>t;
        for(int j = MM*MT-1; j >= t; --j){
            dp[j] = min(dp[j], dp[j-t]+w);
        }
    }
    for(int i = 1; i < MM*MT; ++i){
        if(dp[i]<W) continue;
        res = max(res, 1000*i/dp[i]);
    }
    cout<<res<<endl;
    return 0;
}
