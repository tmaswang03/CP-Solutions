#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 30, inf = 0x3f3f3f3f;
using namespace std;
string a[MM];
vector<int> v[MM];
int N, res, dp[MM][1<<20];
int dfs(int cur, ll mask){
    int ret = dp[cur][mask];
    if(ret!=-1) return ret;
    ret = 0;
    for(auto && i : v[cur]){
        if(mask&(1<<i)) continue;
        ret = max(ret, 1 + dfs(i, mask|(1<<i)));
    }
    return dp[cur][mask] = ret;
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i) cin>>a[i];
    for(int i = 0; i < N; ++i){
        for(int j  = 0; j < N; ++j){
            if(j==i) continue;
            if(a[j][0] == a[i][a[i].length()-1]) v[i].pb(j);
        }
    }
    ms(dp, -1);
    for(int i = 0; i < N; ++i){
        res = max(res, dfs(i, 1<<i));
    }
    cout<<1+res<<endl;
    return 0;
}
