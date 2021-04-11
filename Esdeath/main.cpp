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
const ll MM = 5e3+20;
using namespace std;
vector <int>v[MM]; vector<pair<int, int> > leafs;
int par[MM];
bool blocked[MM];
// idea : binary search for the gap distance in which optimal soldiers used = s;
// then start from the leafs of tree, every gap length in nodes place soldier, (totally didn't peak dmoj help)
void getdpth(int cur, int depth){
    leafs.pb({depth, cur});
    for(auto && i : v[cur]){
        if(i==par[cur]) continue;
        par[i] = cur;
        getdpth(i, depth+1);
    }
}

void blok(int cur, int par, int len){
    blocked[cur] = 1;
    if(!len) return;
    for(auto && i : v[cur]){
        if(i==par)continue;
        blok(i, cur, len - 1);
    }
}

int getnxt(int cur, int len){
    int res = cur;
    for(int i = 0; i < len; ++i){
        res = par[res];
    }
    return res;
}

int place(int len){
    int soldiers =  0;
    for(auto && i : leafs){
        if(blocked[i.s]) continue;
        int node =  getnxt(i.s, len);
        blok(node, -1, len);
        ++soldiers;
    }
    return soldiers;
}


int main()
{
    int N, S; scan(N); scan(S); par[1] = 1;
    for(int i = 0; i < N-1; ++i){
        int a,b; scan(a); scan(b);
        v[a].pb(b); v[b].pb(a);
    }
    getdpth(1, 1);
    sort(leafs.begin(),  leafs.end(), greater<pair<int, int> >());
    int lo = 0, hi = N, mid, ret;
    while(hi >= lo){
        ms(blocked, 0);
        mid = (lo+hi)>>1;
        if(place(mid)<=S){
            hi  = mid-1;
            ret = mid;
        }
        else lo = mid+1;
    }
    printf("%d\n", ret);
    return 0;
}
