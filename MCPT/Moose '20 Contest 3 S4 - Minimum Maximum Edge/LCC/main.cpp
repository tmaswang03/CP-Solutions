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
vector<int>v[MM]; int N, M, K, t = 0, st[MM], lo[MM], hed[MM], res, a, b, c, w;
bool vis[MM], in[MM]; stack<int>s;
void dfs(int n, int par){
    vis[n] = 1; st[n] = lo[n] = ++t;
    s.push(n); in[n] = 1;
    for(auto && i : v[n]){
        if(i==par) continue;
        if(!vis[i]){
            dfs(i, n);
            lo[n] = min(lo[n], lo[i]);
        }
        else if(in[i]) lo[n] = min(lo[n], st[i]);
    }
    if(lo[n]==st[n]){
        ++c;
        while(s.top()!=n){
            int i = s.top(); s.pop();
            in[i] = 0; hed[i] = c;
        }
        s.pop(); hed[n] = c; in[n] = 0;
    }
}
struct E{
    ll a, b, w, c;
};
bool cmp(E x, E y){
    return x.w < y.w;
}
vector<E> e;
int main()
{
    cin>>N>>M;
    for(int i = 0; i < M; ++i){
        cin>>a>>b>>w>>c; v[a].pb(b); v[b].pb(a);
        e.pb({a, b, w, c});
    }
    for(int i = 1; i <= N; ++i){
        if(!vis[i]) dfs(i, -1);
    }
    sort(e.begin(), e.end(), cmp);
    for(int i = 0; i < e.size(); ++i){
        if(hed[e[i].a]!=hed[e[i].b]){
            if(K){ res = max(res, e[i].w - e[i].c) --K;}
            else res = max(res, )
        }
    }
    return 0;
}
