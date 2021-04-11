#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e3+25;
using namespace std;
int bit[MM][MM], S, opt;
void upd(int x, int y, int val){
    for(int x1=x; x1 <= S+1; x1+=(x1&-x1)){
        for(int y1=y; y1<= S+1; y1+=(y1&-y1)){
            bit[x1][y1]+=val;
        }
    }
}
ll query(int x, int y){
    ll res = 0;
    for(int x1=x; x1 > 0; x1-=(x1&-x1)){
        for(int y1=y; y1> 0; y1-=(y1&-y1)){
            res+=bit[x1][y1];
        }
    }
    return res;
}

ll queryrec(int l, int b, int r, int t){
    return query(r, t) + query(l-1, b-1) - query(r, b-1) - query(l-1, t);
}

int main()
{
    ms(bit, 0);
    for(;;){
        scan(opt);
        if(!opt) cin>>S;
        else if(opt==1){
            int x,y,a; scanf("%d%d%d", &x, &y, &a);
            ++x; ++y;
            upd(x, y, a);
        }
        else if(opt == 2){
            int l,b,r,t; scanf("%d%d%d%d", &l, &b, &r, &t);
            ++l; ++b; ++r; ++t;
            printf("%lld\n", queryrec(l,b,r,t));
        }
        else return 0;
    }
    return 0;
}
