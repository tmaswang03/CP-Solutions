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
const ll MM = 2e5+10;
using namespace std;
int sz[MM], N, par; vector<int>v[MM];
int dfs(int cur){
    int res = 0;
    for(auto && i : v[cur]){
        res+=1+dfs(i);
    }
    return sz[cur] = res;
}
int main()
{
    cin>>N;
    for(int i = 2; i <= N; ++i){
        cin>>par; v[par].pb(i);
    }
    dfs(1);
    for(int i = 1; i <= N; ++i) cout<<sz[i]<<" ";
    return 0;
}
