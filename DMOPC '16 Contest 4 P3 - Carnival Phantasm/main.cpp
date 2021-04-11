#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
const ll MM = 1e5+10, MA = 1e2;
using namespace std;
ll N, S, Q, d[MM], res;
bool ye[MM][MA+10];
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq[110];
int main()
{
    scan(N); scan(S);
    for(int i = 1; i <= N; ++i){
        scan(d[i]);
    }
    for(int i = 0; i < S; ++i){
        ll s, a; scan(s); scan(a);
        ye[s][a] = 1; pq[a].push({d[s], s});
    }
    scan(Q);
    for(int i = 0; i < Q; ++i){
        char opt; cin>>opt;
        ll x, k;
        if(opt=='A'){
            scan(x); scan(k);
            pq[k].push({d[x], x});
            ye[x][k] = 1;
        }
        else if(opt == 'S'){
            scan(x); scan(k);
            ye[x][k] = 0;
        }
        else if(opt == 'E'){
            scan(x); scan(k);
            d[x] = k; fill(ye[x], ye[x]+MA, 0);
        }
        else{
            scan(k);
            while(!pq[k].empty() && (!ye[pq[k].top().s][k] || d[pq[k].top().s] != pq[k].top().f)) pq[k].pop();
            if(pq[k].empty()) printf("-1\n");
            else printf("%lld\n", pq[k].top().s);
        }
    }
    return 0;
}
