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
const ll MM = 1e5+10;
using namespace std;
ll N, M, K, sto, u,x,w, dstn[11][11], dst[MM], dstsrc[11], mindst = 1e12; // dst[10] = from home
vector<ll>st;
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >pq;
vector<pair<ll, ll> >v[MM];
int main()
{
    scan(N); scan(M);
    for(int i = 0; i < M; ++i){
        scan(u); scan(x); scan(w);
        v[u].pb({x,w}); v[x].pb({u,w});
    }
    scan(K);
    for(int i = 0; i < K; ++i){
        scan(sto); st.pb(sto);
    }
    sort(st.begin(), st.end());
    ms(dst, 0x3f3f3f3f);
    int src = 0; dst[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur.f > dst[cur.s]) continue;
        for(auto && i : v[cur.s]){
            if(dst[i.f]>dst[cur.s]+i.s){
                dst[i.f] = dst[cur.s] + i.s;
                pq.push({dst[i.f], i.f});
            }
        }
    }
    for(int j = 0; j < st.size(); ++j) dstsrc[j] = dst[st[j]];
    for(int i = 0; i < st.size(); ++i){
        ms(dst, 0x3f3f3f3f);
        int src = st[i]; dst[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(cur.f > dst[cur.s]) continue;
            for(auto && i : v[cur.s]){
                if(dst[i.f]>dst[cur.s]+i.s){
                    dst[i.f] = dst[cur.s] + i.s;
                    pq.push({dst[i.f], i.f});
                }
            }
        }
        for(int j = 0; j < st.size(); ++j) dstn[i][j] = dst[st[j]];
    }
    for(int i = 0; i < st.size(); ++i) st[i] = i;
    do{
        ll res = 0;
        for(int i = 0; i < st.size()-1; ++i){
            res+=dstn[st[i]][st[i+1]];
        }
        res+=dstsrc[st[0]]+dstsrc[st[K-1]];
        mindst = min(res, mindst);
    }while(next_permutation(st.begin(), st.end()));
    cout<<mindst<<endl;
    return 0;
}
