#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 3e5+10;
using namespace std;
int t, n, sz[MM];
vector<int> v[MM], cnt;
int getsz(int cur, int par){
    sz[cur] = 1;
    for(auto && i : v[cur]){
        if(i==par) continue;
        sz[cur]+=getsz(i, cur);
    }
    return sz[cur];
}

int getcnt(int cur, int par, int sze){
    for(auto && i : v[cur]){
        if(i==par) continue;
        if(sz[i]>sze/2) return getcnt(i, cur, sze);
    }
    return cur;
}

void solve(int n){
    getsz(1, 0);
    int cent1 = getcnt(1, 0, n);
    cout<<cent1<<"<-\n";
}
int main()
{
    scan(t);
    while(t--){
        scan(n);
        for(int i = 1; i <= n; ++i) v[i].clear();
        for(int i = 0; i < n-1; ++i){
            int a,b; scan(a); scan(b); v[a].pb(b); v[b].pb(a);
        }
        solve(n);
    }
    return 0;
}
