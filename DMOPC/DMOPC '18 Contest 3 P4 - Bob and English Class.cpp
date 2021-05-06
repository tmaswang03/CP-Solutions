#include<bits/stdc++.h>
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
ll sz[MM], dst[MM], a[MM], N, K, x, y, w, res; vector<pii> v[MM];
int getsz(int cur, int par){
    sz[cur] = a[cur];
    for(auto && i : v[cur]){
        if(i.f==par) continue;
        sz[cur]+=getsz(i.f, cur);
    }
    return sz[cur];
}
int getcnt(int cur, int par, int tot){
    for(auto && i : v[cur]){
        if(i.f==par) continue;
        if(sz[i.f]*2>tot) return getcnt(i.f, cur, tot);
    }
    return cur;
}
ll dfs(int cur, int par, int dpth){
    ll res = dpth*a[cur];
    for(auto && i : v[cur]){
        if(i.f==par) continue;
        res+=dfs(i.f, cur, dpth+i.s);
    }
    return res;
}
int main()
{
    cin>>K>>N;
    for(int i = 1; i <= K; ++i){
        cin>>x; ++a[x];
    }
    for(int i = 0; i < N-1; ++i){
        cin>>x>>y>>w;
        v[x].pb({y, w}); v[y].pb({x, w});
    }
    getsz(1, -1);
    int cent =  getcnt(1, -1, sz[1]);
    cout<<dfs(cent, -1, 0)<<endl;
}