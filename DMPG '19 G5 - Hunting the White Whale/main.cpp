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
const ll MM = 2e5+10;
using namespace std;
struct edge{
    int nd, t;
};
ll sz[MM];
bool blocked[MM];
vector<edge>v[MM];

int main()
{
    int N, K; scan(N); scan(K);
    for(int i = 0; i < N-1; ++i){
        int a,b,t; scan(a); scan(b); scan(t);
        v[a].pb({b,t}); v[b].pb({a,t});
    }
    return 0;
}
