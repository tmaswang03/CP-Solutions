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
const ll MM = 1e2+10;
using namespace std;
int N, a, b, st, dpth[MM], res; vector<int> v[MM]; bool inq[MM];
void dfs(int cur,int lvl){
    inq[cur] = 1; dpth[cur] = lvl;
    for(auto && i : v[cur]){
        if(inq[i]){ res = dpth[cur] - dpth[i] + 1; continue;}
        dfs(i, lvl+1);
    }
    inq[cur] = 0;
}
int main()
{
    for(int t = 0; t < 5; ++t){
        cin>>N;
        for(int i = 0; i < N; ++i){
            cin>>a>>b; v[a].pb(b); if(!i) st = a;
        }
        dfs(st, 0);
        cout<<res<<"\n";
        for(int i = 1; i <= N; ++i) v[i].clear();
    }
    return 0;
}
