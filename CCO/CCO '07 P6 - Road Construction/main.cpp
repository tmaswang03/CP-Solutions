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
const ll MM = 1e3+10;
using namespace std;
vector<int>v[MM]; int N, M, t = 0, st[MM], lo[MM], hed[MM], c=-1, a,b, arr[MM], res;
double ans = 0;
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
int main()
{
    scan(N); scan(M);
    for(int i = 0; i < M; ++i){
        scan(a); scan(b); v[a].pb(b); v[b].pb(a);
    }
    for(int i = 1; i <= N; ++i){
        if(!vis[i]) dfs(i, -1);
    }
    for(int i = 1; i <= N; ++i){
        for(auto && it : v[i]){
            if(hed[it]!=hed[i]) ++arr[hed[i]];
        }
    }
    for(int i = 0; i <= N; ++i){
        if(arr[i]==1) ++res;
    }
    res = ceil(1.0*res/2.0);
    printf("%d\n", res);
    return 0;
}
