#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+1;
using namespace std;
ll N, sz[MM], res = 0;
bool blocked[MM];
map<ll, ll> mp1;
stack<ll> s, s1;
struct edge{
    ll nd, col; //red = -1; blue = 1;
};
vector<edge> v[MM];

ll getsz(ll cur, ll par){
    sz[cur] = 1;
    for(auto && i : v[cur]){
        if(i.nd == par || blocked[i.nd]) continue;
        sz[cur]+=getsz(i.nd, cur);
    }
    return sz[cur];
}

ll getcnt(ll cur, ll par, ll sze){
    for(auto && i : v[cur]){
        if(i.nd == par || blocked[i.nd]) continue;
        if(sz[i.nd]>sze/2) return getcnt(i.nd, cur, sze);
    }
    return cur;
}

void dfs(ll cur, ll par, ll dist){
    s.push(dist); s1.push(dist);
    // dist + n = 1;
    //  = 1- dist
    // ddist + n = -1
    // n = -1-dist
    res+= mp1[1-dist] + mp1[-dist-1];
    for(auto && i : v[cur]){
        if(blocked[i.nd] || i.nd == par ) continue;
        dfs(i.nd, cur, dist + i.col);
    }
}

void solve(ll cur, ll par){
    ll siz = getsz(cur, par);
    ll cnt = getcnt(cur, par, siz);
    mp1[0] = 1;
    blocked[cnt] = 1;
    for(auto && i : v[cnt]){
        if(blocked[i.nd] || i.nd == par) continue;
        dfs(i.nd, cnt, i.col);
        while(!s.empty()){
            ++mp1[s.top()]; s.pop();
        }
    }
    while(!s1.empty()){
        mp1[s1.top()]=0; s1.pop();
    }
    for(auto && i : v[cnt]){
        if(!blocked[i.nd]) solve(i.nd, cnt);
    }
}


int main()
{
    boost();
    cin>>N;
    for(int i = 0; i < N-1; ++i){
        ll o, n, col = -1; cin>>o>>n;
        char c; cin>>c;
        if(c=='r') col = 1;
        v[o].pb({n, col});
        v[n].pb({o, col});
    }
    solve(1, -1);
    cout<<res-N+1<<endl;
    return 0;
}
