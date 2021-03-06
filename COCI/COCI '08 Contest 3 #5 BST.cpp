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
const ll MM = 3e5+10;
using namespace std;
map<ll, ll> mep; ll N, C = 0, cur;
// idea : keep sorted array of all inserted values, since not balanced
// notice change in c = depth of node after insertion
// consider node a, b the 2 closest values to the left and right in the depth if a>b
// 2 options : a is child of b
// or there is a node x: a<x<b who is the lca of both <- not possible (cuz lower_bound returned a and b)
// always go for the deeper depth;
// one of 2 must be leaf (otherwise there exists a leaf node which a<x<b
// since these 2 are the closest they follow the insertion path for the next element
// the result will be the depth of the closest greater node + 1 (insert to left of the greater)
// or the closest smaller node + 1 (insert to right of the least)
int main()
{
    scan(N);
    for(int i = 0; i < N; ++i){
        scan(cur);
        auto pt = mep.lower_bound(cur); ll d = 1;
        if(pt!=mep.end()) d = pt->s+1;
        if(pt!=mep.begin()){
            --pt;
            d = max(d, pt->s+1);
        }
        mep[cur] = d;
        C+=d-1;
        printf("%lld\n", C);
    }
    return 0;
}
