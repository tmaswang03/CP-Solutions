#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 710, inf = 0x3f3f3f3f, mod = 1e6;
using namespace std;
// idea, 2 bfs, one to to  grandma one back
// each  node keep number of ways to get their
//       if dist==mindist[node] ++ways
// number of ways is just the sum sum of ways for minimum distants (ways to node * ways out of node);
// don't doublecount paths that contain 2 cookies
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >pq;
ll N, M, to[MM], from[MM], wayto[MM], wayfrom[MM], res = 0, mindst = 1e9, gae[MM][MM];
vector<pair<ll, ll> >v[MM];
vector<ll> cookie;
int main()
{
    scan(N); ms(to, inf); ms(from, inf);  ms(gae, 0); ms(wayto, 0); ms(wayfrom, 0);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            int dst; scan(dst);
            if(i^j){
                v[i].pb({j, dst});
            }
        }
    }
    scan(M);
    for(int i = 0; i < M; ++i){
        int store; scan(store);
        cookie.pb(store);
    }
    to[1] = 0; wayto[1] = 1;
    pq.push({0, 1});
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(c.f>to[c.s]) continue;
        for(auto && i : v[c.s]){
            if(to[i.f]>to[c.s]+i.s){
                fill(gae[i.f], gae[i.f]+N+1, 0);
                to[i.f] = to[c.s]+i.s;
                wayto[i.f] = wayto[c.s];
                gae[i.f][c.s] = wayto[c.s];
                pq.push({to[i.f], i.f});
            }
            else if(to[i.f]==to[c.s]+i.s){
                wayto[i.f]+=wayto[c.s] - gae[i.f][c.s];
                gae[i.f][c.s] = wayto[c.s];
                wayto[i.f]%=mod;
            }
        }
    }
    ms(gae, 0);
    from[N] = 0; wayfrom[N] = 1;
    pq.push({0, N});
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(c.f>from[c.s]) continue;
        for(auto && i : v[c.s]){
            if(from[i.f]>from[c.s]+i.s){
                fill(gae[i.f], gae[i.f]+N+1, 0);
                from[i.f] = from[c.s]+i.s;
                wayfrom[i.f] = wayfrom[c.s];
                gae[i.f][c.s] = wayfrom[c.s];
                pq.push({from[i.f], i.f});
            }
            else if(from[i.f]==from[c.s]+i.s){
                wayfrom[i.f]+=wayfrom[c.s]-gae[i.f][c.s];
                gae[i.f][c.s] = wayfrom[c.s];
                wayfrom[i.f]%=mod;
            }
        }
    }
    for(auto && i : cookie){
        if(from[i]+to[i]<mindst){
            res = wayto[i]*wayfrom[i];
            res%=mod;
            mindst = from[i]+to[i];
        }
        else if(from[i]+to[i]==mindst){
            res+=wayto[i]*wayfrom[i];
            res%=mod;
        }
    }
    printf("%lld %lld\n", mindst, res);
/*
2
0 1
1 0
2
1 2
*/
    return 0;
}
