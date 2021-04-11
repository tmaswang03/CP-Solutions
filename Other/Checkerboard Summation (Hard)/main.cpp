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
const ll  MM = 3e3+10;
using namespace std;
// 1 = bit0, 0 = bit1
ll M, N, opt, r, c, r1, c1, x, bit[MM][MM][2], a[MM][MM], val;
bool getcol(int r, int c){ return (r%2==c%2);}
void upd(int x, int y, int val, int col){
    for(int x1 = x; x1 <= M; x1+=x1&-x1){
        for(int y1 = y; y1 <= N; y1+=y1&-y1){
            bit[x1][y1][col]+=val;
        }
    }
}
ll query (int x, int y, int col){
    ll res = 0;
    for(int x1 = x; x1 > 0; x1-=x1&-x1){
        for(int y1 = y; y1 > 0; y1-=y1&-y1){
            res+=bit[x1][y1][col];
        }
    }
    return res;
}
ll queryrec(int x1, int x2, int y1, int y2, int col){
    return query(x2, y2, col) - query(x2, y1-1, col) - query(x1-1, y2, col) + query(x1-1, y1-1, col);
}

int main()
{
    boost();
    cin>>M>>N;
    for(;;){
        cin>>opt;
        if(opt==0) break;
        if(opt==1){
            cin>>r>>c>>x;
            val = x - a[r][c]; a[r][c] = x;
            upd(r, c, val, getcol(r, c));
        }
        else if(opt==2){
            cin>>r>>c>>r1>>c1;
            cout<<queryrec(r, r1, c, c1, getcol(r, c)) - queryrec(r, r1, c, c1, !getcol(r, c))<<endl;
        }
    }
    return 0;
}
