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
const ll MM = 1e5+10;
using namespace std;
ll N, M, Q, a, b, l, pre[MM], cost[MM], dia, idx; vector<pii> v[MM]; bool vis[MM];
void dfs1(int cur, int par, ll dist){
    vis[cur] = 1;
    if(dist > dia){
        dia = dist; idx = cur;
    }
    for(auto && i : v[cur]){
        if(i.f==par) continue;
        pre[i.f] = cur; cost[i.f] = i.s;
        dfs1(i.f, cur, dist+i.s);
    }
}
ll getdia(int cur){
    dia = 0, idx = cur;
    dfs1(idx, -1, 0);
    dfs1(idx, -1, 0);
    return dia;
}
ll getra(int cur){
    dia = 0, idx = cur;
    ll tidx = cur, ra = LLONG_MAX;
    dfs1(idx, -1, 0); tidx = idx; dia = 0;
    dfs1(idx, -1, 0);
    for(ll x = 0; idx != tidx; idx = pre[idx]){
        ra = min(ra, max(x, dia - x));
        x += cost[idx];
    }
    return ra == LLONG_MAX ? 0 : ra;
}
int main()
{
    // for maximum height attach all the nodes left to the diameter
    // min height attach to the root of the center of diameter radius thingy
    cin>>N>>M>>Q;
    for(int i = 0; i < M; ++i){
        cin>>a>>b>>l;
        v[a].pb({b, l}); v[b].pb({a, l});
    }
    if(Q==1){
        ll tot = 0;
        for(int i = 1; i <= N; ++i){
            if(!vis[i]) tot += 1+getdia(i);
        }
        cout<<tot-1<<endl;
    }
    else{
        vector<ll> radi;
        for(int i = 1; i <= N; ++i){
            if(!vis[i]){
                radi.pb(getra(i));
            }
        }
        sort(radi.begin(), radi.end(), greater<ll>());
        if(radi.size()>=2) cout<<max(radi[0], radi[1]+1)<<endl;
        else cout<<radi[0]<<endl;
    }
    return 0;
}