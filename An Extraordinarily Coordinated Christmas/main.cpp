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
const ll MM = 1e5+10;
using namespace std;
ll dst[MM][2], par[MM][2], N, Q, a, b, w; vector<pii> v[MM];
void shft(int cur, int n, int p){
    dst[cur][1] = dst[cur][0], par[cur][1] = par[cur][0];
    dst[cur][0] = n; par[cur][0] = p;
}
ll dfs(int cur, int p){
    if(dst[cur][0]!=-1 && par[cur][0]!=p) return dst[cur][0];
    if(dst[cur][1]!=-1) return dst[cur][1];
    dst[cur][1] = dst[cur][0] = 0;
    for(auto && i : v[cur]){
        if(i.f==p) continue;
        ll tmp = dfs(i.f, cur) + i.s;
        if(tmp>dst[cur][0]) shft(cur, tmp, i.f);
        else if(tmp>dst[cur][1]){
            dst[cur][1] = tmp; par[cur][1] = i.f;
        }
    }
    for(auto && i : v[cur]){
        ll tmp = (i.f == par[cur][0] ? dst[cur][1] : dst[cur][0]);
        tmp+=i.s;
        if(tmp>dst[i.f][0]) shft(i.f, tmp, cur);
        else if(tmp>dst[i.f][1]){
            dst[i.f][1] = tmp; par[i.f][1] = cur;
        }
    }
    if(par[cur][0]!=p) return dst[cur][0];
    return dst[cur][1];
}
int main()
{
    cin>>N>>Q; ms(dst, -1); ms(par, -1);
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b>>w; v[a].pb({b, w}); v[b].pb({a, w});
    }
    for(int i = 1; i <= N; ++i){
        dfs(1, -1);
        cout<<dst[1][0]<<" "<<par[1][0]<<endl;
    }
    while(Q--){
        cin>>a;
        cout<<dfs(a, -1)<<endl;
    }
    return 0;
}
