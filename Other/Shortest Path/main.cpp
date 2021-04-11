#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define pii pair<int, int>
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e3+10;
using namespace std;
vector<pii>v[MM];
int N, M, a,b,c, dst[MM];
priority_queue<pii, vector<pii>, greater<pii> >pq;
int main()
{
    cin>>N>>M; ms(dst, 0x3f3f3f3f); dst[1] = 0;
    for(int i = 0; i < M; ++i){
        cin>>a>>b>>c; v[a].pb({b,c});
    }
    pq.push({0, 1});
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(c.f>dst[c.s]) continue;
        for(auto && i : v[c.s]){
            if(dst[c.s]+i.s<dst[i.f]){
                dst[i.f] = dst[c.s]+i.s;
                pq.push({dst[i.f], i.f});
            }
        }
    }
    cout<<dst[N]<<endl;
    return 0;
}
