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
const ll MM = 2e3+10;
using namespace std;
struct edge{int d, l;};
int T, N, M, G, fdb, res, dst[MM];
vector<edge>v[MM];
queue<int>food;
int main()
{
    scana(T,N,M,G); ms(dst, 0x3f3f3f3f);
    for(int i = 0; i < G; ++i){
        scan(fdb); food.push(fdb);
    }
    for(int i = 0; i < M; ++i){
        int o,d,l; scana(o,d,l);
        v[o].pb({d,l});
    }
    dst[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(c.s > dst[c.f]) continue;
        for(auto && i : v[c.f]){
            if(dst[i.d] > dst[c.f] + i.l){
                dst[i.d] = dst[c.f] + i.l;
                pq.push({i.d, dst[i.d]});
            }
        }
    }
    while(!food.empty()){
        auto c = food.front(); food.pop();
        if(dst[c] <= T) ++res;
    }
    printf("%d\n", res);
    return 0;
}
