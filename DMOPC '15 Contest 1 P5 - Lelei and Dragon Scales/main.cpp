#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef int ll;
const ll MAXN = 251;
using namespace std;
ll pfsum[MAXN][MAXN];


ll rettot(int toplx, int toply, int w, int h){
    return pfsum[toplx+w-1][toply+h-1]-pfsum[toplx-1][toply+h-1]-pfsum[toplx+w-1][toply-1]+pfsum[toplx-1][toply-1];
}

int main()
{
    ll W,H, A, res1 = 0; scan(W); scan(H); scan(A);
    ms(pfsum,0);
    for(int r = 1; r <= H; ++r){
        for(int c = 1; c <= W; ++c){
            scan(pfsum[c][r]);
            pfsum[c][r]+=pfsum[c-1][r]+pfsum[c][r-1]-pfsum[c-1][r-1];
        }
    }

    for(int w = 1; w <= min(W,A); ++w){
        ll h = min(H,A/w);
        for(int toply = 1; toply<=H-h+1; ++toply){
            for(int toplx = 1; toplx <=W-w+1; ++toplx){
                res1 = max(res1, rettot(toplx,toply,w,h));
            }
        }
    }
    cout<<res1<<endl;
    return 0;
}
