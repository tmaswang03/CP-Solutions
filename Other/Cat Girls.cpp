#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;

using namespace std;

ll pfsum[500000], pfsum1[500000];

ll getpfsum(int l, int r){
    return pfsum[r]-pfsum[l-1];
}

ll getpfsum1(int l, int r){
    return pfsum1[r]-pfsum1[l-1];
}

int main()
{
    ll n, w; scan(n); scan(w);
    ll dp[500000], cur = 0;
    ll pointer[500000]; pointer[0]=0;
    pfsum1[0]=pfsum[0]=dp[0]=0;
    for(int i = 0; i < n; ++i){
        ll p1 = 0;
        char a; cin>>a;
        if(a=='A'){
            ++cur;
            ll p,c; scan(p); scan(c);
            pfsum[cur]=pfsum[cur-1]+p;
            pfsum1[cur]=pfsum1[cur-1]+c;
            p1 = pointer[cur-1];
            while(getpfsum(p1,cur)>w){
                ++p1;
            }
            dp[cur]=max(dp[cur-1],getpfsum1(p1,cur));
            printf("%lld\n",dp[cur]);
        }
        else{
            dp[cur]=0;
            pfsum[cur]=0;
            --cur;
        }
    }
    return 0;
}
