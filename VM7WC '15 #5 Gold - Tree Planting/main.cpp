#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
const ll MM = 2e3+10, mod = 1e9+7;
using namespace std;
ll bit[MM][MM], N, opt, x, y, v, res = 0;
// keep a bunch of 1d bits of diagonals (:
// to get the right bit notice that all r+c in the diagonals will be equal lol

void upd(int d, int x, int v){
    for(; x <= MM-10; x+=x&-x) bit[d][x]+=v;
}

int query(int d, int x){
    int res = 0;
    for(; x >0; x-=x&-x) res+=bit[d][x];
    return res;
}
int main()
{
    cin>>N;
    while(N--){
        cin>>opt>>x>>y>>v;
        if(opt==1){
            upd(x+y, x, v);
        }
        else{
            res+=query(x+y, x) - query(x+y, x-v-1); res%=mod;
        }
    }
    cout<<res<<endl;
    return 0;
}
