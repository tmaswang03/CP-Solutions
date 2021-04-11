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
const ll MM = 5e5+10;
using namespace std;
struct edge{ int nxt, to;};
int N, M, t,res, a,b,p, c = -1, cur = -1,  strt, st[MM], lo[MM], hed[MM], csh2[MM], dp[MM]; short csh[MM];
int h1[MM], h2[MM]; edge e1[MM], e2[MM];
bool vis[MM],  in[MM], pub[MM]; stack<int>s;
void dfs(int n){
    vis[n] = 1; st[n] = lo[n] = ++t;
    s.push(n); in[n] = 1;
    for(int i = h1[n]; i!=-1; i = e1[i].nxt){
        if(!vis[e1[i].to]){
            dfs(e1[i].to);
            lo[n] = min(lo[n], lo[e1[i].to]);
        }
        else if(in[e1[i].to]) lo[n] = min(lo[n], st[e1[i].to]);
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
int dfs2(int n){
    if(dp[n]!=-1) return dp[n];
    int val=pub[n] ? csh2[n] : 0;
    for(int i = h2[n]; i!=-1; i = e2[i].nxt){
        if(dfs2(e2[i].to)!=0) val = max(val, dfs2(e2[i].to)+csh2[n]);
    }
    return dp[n] = val;
}

int main()
{
    scan(N); scan(M); ms(dp, -1); ms(h1, -1); ms(h2, -1);
    for(int i = 0; i < M; ++i){
        scan(a); scan(b); --a; --b;
        e1[++cur].to = b; e1[cur].nxt = h1[a]; h1[a] = cur;
    }
    for(int i = 0; i < N; ++i){
        if(!vis[i]) dfs(i);
    }
    cur = -1;
    for(int i = 0; i < N; ++i) scan(csh[i]);
    for(int i = 0; i < N; ++i){
        csh2[hed[i]]+=csh[i];
        for(int j = h1[i]; j!=-1; j = e1[j].nxt){
            if(hed[e1[j].to]!=hed[i]){
                e2[++cur].to = hed[e1[j].to]; e2[cur].nxt = h2[hed[i]]; h2[hed[i]] = cur;
            }
        }
    }
    scan(strt); scan(p); --strt;
    for(int i = 0; i < p; ++i){
        scan(a); --a;
        pub[hed[a]] = 1;
    }
    res = dfs2(hed[strt]);
    cout<<res<<endl;
    return 0;
}
