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
const ll MM = 1e5+10;
using namespace std;
int N, M, a, b, lo[MM], st[MM], t;
bool vis[MM];
vector<int> v[MM], out;
// find articulation points
//  if lo[child] != dfn[par] && v has > 1 nodes it is articulation point
void dfs(int n, int par){
    vis[n] = 1; lo[n] = st[n] = ++t; int children = 0;
    for(auto && i : v[n]){
        if(i==par) continue;
        if(!vis[i]){
            ++children;
            dfs(i, n);
            if(st[n]<=lo[i] && par!=-1) out.pb(n);
            lo[n] = min(lo[i], lo[n]);
        }
        else lo[n] = min(lo[n], st[i]);
    }
    if(children>1&&par==-1) out.pb(n);
}
int main()
{
    scan(N); scan(M);
    for(int i = 0; i < M; ++i){
        scan(a); scan(b); v[a].pb(b); v[b].pb(a);
    }
    for(int i = 1; i <= N; ++i){
        if(!vis[i]) dfs(i, -1);
    }
    sort(out.begin(), out.end());
    auto last = unique(out.begin(),out.end());
    out.erase(last,out.end());
    cout<<out.size()<<endl;
    for(auto && i : out) cout<<i<<endl;
    return 0;
}
