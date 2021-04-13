#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MAXN = 1550;
const ll MAXM = 5e3+10;
const ll INF = 0x3f3f3f;
const ll MOD = 1e9+7;
using namespace std;
struct edge{
    ll O, D, L, ind;
};
vector<edge> v[MAXN];
ll res[MAXM], dist[MAXN], pt[MAXN], pf[MAXN], dp[MAXN];
vector<edge> lastedge[MAXN];
int main()
{
    int N, M; scan(N); scan(M);
    for(int i = 0; i < M; ++i){
        ll O,D, L; scan(O); scan(D); scan(L);
        v[O].pb({O,D,L,i});
    }
    for(int i = 1; i <= N; ++i){
        priority_queue<pair<ll, ll>, vector<pair< ll, ll> >, greater<pair<ll, ll> > >pq;
        deque<ll>dq;
        ms(dist, INF); ms(pf, 0); ms(pt, 0); dist[i] = 0; pt[i] = 1;
        pq.push({0,i}); //dist, src
        while(!pq.empty()){
            pair<ll, ll> temp = pq.top();
            pq.pop();
            if(temp.f > dist[temp.s]) continue;
            dq.pb(temp.s);
            for(auto && it : v[temp.s]){
                if(it.L+dist[temp.s] < dist[it.D]){
                    pt[it.D] = pt[temp.s];
                    dist[it.D] = dist[temp.s]+it.L;
                    pq.push({dist[it.D], it.D});
                }
                else if(it.L+dist[temp.s] == dist[it.D]){
                    pt[it.D] += pt[temp.s]; pt[it.D]%=MOD;
                }

            }
        }
        while(!dq.empty()){
            ll temp = dq.back(); dq.pop_back(); pf[temp] = 1;
            for(auto && it : v[temp]){
                if(dist[it.D]>=dist[temp]+it.L){
                    pf[temp]+=pf[it.D];
                    pf[temp]%=MOD;
                    res[it.ind] += pt[temp]*pf[it.D];
                    res[it.ind]%=MOD;
                }
            }
        }
    }
    for(int i = 0; i < M; ++i){
        cout<<res[i]<<endl;
    }
/*
4 4
1 2 1
2 3 1
1 3 2
3 4 1
*/
    return 0;
}
