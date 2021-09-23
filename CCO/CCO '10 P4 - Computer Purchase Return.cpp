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
const ll MM = 1e3+10, MN = 3e3+10;
using namespace std;
ll T, B, N, dp[MN][5], dpu[MN][5], x, y, z; vector<pii> t[6];
ll dfs(int cur, int left){
    if(left < 0) return -0x3f3f3f;
    if(cur==6 && left >= 0) return 0;
    if(dpu[left][cur] != -1) return dpu[left][cur];
    dpu[left][cur] = 0;
    for(auto && i : t[cur]){
        if(i.f > left) continue;
        dpu[left][cur] = max(dpu[left][cur], dfs(cur+1, left - i.f) + i.s);
    }
    return dpu[left][cur];
}
int main()
{
    cin>>T>>N;
    for(int i = 0; i < N; ++i){
        cin>>x>>y>>z; t[z].pb({x, y});
    }
    cin>>B; ms(dpu, -1);
    if(dfs(1, B) != 0) cout<<dfs(1, B)<<endl;
    else cout<<-1<<endl;
    return 0;
}