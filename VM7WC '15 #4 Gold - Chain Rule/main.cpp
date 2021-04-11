#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10, inf = 0x3f3f3f3f;
using namespace std;
struct edge{int d, l;};
int T, N, M, G, fdb, res, dst[MM], dst1[MM];
vector<edge>v[MM];
queue<int>food;
int main()
{
    scana(N,M); ms(dst, inf); ms(dst1, inf)
    for(int i = 0; i < M; ++i){
        int o,d,l; scana(o,d,l);
        v[o].pb({d,l});
        v[d].pb({o,l});
    }
    dst[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(c.f > dst[c.s]) continue;
        for(auto && i : v[c.s]){
            if(dst[i.d] > dst[c.s] + i.l){
                dst[i.d] = dst[c.s] + i.l;
                pq.push({dst[i.d], i.d});
            }
        }
    }
    dst1[N-1] = 0;
    pq.push({0,N-1});
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(c.f > dst1[c.s]) continue;
        for(auto && i : v[c.s]){
            if(dst1[i.d] > dst1[c.s] + i.l){
                dst1[i.d] = dst1[c.s] + i.l;
                pq.push({dst1[i.d], i.d});
            }
        }
    }
    for(int i = 0; i < N; ++i){
        res = max(res, dst[i]+dst1[i]);
    }
    printf("%d\n", res);
    return 0;
}
