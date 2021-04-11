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
const ll MM = 1e6+10;
using namespace std;
ll N, M, t = 0, st[MM], lo[MM], c=-1, a,b,p, hed[MM], csh[MM], csh2[MM], res = 0, S, E, dp[MM];
vector<ll> v[MM], sv[MM];
bool vis[MM],  in[MM]; stack<ll>s;
void dfs(int n){
    vis[n] = 1; st[n] = lo[n] = ++t;
    s.push(n); in[n] = 1;
    for(auto && i : v[n]){
        if(!vis[i]){
            dfs(i);
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
ll dfs2(int n){
    if(dp[n]!=-1) return dp[n];
    ll val= n==hed[E] ? csh2[n] : 0;
    for(auto && i : sv[n]){
        if(dfs2(i)!=0) val = max(val, dfs2(i)+csh2[n]);
    }
    return dp[n] = val;
}

int main()
{
    scana(N, M, S, E); ms(dp, -1); --S; --E;
    for(int i = 0; i < N; ++i) scan(csh[i]);
    for(int i = 0; i < M; ++i){
        scan(a); scan(b); --a; --b;
        v[a].pb(b);
    }
    for(int i = 0; i < N; ++i){
        if(!vis[i]) dfs(i);
    }
    for(int i = 0; i < N; ++i){
        csh2[hed[i]]+=csh[i];
        for(auto && j : v[i]){
            if(hed[j]!=hed[i]) sv[hed[i]].pb(hed[j]);
        }
    }
    res = dfs2(hed[S]);
    cout<<res<<endl;
    return 0;
}
