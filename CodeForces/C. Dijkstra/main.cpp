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
using namespace std;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10, inf = 0x3f3f3f3f3f;
typedef pair<ll, ll> pll;

vector<pll> v[MM]; priority_queue<pll, vector<pll>, greater<pll> >pq; vector<int> out;
ll dist[MM], par[MM], N, M, a, b, w;
int main()
{
    ms(dist, inf); dist[1] = 0;
    cin>>N>>M;
    for(int i = 0; i < M; ++i){
        cin>>a>>b>>w;
        v[a].pb({b, w}); v[b].pb({a, w});
    }
    pq.push({0, 1});
    while(!pq.empty()){
        pll c = pq.top(); pq.pop();
        if(dist[c.s]<c.f) continue;
        for(auto && i : v[c.s]){
            if(dist[i.f] > dist[c.s]+i.s){
                par[i.f] = c.s; dist[i.f] = dist[c.s]+i.s;
                pq.push({dist[i.f], i.f});
            }
        }
    }
    if(dist[N]>=inf) cout<<-1<<endl;
    else{
        for(int cur = N; cur!=1; cur = par[cur]) out.pb(cur);
        out.pb(1);
        for(int i = out.size()-1; i >= 0; --i) cout<<out[i]<<" ";
    }
    return 0;
}
