#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM =1e5+10, inf = 1e6+10;
using namespace std;
ll res = 0, n, len, ma[MM], mi[MM], tma, tmi, cur, cnt = 0, bit[inf];
bool valid[MM], yes = 0;

void upd(int cur){
    for(; cur <= inf-5; cur+=cur&-cur) ++bit[cur];
}
ll que(int cur){
    ll res = 0;
    for(; cur > 0; cur-=cur&-cur) res+=bit[cur];
    return res;
}

int main()
{
    scan(n); ms(valid, 0);
    for(int i = 0; i < n; ++i){
        tma = 0; tmi = inf;
        scan(len);
        for(int j = 0; j < len; ++j){
            scan(cur); ++cur;
            if(tmi < cur) valid[i] = 1;
            tma = max(tma, cur); tmi = min(tmi, cur);
        }
        ma[i] = tma; mi[i] = tmi;
        if(valid[i]) upd(1);
        if(!valid[i]) upd(tmi);
    }
    for(int i = 0; i < n; ++i){
        if(valid[i]){res+=n; continue;}
        res+=que(ma[i]-1);
    }
    cout<<res<<endl;
    return 0;
}
