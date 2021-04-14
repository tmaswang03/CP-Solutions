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
const ll MM = 1e6+1;
using namespace std;
struct edge{
    int nxt, to; //nxt = last added edge, to = next node;
};
int N, M, t = 0, st[MM], lo[MM], c=-1, a,b, freq[MM], hed[MM], cur = -1; ll tot; double res; edge e[2*MM];
bool vis[MM], in[MM]; stack<int>s;
ll calc(ll n){return n*(n-1)/2;}
void dfs(int n, int par){
    vis[n] = 1; st[n] = lo[n] = ++t;
    s.push(n); in[n] = 1;
    for(int i = hed[n]; i; i = e[i].nxt){
        if(e[i].to==par) continue;
        if(!vis[e[i].to]){
            dfs(e[i].to, n);
            lo[n] = min(lo[n], lo[e[i].to]);
        }
        else if(in[e[i].to]) lo[n] = min(lo[n], st[e[i].to]);
    }
    if(lo[n]==st[n]){
        ++c;
        while(s.top()!=n){
            int i = s.top(); s.pop();
            in[i] = 0; ++freq[c];
        }
        s.pop(); ++freq[c]; in[n] = 0;
    }
}
int main()
{
    scan(N); scan(M);
    for(int i = 0; i < M; ++i){
        scan(a); scan(b);
        ++cur;
        e[cur].to = b; e[cur].nxt = hed[a]; hed[a] = cur;
        ++cur;
        e[cur].to = a; e[cur].nxt = hed[b]; hed[b] = cur;
    }
    for(int i = 1; i <= N; ++i){
        if(!vis[i]) dfs(i, -1);
    }
    for(int i = 0; i <= c; ++i) tot+=calc(freq[i]);
    res = 1.0*tot/(1.0*calc(N));
    res = 1.0-res;
    cout<<fixed<<setprecision(5)<<res<<endl;
    return 0;
}
